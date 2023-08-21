#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>


enum token_type {
	//	Brackets
	OPAREN,
	CPAREN,
	OBRACE,
	CBRACE,
	OBRACKET,
	CBRACKET,

	//	Operators
	ADD,
	SUB,
	LT,
	GT,
	AND,
	OR,
	MUL,
	DIV,
	EQ,
	NOT,
	ADDEQ,
	SUBEQ,
	LTE,
	GTE,
	ANDEQ,
	OREQ,
	MULEQ,
	DIVEQ,
	DEQ,
	NEQ,
	INCR,
	DECR,
	LSHIFT,
	RSHIFT,
	L_AND,
	L_OR,
	DOT,

	//	Keywords
	BREAK,
	CASE,
	CLASS,
	CONTINUE,
	ELSE,
	EXTENDS,
	FALSE,
	FOR,
	IF,
	LOCAL,
	NEW,
	REF,
	RETURN,
	STATIC,
	SWITCH,
	TRUE,
	WHILE,

	//	Constants
	CHARACTER,
	STRING,
	NUMERIC,

	//	Special
	END,
	ID,
	STMT_END,
	COMMA,

	//	Error
	UNIDENTIFIED
};

enum token_category {
	KEYWORD,
	OPERATOR,
	BRACKET,
	CONSTANT,
	SPECIAL,
	ERROR
};

struct token {
	enum token_category category;
	enum token_type type;
};

extern char* token_val;

void Lexer_init(FILE* file);
struct token Lexer_next();

#endif