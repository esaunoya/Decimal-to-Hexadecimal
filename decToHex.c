#include <stdio.h>

int findMax(int decimal);
void convertDecimalToBinary(int decimal, char arr[], int max, char hexVals[]);
void printArray(char arr[], int max);

int main(void){
	char hexVals[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int decimal = -1;
	int max = -1;

	printf("Decimal to Hexadecimal Converter\n\n");
	
	while(decimal < 0){
		printf("Please enter a decimal number 0 or greater: ");
		scanf("%d", &decimal);
		if(decimal < 0)
			printf("\n You have entered a number less than 0.\n\n");
		
	}

	max = findMax(decimal);
	char hex[max];
	printf("\n");
	convertDecimalToBinary(decimal, hex, max, hexVals);
	printArray(hex, max);


	return 0;
}

int findMax(int decimal){
	int bitLen = 0;
	int mul = 1;
	while(decimal >= mul){
		bitLen++;
		mul*=16;
	}
	if(bitLen==0)bitLen=1;
	return bitLen;
}


void convertDecimalToBinary(int decimal, char arr[], int max, char hexVals[]){
	int temp;
	for(int i = 0; i < max; i++){
		temp = decimal%16;
		arr[(max-1)-i]=hexVals[temp];
		decimal = decimal >> 4;
	}
	return;
}

void printArray(char arr[], int max){
	for(int i = 0; i < max; i++){
		printf("%c", arr[i]);	
	}
	printf("\n\n");
	return;
}
