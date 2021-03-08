/************************
* Author: Philip Wright *
* Project 1: Scanner    *
* main.c processes the command line arguments (a file) *
* after opening the file it will call testScanner()    *
*******************************************************/

# include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp
    char *fileName;
    char ch;
    
    //Check if a file has been specified
    if(argc > 2) {
        printf("Too many arguments given. See the help screen\n");
        helpScreen();
        return(1);
    }
    else if (argc < 2) {
        printf("No filename was specified. See the help screen\n");
        helpScreen();
        return(1)
    }
    //try to open the file
    else if {argc == 1) {
        fileName = argv[1];
        printf("Opening file %s\n", fileName);
        fp = fopen(fileName, "r");
        
        //if the file was opened, pass it to the testScanner
        if (fp) {
            printf("File %s was opened successfully!\n", fileName);
            testScanner(fp);
        }
        else {
            printf("Error: Could not open file %s\n", fileName);
        }
    }
    
    fclose(fp);
    return(0);
}
    
    
     
