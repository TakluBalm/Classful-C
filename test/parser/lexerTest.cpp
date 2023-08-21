#include <gtest/gtest.h>

extern "C" {
	#include <lexer.h>
}

FILE* file = NULL;
char filename[] = "lexerTest.txt";

void setup(const char* content){
	file = fopen(filename, "w+");
	fprintf(file, "%s", content);
	fflush(file);
	fseek(file, 0, SEEK_SET);
	Lexer_init(file);
}

void teardown(){
	fclose(file);
	remove(filename);
	file = NULL;
}

TEST(lexer, brackets_test){
	setup("({[]})");

	enum token_type types[] = {OPAREN, OBRACE, OBRACKET, CBRACKET, CBRACE, CPAREN};
	struct token t = Lexer_next();
	int i = 0;
	ASSERT_NE(t.type, END);
	while(t.type != END){
		ASSERT_EQ(t.category, BRACKET);
		ASSERT_EQ(t.type, types[i]);
		t = Lexer_next();
		i++;
	}

	teardown();
}

TEST(lexer, operators_test){
	setup("+ - < > & | * / = ! += -= <= >= &= |= *= /= == != ++ -- << >> && || .");

	struct token t = Lexer_next();
	int i = 0;
	ASSERT_NE(t.type, END);
	while(t.type != END){
		ASSERT_EQ(t.category, OPERATOR);
		ASSERT_EQ(t.type, ADD+i);
		t = Lexer_next();
		i++;
	}

	teardown();
}

TEST(lexer, constants_test){
	setup("'c' '\n' '\033' \"Hello!\" \"Hello World!\n\" 34");

	enum token_type types[] = {
		CHARACTER,	//	'c'
		CHARACTER,	//	'\n'
		CHARACTER,	//	'\033'
		STRING,		//	"Hello!"
		STRING,		//	"Hello World!\n"
		NUMERIC		//	34
	};
	const char* const tokens[] = {"c", "\n", "\033", "Hello!", "Hello World!\n", "34"};
	struct token t = Lexer_next();
	int i = 0;
	ASSERT_NE(t.type, END);
	while(t.type != END){
		ASSERT_EQ(t.category, CONSTANT);
		ASSERT_EQ(t.type, types[i]);
		ASSERT_STREQ(token_val, tokens[i]);
		t = Lexer_next();
		i++;
	}

	teardown();
}
