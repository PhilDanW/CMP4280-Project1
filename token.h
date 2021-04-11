#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum tokens {
    BEGIN_TOKEN,                 
    END_TOKEN,                   
    LOOP_TOKEN,                  
    WHILE_TOKEN,                 
    VOID_TOKEN,                  
    EXIT_TOKEN,                  
    GETTER_TOKEN,               
    OUTTER_TOKEN,                
    MAIN_TOKEN,                  
    IF_TOKEN,                   
    THEN_TOKEN,                  
    ASSIGN_TOKEN,               
    DATA_TOKEN,               
    PROC_TOKEN,                  
    EQUAL_TOKEN,                
    EQUAL_LESS_THAN_TOKEN,   
    EQUAL_GREATER_THAN_TOKEN,  
    EQUAL_EQUAL_TOKEN,         
    COLON_TOKEN,                 
    COLON_EQUAL_TOKEN,          
    ADD_TOKEN,                  
    SUBTRACT_TOKEN,                 
    ASTERISK_TOKEN,              
    DIVIDE_TOKEN,                 
    MODULUS_TOKEN,               
    PERIOD_TOKEN,                
    LEFT_PARENT_TOKEN,            
    RIGHT_PARENT_TOKEN,           
    COMMA_TOKEN,                 
    LEFT_BRACE_TOKEN,            
    RIGHT_BRACE_TOKEN,           
    SEMICOLON_TOKEN,            
    LEFT_BRACKET_TOKEN,         
    RIGHT_BRACKET_TOKEN,         
    ID_TOKEN,                    
    INT_TOKEN,                   
    EOF_TOKEN,                   
    ERROR_TOKEN                  
} TokenType;

struct Token{
	int lineNum;
	tokens tokenID;
	std::string tokenString;
	
	Token(tokens ID, std::string string, int lineNum)
	{
		this->lineNum = lineNum;
		this->tokenID = ID;
		this->tokenString = string;
	}
};

#endif
