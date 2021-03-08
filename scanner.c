/************************
* Author: Philip Wright *
* Project 1: Scanner    *
* scanner.c loops through the FSA table and begins storing *
* tokens in the token struct                               *
***********************************************************/

#include <stdio.h>
#include "token.h"
#include "scanner.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void mainDriver(char *array, int line) {
  int i;
  int j;
  int nextChar = 0;
  int state = 0;
  
  ignoreComments(array, line);
  
  for(i = 0; i < strlen(array); i++) {
      nextChar = isChar(array[i]);
      if (nextChar == -1) {
          sprintf(errorBuffer, "Scanner Error in line %d:  %c Invalid Character", line, array[i]);
          strcpy(error[errorIndex], errorBuffer);
					errorIndex++;	
					isError = 1;
      }
      else {
          state = table[state][nextChar];
        
          if(state == -1) {
              sprintf(errorBuffer, "Scanner Error in line %d:  %c Invalid Character", line, array[i]);
						  strcpy(error[errorIndex], errorBuffer);
						  errorIndex++;	
						  isError = 1;
          }
        
          switch(state) {
            case '1001':
                      tokens[z].tokenType = IDENTIFIER;
                      break;
            case '1002':
                      tokens[z].tokenType = NUMBER;
                      break;
            case '1003':
                      tokens[z].tokenType = KEYWORD;
                      break;
            case '1004':
                      tokens[z].tokenType = EQUAL;
                      break;
            case '1005':
                      tokens[z].tokenType = LESS;
                      break;
            case '1006':
                      tokens[z].tokenType = GREATER;
                      break;
            case '1007':
                      tokens[z].tokenType = COLON;
                      break;
            case '1008':
                      tokens[z].tokenType = PLUS;
                      break;
            case '1009':
                      tokens[z].tokenType = MINUS;
                      break;
            case '1010':
                      tokens[z].tokenType = ASTERIK;
                      break;
            case '1011':
                      tokens[z].tokenType = SLASH;
                      break;
            case '1012':
                      tokens[z].tokenType = PERCENT;
                      break;
            case '1013':
                      tokens[z].tokenType = DOT;
                      break;
            case '1014':
                      tokens[z].tokenType = L_PARENT;
                      break;
            case '1015':
                      tokens[z].tokenType = R_PARENT;
                      break;
            case '1016':
                      tokens[z].tokenType = COMMA;
                      break;
            case '1017':
                      tokens[z].tokenType = L_BRACE;
                      break;
            case '1018':
                      tokens[z].tokenType = R_BRACE;
                      break;
            case '1019':
                      tokens[z].tokenType = SEMICOLON;
                      break;
            case '1020':
                      tokens[z].tokenType = L_BRACKET;
                      break;
            case '1021':
                      tokens[z].tokenType = R_BRACKET;
                      break;
          }
        
          if(state >= 1001 && state <= 1021){
						state = 0;
						tokens[z].lineNum = line;	
            checkError();
						z++;
						i--;
						j=0;
						j--;
					}	 

					if(!isspace(array[i])){
						tokens[z].instance[j] = array[i];
						j++;
					} 
      }
   }
}

//functions that ignore comments and check for error
void ignoreComments(char *array, int line){
	int i;
	size_t length = strlen(array);

	for(i = 0; i < length; i++){
		if (array[i] == '$') {
			int j;			
			array[i] = ' ';
					
			for(j=i+1; j < length; j++ ){
				if(array[j] == '$' && array[j] != '\n'){	
					array[j] = ' ';
					j = length + 1;
				} else if(array[j] != '$' && array[j] == '\n'){	
					sprintf(errorBuffer, "Scanner Error in Line %d: Missing $ at the end of the line", line);
					strcpy(error[errorIndex], errorBuffer);
					errorIndex++;
					isError = 1;
				} else {
					array[j] = ' ';
				}			
			}
		}
	}	
}

void checkError(){	
	//check the identifier first letter starts  with capital letter
	int len = strlen(tokens[z].instance);
		
	//check if the identifier is longer than 8 and start with Capital letter
	if(tokens[z].tokenType == IDENTIFIER){
		
			//check if length is greater than 8 show error
			if (len > 8) {
				sprintf(errorBuffer, "Scanner Error in Line %d: identifier %s, needs to have max letter of 8", tokens[z].lineNum, tokens[z].instance);
				strcpy(error[errorIndex], errorBuffer);
				errorIndex++;
				isError = 1;
			}

			//check if it is lowercase letter start of identifier and show error
			if(!islower(tokens[z].instance[0])){
				sprintf(errorBuffer, "Scanner Error in Line %d: identifier %s, first letter should be lowercase", tokens[z].lineNum, tokens[z].instance);
				strcpy(error[errorIndex], errorBuffer);
				errorIndex++;	
				isError = 1;
			}
  }
		
	//check if the length of digit is longer than 8 then show error
	if(tokens[z].tokenType == NUMBER){
					
		  if (len > 8) {
				sprintf(errorBuffer, "Scanner Error in Line %d: integer %s, needs to have max digit of 8", tokens[z].lineNum, tokens[z].instance);
				strcpy(error[errorIndex], errorBuffer);
				errorIndex++;
				isError = 1;
			}	
  }
}
		     
//check the character then return nextChar Index
int isCharacter(char c) {
	if(isalpha(c)){
		return 0;
  }
	if(c == '_'){
		return 6;
	}
	if(c == ' ' || c == '\t' || c == '\n') {
		return 4;
	}
	if(isdigit(c)){
		return 1;
	}
	if(c == '='){
		return 2;
	}
	if(c == '<'){
		return 3;
	}
	if(c == '>'){
		return 7;
	}
	if(c == ':'){
		return 8;
	}
	if(c == '+'){
		return 9;
	}
	if(c == '-'){
		return 10;
	}
	if(c == '*'){
		return 11;
	}
  if(c == '/'){
		return 12;
	}
	if(c == '%'){
		return 13;
	}
	if(c == '.'){
		return 14;
	}
	if(c == '('){
		return 15;
	}
	if(c == ')'){
		return 16;
	}
	if(c == ','){
		return 17;
	}
	if(c == '{'){
		return 18;
	}
	if(c == '}'){
		return 19;
	}
	if(c == ';'){
		return 20;
	}
	if(c == '['){
		return 21;
	}
	if(c == ']'){
		return 22;
	}
	return -1;
}
    
//check if the identifier is keyword 
void checkIfKeyword() {
	int i;
  int j;
	char *keywords[] = {"start","stop","loop","void","var","return","scan","out","program","if","then","let"};
	size_t len = sizeof(keywords)/sizeof(keywords[0]);;
	
	for(i=0; i < z; i++) {
		if(tokens[i].tokenType == IDENTIFIER){
			for (j=0; j < len; j++){
				if(strcmp(tokens[i].instance, "start") == 0){
					tokens[i].tokenType = START_KEYWORD;	
				}
			
				if(strcmp(tokens[i].instance, "stop") == 0){
					tokens[i].tokenType = STOP_KEYWORD;	
				}
				
				if(strcmp(tokens[i].instance, "loop") == 0){
					tokens[i].tokenType = LOOP_KEYWORD;	
				}
				
				if(strcmp(tokens[i].instance, "void") == 0){
					tokens[i].tokenType = VOID_KEYWORD;	
				}
				
				if(strcmp(tokens[i].instance, "var") == 0){
					tokens[i].tokenType = VAR_KEYWORD;	
				}

				if(strcmp(tokens[i].instance, "return") == 0){
					tokens[i].tokenType = RETURN_KEYWORD;	
				}

				if(strcmp(tokens[i].instance, "scan") == 0){
					tokens[i].tokenType = SCAN_KEYWORD;	
				}

				if(strcmp(tokens[i].instance, "out") == 0){
					tokens[i].tokenType = OUT_KEYWORD;	
				}

				if(strcmp(tokens[i].instance, "program") == 0){
					tokens[i].tokenType = PROGRAM_KEYWORD;	
				}
				
				if(strcmp(tokens[i].instance, "if") == 0){
					tokens[i].tokenType = IF_KEYWORD;	
				}
				
				if(strcmp(tokens[i].instance, "then") == 0){
					tokens[i].tokenType = THEN_KEYWORD;	
				}
				
				if(strcmp(tokens[i].instance, "let") == 0){
					tokens[i].tokenType = LET_KEYWORD;	
				}
			}
		}
	}
}
  
void fsaTable() {
    int i;
    int j;
    int k = 1003;
  
    //first state
    table[0][0] = 1;
    table[0][1] = 2;
    table[0][2] = 3;
    table[0][3] = 4;
    table[0][4] = 0;
    table[0][5] = 1005;
    table[0][6] = -1;
    table[0][7] = 5;
    table[0][8] = 6;
    table[0][9] = 7;
    table[0][10] = 8;
    table[0][11] = 9;
    table[0][12] = 10;
    table[0][13] = 11;
    table[0][14] = 12;
    table[0][15] = 13;
    table[0][16] = 14;
    table[0][17] = 15;
    table[0][18] = 16;
    table[0][19] = 17;
    table[0][20] = 18;
    table[0][21] = 19;
    table[0][22] = 20;
  
    //identifier states
    table[1][0] = 1;
    table[1][1] = 1001;
    table[1][2] = 1001;
    table[1][3] = 1001;
    table[1][4] = 1001;
    table[1][5] = 1001;
    table[1][6] = 1;
    table[1][7] = 1001;
    table[1][8] = 1001;
    table[1][9] = 1001;
    table[1][10] = 1001;
    table[1][11] = 1001;
    table[1][12] = 1001;
    table[1][13] = 1001;
    table[1][14] = 1001;
    table[1][15] = 1001;
    table[1][16] = 1001;
    table[1][17] = 1001;
    table[1][18] = 1001;
    table[1][19] = 1001;
    table[1][20] = 1001;
    table[1][21] = 1001;
    table[1][22] = 1001;
    
    //integer states
    table[2][0] = 1002;
    table[2][1] = 2;
    table[2][2] = 1002;
    table[2][3] = 1002;
    table[2][4] = 1002;
    table[2][5] = 1002;
    table[2][6] = 1002;
    table[2][7] = 1002;
    table[2][8] = 1002;
    table[2][9] = 1002;
    table[2][10] = 1002;
    table[2][11] = 1002;
    table[2][12] = 1002;
    table[2][13] = 1002;
    table[2][14] = 1002;
    table[2][15] = 1002;
    table[2][16] = 1002;
    table[2][17] = 1002;
    table[2][18] = 1002;
    table[2][19] = 1002;
    table[2][20] = 1002;
    table[2][21] = 1002;
    table[2][22] = 1002;
     
    //loop to assign value to all other states
    for(i = 3; i < 21; i++) {
       for(j = 0; j < 23; j++) {
           table[i][j] = k;
       }
       k++;
    }
}
              
  
