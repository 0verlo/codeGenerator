/*************************************************************************
	> File Name: codeGenerator.h
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Mar 2017 10:55:56 AM CST
 ************************************************************************/

#ifndef _CODEGENERATOR_H
#define _CODEGENERATOR_H

#define MAX_LENGTH_WIHTOUT_PUNC 5 
//XXX:A more complex rule can be set.

typedef struct _stCrCode{
	int codeLength;
	char *tarCode;
}stCrCode;

int charTableSelect(int iPosition);
char* codeGenerate(int codeLength);
int lengthInput();

#endif
