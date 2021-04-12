/***********************************************************
* Author: Philip Wright                                    *
* Project 1: Scanner                                       *
* testScanner.h provides funtion definitions for           *
* testScanner.cpp                                          *  
***********************************************************/
#ifndef TESTSCANNER_H
#define TESTSCANNER_H

#include <fstream>
#include "token.h"

void testScanner(std::ifstream& file);
void printTokenInfo(Token token);

#endif
