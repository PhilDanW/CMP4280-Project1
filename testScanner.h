#ifndef TESTSCANNER_H
#define TESTSCANNER_H

#include <fstream>
#include "token.h"

void testScanner(std::ifstream& file);
void printTokenInfo(Token token);

#endif
