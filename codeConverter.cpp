// codeConverter.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE_PATH			"M:\\Study\\Fomin\\SM6\\LBS\\LB2\\input.txt"
#define OUTPUT_FILE_PATH		""

char *firstString;
char *secondString;

bool readStringsFromFile(char *);
char convertSymbol(char);
bool convertToReverseCode(void);

int main()
{
		puts((char *)"Input strings\n");
		readStringsFromFile((char *)INPUT_FILE_PATH);
		puts((char *)"Output strings\n");
		convertToReverseCode();
		system("pause");
    return 0;
}


bool readStringsFromFile(char *inputFilePath) {
	FILE *inputFile;
	int i = 0;
	long fileLength;
	inputFile = fopen(inputFilePath, "r");
	fseek(inputFile, 0, SEEK_END);
	fileLength = ftell(inputFile);
	fseek(inputFile, 0, SEEK_SET);
	firstString = (char *)malloc(sizeof(char)*fileLength/2);
	secondString = (char *)malloc(sizeof(char)*fileLength/2);
	while ((firstString[i] = fgetc(inputFile)) != '\n') {
		i++;
	}
	firstString[i] = '\0';
	puts((char *)firstString);
	fgets((char *)secondString, strlen(firstString-1), inputFile);
	puts((char *)secondString);
	fclose(inputFile);
	return true;
}



bool convertToReverseCode(void) {
	int i;
	for (i = 1; i < strlen(firstString); i++) {
		firstString[i] = convertSymbol(firstString[i]);
		secondString[i] = convertSymbol(secondString[i]);
	}
	puts(firstString);
	puts(secondString);
	return true;
}


char convertSymbol(char symbol) {
	switch (symbol) {
		case '1':
			return '0';
		case '0':
			return '1';
	}
}

