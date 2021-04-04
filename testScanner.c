/************************
* Author: Philip Wright *
* Project 1: Scanner    *
* testScanner.c asks for one token at a time to display*
* the token to the screen *
*******************************************************/

#include "token.h"
#include "scanner.h"
#include "stdio.h"
#include "stdlib.h"
#include "testScanner.h"

//test scanner
void testScanner(){
	int i;
  	int j;
	
	if (isError == 1) {
		for(j = 0; j < errorIndex; j++){
			printf("%s\n", error[j]);
		}
	} 
  	else {
		//since my token type is enum, I have to print them all manually
		for(i=0; i < z; i++){
		
			if(tokens[i].tokenType == IDENTIFIER){
				printf("Line: %-3d | Token: %-8s | Token Type: Identifier Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == NUMBER){	
				printf("Line: %-3d | Token: %-8s | Token Type: Number Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == EQUAL){	
				printf("Line: %-3d | Token: %-8s | Token Type: Equal Token\n", tokens[i].lineNum, tokens[i].instance);	
			}  else if(tokens[i].tokenType == LESS){	
				printf("Line: %-3d | Token: %-8s | Token Type: Less Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == GREATER){	
				printf("Line: %-3d | Token: %-8s | Token Type: Greather Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == COLON){	
				printf("Line: %-3d | Token: %-8s | Token Type: Colon Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == PLUS){	
				printf("Line: %-3d | Token: %-8s | Token Type: Plus Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == MINUS){	
				printf("Line: %-3d | Token: %-8s | Token Type: Minus Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == ASTERIK){	
				printf("Line: %-3d | Token: %-8s | Token Type: Asterik Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == SLASH){	
				printf("Line: %-3d | Token: %-8s | Token Type: Slash Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == PERCENT){	
				printf("Line: %-3d | Token: %-8s | Token Type: Percent Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == DOT){	
				printf("Line: %-3d | Token: %-8s | Token Type: Dot Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == L_PARENT){	
				printf("Line: %-3d | Token: %-8s | Token Type: Left Parenthesis Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == R_PARENT){	
				printf("Line: %-3d | Token: %-8s | Token Type: Right Parenthesis Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == COMMA){	
				printf("Line: %-3d | Token: %-8s | Token Type: Comma Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == L_BRACE){	
				printf("Line: %-3d | Token: %-8s | Token Type: Left Brace Token\n", tokens[i].lineNum, tokens[i].instance);	
			}  else if(tokens[i].tokenType == R_BRACE){	
				printf("Line: %-3d | Token: %-8s | Token Type: Right Brace Token\n", tokens[i].lineNum, tokens[i].instance);	
			}  else if(tokens[i].tokenType == SEMICOLON){	
				printf("Line: %-3d | Token: %-8s | Token Type: Semicolon Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == L_BRACKET){	
				printf("Line: %-3d | Token: %-8s | Token Type: Left Brackets Token\n", tokens[i].lineNum, tokens[i].instance);
			}  else if(tokens[i].tokenType == R_BRACKET){	
				printf("Line: %-3d | Token: %-8s | Token Type: Right Brackets Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == BEGIN_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: begin Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == END_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: end Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == LOOP_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: loop Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == WHILE_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: while Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == VOID_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: void Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == EXIT_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: exit Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == GETTER_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: getter Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == OUTTER_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: outter Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == MAIN_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: main Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == IF_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: if Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == THEN_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: then Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == ASSIGN_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: assign Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == DATA_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: data Keyword Token\n", tokens[i].lineNum, tokens[i].instance);	
			} else if(tokens[i].tokenType == PROC_KEYWORD){		
				printf("Line: %-3d | Token: %-8s | Token Type: proc Keyword Token\n", tokens[i].lineNum, tokens[i].instance);
			} else if(tokens[i].tokenType == EOT){		
				printf("Line: %-3d | Token: %-8s | Token Type: EOF Token\n", tokens[i].lineNum, tokens[i].instance);
			}
		}
	}
}
