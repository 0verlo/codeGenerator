/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Mar 2017 08:50:46 AM CST
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

#include"codeGenerator.h"

int charTableSelect(int iPosition)
{
	static int lastPunc = 0;
	int charSelect = 0;
	do{
		charSelect = rand() % (126 - 33 + 1) + 33;
	//here you can remove some char you dont like.
	}while(124 == charSelect ||
			96 == charSelect);
	
	//change the random char when there is too less punctuations.
	if((MAX_LENGTH_WIHTOUT_PUNC < (iPosition - lastPunc)) &&
			((46 < charSelect && 58 > charSelect) ||
			 (64 < charSelect && 123 > charSelect))){
		charSelect = charTableSelect(iPosition);
		lastPunc = iPosition;
		//printf("inside punc change,in %d\n",iPosition);
	}else if(!((46 < charSelect && 58 > charSelect) ||
			 (64 < charSelect && 123 > charSelect))){
		lastPunc = iPosition;
	}

	//printf("char you got is %d\n",charSelect);
	return charSelect;
}

char* codeGenerate(int codeLength)
{
	char* tarCode;
	tarCode = malloc(codeLength*sizeof(char));
	memset(tarCode, 0, sizeof(codeLength*sizeof(char)));

	for(int i = 0;i < codeLength;i ++){
		tarCode[i] = (char)charTableSelect(i);
	}

	return tarCode;
}

int lengthInput()
{
	int inputLength;
	printf("Please enter the length of the code:");
	scanf("%d",&inputLength);
	printf("\n");
	return inputLength;
}

void main()
{
	//srand() will initailize the rand() func
	//Which means it should only run once in each process if you need
	srand(time(NULL));
	
	stCrCode newCode;
	newCode.codeLength = 0;
	newCode.tarCode = NULL;
	
	newCode.codeLength = lengthInput();
	newCode.tarCode = codeGenerate(newCode.codeLength);

	printf("You've got a save code:%s\n",newCode.tarCode);
	printf("Like it or not :)\n");
}
