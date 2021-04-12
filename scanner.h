#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"
#include <fstream>
#include <map>
#include <string>

void testScanner(std::ifstream& file);
Token scanner(std::ifstream& in_file, int& lineNum);

int getColumn(char the_char);
Token setToken(int state, std::string word, int lineNum);
void tokenInfo(Token token);

#endif
