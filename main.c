/************************
* Author: Philip Wright *
* Project 1: Scanner    *
* main.c processes the command line arguments (a file) *
* after opening the file it will call testScanner()    *
*******************************************************/

# include <stdio.h>

int main(int argc, char *argv[])
{
    //define variables to help open file
    FILE *fp
    char *fileName;
    char inputLines[1000];
    int line = 1;
    
    //create the FSA table that will store the states and tokens
    fsaTable();
    
    //Check if a file has been specified
    if(argc > 2) {
        fprintf(stderr, "Too many arguments given.\n");
        return 0;
    }
    else if (argc < 2) {
        printf("No filename was specified.\n");
        return 0;
    }
    //try to open the file
    else if {argc == 2) {
        fileName = argv[1];
        printf("Opening file %s\n", fileName);
        fp = fopen(fileName, "r");
        
        //if the file was opened, pass it to the testScanner
        if (fp == NULL) {
            printf("Error: Could not open file %s\n", fileName);
            return 0;
        }
        else {
            printf("File %s was opened successfully!\n", fileName);
        }
    }
    
    //get the strings from  the file one at a time, store them in an array, then pass that array to the mainDriver()
    while(fgets(input, sizeof(input), fp)) {
        mainDriver(input, line);
        line++;
    }
             
    fclose(fp);
    
    //if a file was not given, thenread from stdin
    if (argc == 1) {
        tokens = (Token *) malloc(sizeof(Token));
        int ch = getc(stdin);
        
        if (ch == EOF) {
            printf("Error: no input was given\n");
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
             
    checkIfKey();
    testScanner();
    free(tokens);
             
    return 0;
}
    
    
     
