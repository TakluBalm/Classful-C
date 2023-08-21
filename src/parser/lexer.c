#include <lexer.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define FIRST_KEYWORD BREAK

FILE* inputFile = NULL;
char current;

//	Keywords in lexicographical order
char* keywords[] = {"break", "case", "class", "continue", "else", "extends", "false", "for", "if", "local", "new", "ref", "return", "static", "switch", "true", "while"};

#define BUF_UNIT 32
long buffer_index = -1;
long buffer_size;
char* token_val;

void Lexer_init(FILE* file){
	inputFile = file;
	current = fgetc(inputFile);
}

static void update(){
	current = fgetc(inputFile);
}

static void skipWhiteSpace(){
	while(current == ' ' || current == '\t' || current == '\n'){
		update();
	}
}

static bool gotAlpha(){
	return (current <= 'z' && current >= 'a') || (current <= 'Z' && current >= 'A');
}

static bool gotNumber(){
	return (current >= '0' && current <= '9');
}

static void clearBuf(){
	if(token_val == NULL){
		return;
	}
	buffer_index = 0;
	token_val[buffer_index] = '\0';
}

static void appendToBuf(char c){
	if(token_val == NULL){
		token_val = malloc(BUF_UNIT);
		buffer_size = BUF_UNIT;
		buffer_index = 0;
	}
	if(buffer_index == buffer_size-1){
		buffer_size += BUF_UNIT;
		token_val = realloc(token_val, buffer_size);
	}
	token_val[buffer_index++] = c;
	token_val[buffer_index] = '\0';
}

static void parseId(){
	while(gotAlpha() || gotNumber() || current == '_'){
		appendToBuf(current);
		update();
	}
}

static void parseNum(){
	bool found  = false;
	while(gotNumber() || (current == '.' && !found && (found = true))){
		appendToBuf(current);
		update();
	}
}

static char interpreteEscape(){
	char c;
	if(gotNumber()){
		int len = 0;
		while(gotNumber() && len < 3){
			c += current - '0';
			c = c << 1;
			len++;
		}
	}else{
		switch(current){
			case 'a':
				c = '\a';
				break;
			case 'b':
				c = '\b';
				break;
			case 'e':
				c = '\e';
				break;
			case 'f':
				c = '\f';
				break;
			case 'n':
				c = '\n';
				break;
			case 'r':
				c = '\r';
				break;
			case 't':
				c = '\t';
				break;
			case 'v':
				c = '\v';
				break;
			default:
				c = current;
				break;
		}
		update();
	}
	return c;
}

static char getLiteral(){
	char c;
	if(current == '\\'){
		update();
		c = interpreteEscape();
	} else {
		c = current;
		update();
	}
	return c;
}

static void parseCharacterConstant(){
	char c = getLiteral();
	if(current == '\''){
		appendToBuf(c);
		update();
	}
}

static void parseString(){
	while(current != '"'){
		char c = getLiteral();
		appendToBuf(c);
	}
	update();
}

static int getKeyIndex(){
	if(token_val == NULL){
		return -1;
	}

	int prevMatch = 0;
	for(int i = 0; i < WHILE-BREAK+1; i++){
		int index = 0;
		while(token_val[index] != '\0' && keywords[i][index] != '\0' && keywords[i][index] == token_val[index]){
			index++;
		}
		if(token_val[index] == '\0' && keywords[i][index]== '\0'){
			return i;
		}
		if(prevMatch > index){
			return -1;
		}
		prevMatch = index;
	}
	return -1;
}

static bool gotOperator(){
	switch(current){
		case '+':
		case '-':
		case '<':
		case '>':
		case '&':
		case '|':
		case '=':
		case '*':
		case '/':
		case '.':
		case '!':
			return true;
		default:
			return false;
	}
}

static enum token_type operatorBaseType(char c){
	switch (c){
	case '+':
		return ADD;
	case '-':
		return SUB;
	case '*':
		return MUL;
	case '/':
		return DIV;
	case '=':
		return EQ;
	case '>':
		return GT;
	case '<':
		return LT;
	case '&':
		return AND;
	case '|':
		return OR;
	case '.':
		return DOT;
	case '!':
		return NOT;
	}
}

static enum token_type parseOperator(){
	enum token_type first = operatorBaseType(current);
	appendToBuf(current);
	update();
	if(first < FIRST_KEYWORD && !gotOperator()){
		return first;
	}
	enum token_type second = operatorBaseType(current);
	if(second == EQ){
		appendToBuf(current);
		update();
		return first + (ADDEQ-ADD);
	}
	if(first == second && first <= OR && first >= ADD){
		appendToBuf(current);
		update();
		return first-ADD + INCR;
	}
	return first;
}

static bool gotBracket(){
	switch (current) {
	case '[':
	case ']':
	case '{':
	case '}':
	case '(':
	case ')':
		return true;
	
	default:
		return false;
	}
}

static enum token_type parseBracket(){
	appendToBuf(current);
	switch (current)
	{
	case '[':
		update();
		return OBRACKET;
	case ']':
		update();
		return CBRACKET;
	case '{':
		update();
		return OBRACE;
	case '}':
		update();
		return CBRACE;
	case '(':
		update();
		return OPAREN;
	case ')':
		update();
		return CPAREN;
	default:
		break;
	}
}

struct token Lexer_next(){
	skipWhiteSpace();
	clearBuf();
	struct token t;
	switch (current) {
	case '\'':
		update();
		parseCharacterConstant();
		t.category = CONSTANT;
		t.type = CHARACTER;
		return t;

	case '\"':
		update();
		parseString();
		t.category = CONSTANT;
		t.type = STRING;
		return t;

	case EOF:
		t.category = SPECIAL;
		t.type = END;
		return t;

	case ';':
		do{
			appendToBuf(current);
			update();
			skipWhiteSpace();
		} while(current == ';');
		t.category = SPECIAL;
		t.type = STMT_END;
		return t;
	
	case ',':
		t.category = SPECIAL;
		t.type = COMMA;
		appendToBuf(current);
		update();
		return t;

	default :
		if(gotAlpha()){
			parseId();
			int idx = getKeyIndex();
			if(idx == -1){
				t.category = SPECIAL;
				t.type = ID;
			} else {
				t.category = KEYWORD;
				t.type = FIRST_KEYWORD + idx;
			}
			return t;
		}
		if(gotNumber()){
			parseNum();
			t.type = NUMERIC;
			t.category = CONSTANT;
			return t;
		}
		if(gotOperator()){
			t.category = OPERATOR;
			t.type = parseOperator();
			return t;
		}
		if(gotBracket()){
			t.category = BRACKET;
			t.type = parseBracket();
			return t;
		}
	}
	t.category = ERROR;
	t.type = UNIDENTIFIED;
}