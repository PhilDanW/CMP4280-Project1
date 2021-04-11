/************************
* Author: Philip Wright *
* Project 1: Scanner    *
* scanner.c loops through the FSA table and begins storing *
* tokens in the token struct                               *
***********************************************************/

#include "scanner.h"
#include "token.h"
#include <fstream>
#include <map>
#include <string>
#include <iostream>

int fsa_table[23][23] = {   // [row] [col]   ws = whitespace, lc = lowercase, UC = UpperCase, dig = digit, eof = end of file
 //   ws   lc   UC  dig    =    <    >    :    +    -    *    /    %    .    (    )    ,    {    }    ;    [    ]  eof  
    {  0,   1,  23,   2,   3,  23,  23,   7,   9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20,  21,  22,  -1}, // 0
    {100,   1,   1, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100}, // 1 id
    {101, 101, 101,   2, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101}, // 2 int
    {102, 102, 102, 102,   6,   5,   4, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102}, // 3 =
    {103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103}, // 4 =>
    {104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104}, // 5 =<
    {105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105}, // 6 ==
    {106, 106, 106, 106,   8, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106}, // 7 :
    {107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107}, // 8 :=
    {108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108}, // 9 +
    {109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109}, // 10 -
    {110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110}, // 11 *
    {111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111}, // 12 /
    {112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112}, // 13 %
    {113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113}, // 14 .
    {114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114}, // 15 (
    {115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115}, // 16 )
    {116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116}, // 17 ,
    {117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117}, // 18 {
    {118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118}, // 19 }
    {119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119}, // 20 ;
    {120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120}, // 21 [
    {121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121}  // 22 ]
};

std::map<std::string, tokens> keywords = {
	{"begin", BEGIN_TOKEN},
	{"end", END_TOKEN},
	{"loop", LOOP_TOKEN},
	{"while", WHILE_TOKEN},
	{"void", VOID_TOKEN},
	{"exit", EXIT_TOKEN},
	{"getter", GETTER_TOKEN},
	{"outter", OUTTER_TOKEN},
	{"main", MAIN_TOKEN},
	{"if", IF_TOKEN},
	{"then", THEN_TOKEN},
	{"assign", ASSIGN_TOKEN},
	{"data", DATA_TOKEN},
	{"proc", PROC_TOKEN}
};

std::map<char, int> symbols = {
    {'=', 4},
    {'<', 5},
    {'>', 6},
    {':', 7},
    {'+', 8},
    {'-', 9},
    {'*', 10},
    {'/', 11},
    {'%', 12},
    {'.', 13},
    {'(', 14},
    {')', 15},
    {',', 16},
    {'{', 17},
    {'}', 18},
    {';', 19},
    {'[', 20},
    {']', 21}
};

std::map<int, tokens> endState = {
    {100, ID_TOKEN},
    {101, INT_TOKEN},
    {-1, EOF_TOKEN},
    {102, EQUAL_TOKEN},
    {103, EQUAL_GREATER_THAN_TOKEN},
    {104, EQUAL_LESS_THAN_TOKEN},
    {105, EQUAL_EQUAL_TOKEN},
    {106, COLON_TOKEN},
    {107, COLON_EQUAL_TOKEN},
    {108, ADD_TOKEN},
    {109, SUBSTRACT_TOKEN},
    {110, ASTERISK_TOKEN},
    {111, DIVIDE_TOKEN},
    {112, MODULUS_TOKEN},
    {113, PERIOD_TOKEN},
    {114, LEFT_PARENT_TOKEN},
    {115, RIGHT_PARENT_TOKEN},
    {116, COMMA_TOKEN},
    {117, LEFT_BRACE_TOKEN},
    {118, RIGHT_BRACE_TOKEN},
    {119, SEMICOLON_TOKEN},
    {120, LEFT_BRACKET_TOKEN},
    {121, RIGHT_BRACKET_TOKEN}
};
	
Token scanner(std::ifstream& in_file, int& lineNum){
    int initState = 0;           // initialize state       
    int lookAhead = 0;       // initialize lookahead
    char the_char = ' ';  // empty char for reading char    
    std::string str = "";   // placeholder for building string
    
    while (initState < 100){           // loop until end state is hit
        in_file.get(the_char);
        
        // Skips comments 
        if (the_char == '$'){
            in_file.get(the_char);
            if (the_char == '$') {              // Find $$
                in_file.get(the_char);
                while (1) {                        // loop until break
                    in_file.get(the_char);
                    if (in_file.eof()) {
			//if there is no closing $$ for a comment print error
                        std::cout << "SCANNER ERROR: Comment not closed, EOF reached at line: " << lineNum << std::endl;   
                        return Token(ERROR_TK, "No end to comment", lineNum);
                    }
                    if (the_char == '$') {
                        in_file.get(the_char);  
                        if (the_char == '$') {
                            in_file.get(the_char);  // Find $$
                            break;
                        }
                    }
                }
            }        
        }
        
        int fsaColumn = getColumn(the_char);   // find the colomn of char
        
        if (in_file.eof()){   //EOF
            fsaColumn = 22;
        }

        if (fsaColumn == 23)   // error
        {

            std::cout << "SCANNER ERROR: Invalid character detected \'" << the_char << "\'";
            std::cout << " at line: " << lineNum << std::endl;

            return Token(ERROR_TK, "Invalid char", lineNum);
        }

        lookAhead = fsa_table[initState][fsaColumn];

        if (lookAhead == 23) {                  // error
            std::cout << "SCANNER ERROR 2: Invalid char \"" << the_char << "\"";
            std::cout << " at line: " << lineNum << std::endl;
            return Token(ERROR_TK, "Invalid ID", lineNum);
        }

        else if (lookAhead == -1) {
            return Token(EOF_TK, "EOF", lineNum);
        }
        
        else if (lookAhead >= 100)
        {
            in_file.unget();
            return setToken(lookAhead, str, lineNum);
        }
        else
        {
            if (!isspace(the_char))
            {
                str += the_char;
	    }
	    // ensures that identifiers cannot be more than 8 characters long
            if (str.length() >= 9)                 
            {
                std::cout << "SCANNER ERROR 3: \"" << str << "\" is longer than 8 chars";
                std::cout << " at line: " << lineNum << std::endl;
                return Token(ERROR_TK, "Invalid Length", lineNum);
            }
            if (the_char == '\n')
            {
                lineNum++;
            }
 
            initState = lookAhead;
        }
    }

    return Token(ERROR_TK, "Scanner Failed", lineNum);

}

int setFSAcol(char the_char){
    
    if (the_char == EOF)
        return 22;

    if (isspace(the_char))
        return 0;       // ws
    
    if (isalpha(the_char) || the_char == '_'){
        if (isupper(the_char))
            return 2;   // uppercase
        return 1;       // lowercase
    }

    if (isdigit(the_char))
        return 3;       // digit


    else  // valid symbol
    {
        if (symbols.find(the_char) != symbols.end())
            return symbols[the_char];
    }

    return 23;  // Leads to error state
}

// sets the type of token
Token setToken(int initState, std::string str, int lineNum){
    // keywords
    if (keywords.find(str) != keywords.end()) {
         return Token(keywords[str], str, lineNum);
    }
    // symbols
    else {
        return Token(endState[initState], str, lineNum);
    }
}
