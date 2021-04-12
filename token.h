/***********************************************************
* Author: Philip Wright                                    *
* Project 1: Scanner                                       *
* token.h creates an enumeration for all the types of      *
* tokens allowed while also setting up the Token struct    * 
***********************************************************/
#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum tokens {
    BEGIN, END, LOOP, WHILE, VOID, EXIT, GETTER, OUTTER, MAIN, IF, THEN, ASSIGN, DATA, PROC, 
    EQUALS, EQUALS_LESS_THAN, EQUALS_GREATER_THAN, EQUALS_EQUALS, COLON, COLON_EQUALS, ADD, SUBTRACT, 
    ASTERISK, DIVIDE, MODULUS, PERIOD, LEFT_PARENT, RIGHT_PARENT, COMMA, LEFT_BRACE, RIGHT_BRACE, 
    SEMICOLON, LEFT_BRACKET, RIGHT_BRACKET, IDENTIFIER, INT, EOF_TOKEN, ERROR                  
};

struct Token {
    unsigned int lineNum;      // line number
    tokens token_ID;           // token ID
    std::string token_string;  // string of token

    
    // Assign token info
    Token(tokens ID, std::string string, unsigned int lineNum)
    {   
        this->lineNum = lineNum;
        this->token_ID = ID;
        this->token_string = string;
    }
};

#endif
