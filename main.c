/************************
* Author: Philip Wright *
* Project 1: Scanner    *
* main.c processes the command line arguments (a file) *
* after opening the file it will call testScanner()    *
*******************************************************/
#include "stdio.h"
#include "errno.h"
#include "ctype.h"
#include "token.h"
#include "scanner.h"
#include "testScanner.h"
#include "string.h"
#include "stdlib.h"

int z = 0;
int errorIndex = 0;

int main(int argc, char *argv[])
{
    //define variables to help open file
    char input[1000];
    int line = 1;
    
    //create the FSA table that will store the states and tokens
    fsaTable();
    
    //Check if a file has been specified
    if(argc > 2) {
        fprintf(stderr, "Too many arguments given.\n");
	printf("Use: \n%s\n%s <file>\n", argv[0], argv[0]);
        return 0;
    }
	
    if (argc == 2) {
       	 
	int size = 0;
	size_t length = strlen(argv[1]);
	FILE *file = fopen(strcat(argv[1], ".sp2021"), "r");    
        argv[length] = '\0';
        
        tokens = (Token *) malloc(sizeof(Token));
        //if the file was opened, pass it to the testScanner
        if (file == NULL) {
            perror("Error: Could not open file\n");
            return 0;
        }
        else {
            fseek (file, 0, SEEK_END);

	    size = ftell(file);
	    rewind(file);
	    if(size == 0) {
		fprintf(stderr, "Error: The File is Empty\n");
		return 0;
	    }
	}
	 
	//get the strings from  the file one at a time, store them in an array, then pass that array to the mainDriver()
    	while(fgets(input, sizeof(input), file)) {
        	mainDriver(input, line);
        	line++;
    	}
             
    	fclose(file);
    }
    
    //if a file was not given, thenread from stdin
    if (argc == 1) {
	printf("Type in input for scanner and press CTRL+D when finished\n");
        tokens = (Token *) malloc(sizeof(Token));
	isError = 0;
	    
        int ch = getc(stdin);
        if (ch == EOF) {
            fprintf(stderr, "Error: No input was given\n");
            return 0;
        } 
        else {
            ungetc(ch, stdin);
        }
        
        while(fgets(input, sizeof(input), stdin)) {
            mainDriver(input, line);
            line++;
        }
    }
             
    //end of file token 
	strcpy(tokens[z].instance, "EndToken");
	tokens[z].lineNum = --line;
	tokens[z].tokenType = EOT;
	z++;
             
    checkIfKeyword();
    printf("\n");
	
	
    testScanner();
    free(tokens);
             
    return 0;
}
    
    
     
