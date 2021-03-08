#ifndef TOKEN_H
#define TOKEN_H

#define MAX 9
#define LIMIT 200

typedef enum {
	IDENTIFIER,
	KEYWORD,
	NUMBER,	
	EQUAL,
	GREATER,
	LESS,
	COLON,
	PLUS,
	MINUS,
	ASTERIK,
	SLASH,
	PERCENT,
	DOT,
	L_PARENT,
	R_PARENT,
	COMMA,
	L_BRACE,
	R_BRACE,
	SEMICOLON,
	L_BRACKET,
	R_BRACKET,
	
	//keywords
	START_KEYWORD,
	STOP_KEYWORD,
	LOOP_KEYWORD,
	VOID_KEYWORD,
	VAR_KEYWORD,
	RETURN_KEYWORD,
	SCAN_KEYWORD,
	OUT_KEYWORD,
	PROGRAM_KEYWORD,
	IF_KEYWORD,
	THEN_KEYWORD,
	LET_KEYWORD,
	EOT // end of token
} TokenType;

typedef struct {
	TokenType tokenType;
	char instance[100];
	int lineNum;
} Token;

Token* tokens;

#endif
