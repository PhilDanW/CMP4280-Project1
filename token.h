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
    BEGIN_TK, END_TK, LOOP_TK, WHILE_TK, VOID_TK, EXIT_TK, GETTER_TK, OUTTER_TK,                // 7
    MAIN_TK, IF_TK, THEN_TK, ASSIGN_TK, DATA_TK, PROC_TK, EQUALS_TK, EQUALS_OR_LESS_THAN_TK,   // 15
    EQUALS_OR_GREAT_THAN_TK, EQUALS_EQUALS_TK, COLON_TK, COLON_EQUALS_TK, PLUS_TK, MINUS_TK, ASTERISK_TK,              // 22
    SLASH_TK, PERCENT_TK, PERIOD_TK, LEFT_PAREN_TK, RIGHT_PAREN_TK, COMMA_TK, LEFT_BRACE_TK,            // 29
    RIGHT_BRACE_TK, SEMI_COLON_TK, LEFT_BRACKET_TK, RIGHT_BRACKET_TK, ID_TK, INT_TK, EOF_TK, ERROR_TK                  // 37
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
