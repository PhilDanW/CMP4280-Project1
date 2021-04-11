/************************
* Author: Philip Wright *
* Project 1: Scanner    *
* main.c processes the command line arguments (a file) *
* after opening the file it will call testScanner()    *
*******************************************************/
#include "testScanner.h"
#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
	//file input in the command line
	std::ifstream inputFile;
	//name of the file given
	std::string fname;
	
	//if appropriate args given, open the file for reading
	if(argc == 2) {
		fname = argv[1];
		fname += ".sp2021";
		
		std::ofstream outputFile;
		outputFile.open(fname, std::ios_base::app);
		outputFile << " ";
		std::cout << "stdin.temp" << std::endl;
	}
	//otherwise take input from the keyboard
	else if (argc == 1) {
		std::string keyboard;
		std::ofstream temp;
		fname = "stdin.temp";
		
		temp.open(fname, std::ios::trunc);
		
		std::string str = "";
		std::cout << "Type you input here. Pressing \"Enter\" will represent EOF. Type CTRL+D to finish input" << std::endl;
		
		do{
			getline(std::cin, keyboard);
			temp << keyboard << "\n";
		}while (!keyboard.empty());
		
		temp.close();
	}
	else {
		std::cout << "You have entered too many arguments" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	//open the file with the tokens for reading
	inputFile.open(fname);
	
	//if the file is open, pass it to the testScanner()
	if(inputFile) {
		testScanner(inputFile);
		inputFile.close();
	}
	else {
		std::cout << "ERROR: Failed to open " << fname << std::endl;
		exit(EXIT_FAILURE);
	}
	return 0;
}
