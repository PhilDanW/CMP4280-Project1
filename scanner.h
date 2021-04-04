#ifndef SCANNER_H
#define SCANNER_H

#define row 21
#define col 24
	 
int table[row][col];

extern int z;
char error[LIMIT][LIMIT];
char errorBuffer[LIMIT];
extern int errorIndex;
int isError;

void mainDriver(char *array, int line);
void ignoreComments(char *array);
void checkError();
int isCharacter(char c);
void checkIfKeyword();
void fsaTable();

#endif
