/************************
* Author: Philip Wright *
* Project 1: Scanner    *
* testScanner.c asks for one token at a time to display*
* the token to the screen *
*******************************************************/
#include "scanner.h"
#include "testScanner.h"
#include <iostream>
#include <iomanip>

//array holding all the names of the allowed tokens
std::string tokens[] = {"BEGIN_TOKEN","END_TTOKEN","LOOP_TOKEN","WHILE_TOKEN", "VOID_TOKEN", "EXIT_TOKEN", "GETTER_TOKEN", "OUTTER_TOKEN", "MAIN_TOKEN", 
			"IF_TOKEN", "THEN_TOKEN", "ASSIGN_TOKEN", "DATA_TOKEN", "PROC_TOKEN", "EQUAL_TOKEN", "EQUAL_LESS_THAN_TOKEN", 
			"EQUAL_GREATER_THAN_TOKEN", "EQUAL_EQUAL_TOKEN", "COLON_TOKEN", "COLON_EQUAL_TOKEN", "ADD_TOKEN", "SUBTRACT_TOKEN", 
			"ASTERISK_TOKEN", "DIVIDE_TOKEN", "MODULUS_TOKEN", "PERIOD_TOKEN", "LEFT_PARENT_TOKEN", "RIGHT_PARENT_TOKEN", "COMMA_TOKEN", 
			"LEFT_BRACE_TOKEN", "RIGHT_BRACE_TOKEN", "SEMICOLON_TOKEN", "LEFT_BRACKET_TOKEN", "RIGHT_BRACKET_TOKEN", "ID_TOKEN", 
			"INT_TOKEN", "EOF_TOKEN", "ERROR_TOKEN"};

//test scanner to loop thru tokens from given file or keyboard input
void testScanner(std::ifstream& file){
	int lineNum = 1;
	do {
		//get all the tokens from the given file
		Token token = scanner(file, lineNum);
		if(token.tokenID == ERROR_TOKEN) {
			exit(EXIT_FAILURE);
		}
		else {
			tokenInfo(token);
		}
	} while (file);
}

//prints out the token info to the screen
void tokenInfo(Token token) {
	std::cout << std::left;
	std::cout << "Line number: " << std::setw(3) << token.lineNum;
	std::cout << "\tToken type: " << std::setw(22) << tokens[token.tokenID];
	std::cout << "\tToken value: " << std::setw(10) << token.tokenString << std::endl;
}
