/*********************************************************
* Author: Philip Wright                                  *
* Project 1: Scanner                                     *
* main.cpp processes the command line arguments (a file) *
* or will take keyboard input if no file is given.       *
* After opening the file or taking keyboard input it     * 
* will call testScanner() to scan the tokens given       *
**********************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "testScanner.h"

int main(int argc, char** argv) {
    std::ifstream inFile;         // input file
    std::string fileName;         // filename

    //If no file is given then get input from the user
    if (argc == 1) {
        //create variables necessary for user input
        std::string userInput;
        std::ofstream tempFile;   
        std::string string = "";
        fileName = "stdin.temp";
        
        // trunc overwrites if anything is already written in the file
        tempFile.open(fileName, std::ios::trunc); 
 
        std::cout << "Pressing \"Enter\" is the same as EOF" << std::endl;
        do {
            std::cout << std::endl << "Type your input here: ";
            //get keyboard input from the user
            getline(std::cin, userInput);
            //put that input into a temporary file so that it can be used by the scanner
            tempFile << userInput << "\n";
        } while (!userInput.empty());         
        // close file after writing to it
        tempFile.close();                  
    }

    //Input from file given in command line argument
    else if (argc == 2) {
        fileName = argv[1];
        fileName += ".fs";
        
        std::ofstream outfile;
        outfile.open(fileName, std::ios_base::app);
        outfile << " ";
        std::cout << "stdin.temp" << std::endl;

    }
    //if there is more than one argument quit the program
    else {
        std::cout << "Too many arguments given" << std::endl;
        exit(EXIT_FAILURE);
    }

    inFile.open(fileName);
    
    //If the file is open, scan its contents
    if(!inFile) {
        std::cout << "ERROR: Cannot open " << fileName << " for reading" << std::endl;
        exit(EXIT_FAILURE);
    }
    else {  // cannot open file
        //scan the file with testScanner
        testScanner(inFile); 
        //close file
        inFile.close();
    }
    return 0;
}
