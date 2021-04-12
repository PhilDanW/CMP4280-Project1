/************************
* Author: Philip Wright *
* Project 1: Scanner    *
* main.c processes the command line arguments (a file) *
* after opening the file it will call testScanner()    *
*******************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "testScanner.h"

int main(int argc, char** argv) {
    std::ifstream inFile;         // input file
    std::string fileName;         // filename
    int option = argc;
    
    switch(option) {
        case 1:
            std::string userInput;
            std::ofstream tempFile;                 // TempFile for user input
            fileName = "stdin.temp";

            tempFile.open(fileName, std::ios::trunc); // trunc overwrites

            std::string string = "";                // empty string for reading input

            std::cout << "Pressing \"Enter\" on empty line will simulate EOF" << std::endl;

            do {
                std::cout << std::endl << "Keyboard Input: ";
                getline(std::cin, userInput);   // read user input
                tempFile << userInput << "\n";   // write input to temp file
            } while (!userInput.empty());         // Pressing "Enter" on empty line will sim EOF

            tempFile.close();                   // close file
            break;
        case 2:
            fileName = argv[1];
            fileName += ".fs";
        
            std::ofstream outfile;
            outfile.open(fileName, std::ios_base::app);
            outfile << " ";
            std::cout << "stdin.temp" << std::endl;
            break;
        case 3:
            std::cout << "Too many arguments given" << std::endl;
            exit(EXIT_FAILURE);
            break;
    }
    
    inFile.open(fileName);
    
    // Scan file
    if (inFile) {

        testScanner(inFile);  //scan file with testScanner

        inFile.close(); // close file

    }
    else {  // cannot open file
    std::cout << "ERROR: Cannot open " << fileName << " for reading" << std::endl;

    exit(EXIT_FAILURE);
    }
    return 0;
}
