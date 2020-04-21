#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned short boolean;
typedef unsigned char uChar;

boolean true	= 1;
boolean false	= 0;


void delCharArray(char * array, int init, int arraySize, int num){
    int i = 0, j = 0;
    array[arraySize] = 0;
	printf("arraySize %d\n", arraySize);
	for(j = 0; j < num; j++){
		for (i = init; i < arraySize; i++){
			array[i] = array[i+1];
		}
	}
}

void subString(int init, int qtd, char *source, char *target){
	qtd += init-1;
	int i = init, j = 0;
	for(; i <= qtd; i++){
		target[j] = source[i];
		j++;
	}
}


int treatEspecialChars(uChar input){
	int ascInput = 0;

	switch (input){
		case 128: ascInput = 183; break;	// À
		case 129: ascInput = 181; break;	// Á
		case 130: ascInput = 182; break;	// Â
		case 131: ascInput = 199; break;	// Ã
		case 135: ascInput = 128; break;	// Ç
		case 137: ascInput = 144; break;	// É
		case 138: ascInput = 210; break;	// Ê
		case 141: ascInput = 214; break;	// Í
		case 147: ascInput = 224; break;	// Ó
		case 148: ascInput = 226; break;	// Ô
		case 149: ascInput = 229; break;	// Õ
		case 154: ascInput = 233; break;	// Ú
		case 160: ascInput = 133; break;	// à
		case 161: ascInput = 160; break;	// á
		case 162: ascInput = 131; break;	// â
		case 163: ascInput = 198; break;	// ã
		case 167: ascInput = 135; break;	// ç
		case 169: ascInput = 130; break;	// é
		case 170: ascInput = 136; break;	// ê
		case 173: ascInput = 161; break;	// í
		case 179: ascInput = 162; break;	// ó
		case 180: ascInput = 147; break;	// ô
		case 181: ascInput = 228; break;	// õ
		case 186: ascInput = 163; break;	// ú

		default:
			printf("");

			ascInput = (int)input;
			break;
	}

	return ascInput;
}

int characterToBinary(uChar input, char *output){

	int ascInput;
	int bits[] = {128, 64, 32, 16, 8, 4, 2, 1};
	int i = 0;
	char binary[9] = {0x00};



	ascInput = treatEspecialChars(input);
	while(ascInput > -1 && i < 8){
		if(ascInput == 195) {
			i++; continue;
		}
		if(ascInput >= bits[i]){
			binary[i] = '1';
			ascInput -= bits[i];
		}else{
			binary[i] = '0';
		}
		i++;
	}

	strcpy(output, binary);

	return 0;
}

int textToBinary(char *input, char *output, int space){

	int i = 0;

	char binaryText[4069] = {0x00};
	char text[8192]			= {0x00};
	char binaryChars[8][128];

	for(i = 0; i < 8; i++){
		memset(binaryChars[i], 0x00, sizeof(binaryChars));
	}

	strcpy(text, input);

	*binaryText = (char*) malloc((strlen(text) * sizeof(char))*8);
	memset(binaryText, 0x00, sizeof(binaryText));

	strcpy(binaryText, "");

	i = 0;
	while(text[i] != 0 && text[i] != '\0'){
		characterToBinary((uChar)text[i], binaryChars[i]);
		if(space){
			sprintf(binaryText, "%s%s ", binaryText, binaryChars[i]);
		}else{
			sprintf(binaryText, "%s%s", binaryText, binaryChars[i]);
		}
		i++;
	}

	if (space){
		binaryText[strlen(binaryText)-1] = '\0';
	}


	strcpy(output, binaryText);

	return 0;
}

char getCharByAscii(int code){
	char character = 0;

	switch (code)
	{
		case 32:  character = ' '; break;
		case 65:  character = 'A'; break;
		case 66:  character = 'B'; break;
		case 67:  character = 'C'; break;
		case 68:  character = 'D'; break;
		case 69:  character = 'E'; break;
		case 70:  character = 'F'; break;
		case 71:  character = 'G'; break;
		case 72:  character = 'H'; break;
		case 73:  character = 'I'; break;
		case 74:  character = 'J'; break;
		case 75:  character = 'K'; break;
		case 76:  character = 'L'; break;
		case 77:  character = 'M'; break;
		case 78:  character = 'N'; break;
		case 79:  character = 'O'; break;
		case 80:  character = 'P'; break;
		case 81:  character = 'Q'; break;
		case 82:  character = 'R'; break;
		case 83:  character = 'S'; break;
		case 84:  character = 'T'; break;
		case 85:  character = 'U'; break;
		case 86:  character = 'V'; break;
		case 87:  character = 'W'; break;
		case 88:  character = 'X'; break;
		case 89:  character = 'Y'; break;
		case 90:  character = 'Z'; break;
		case 183: character = 'A'; break;	// À
		case 181: character = 'A'; break;	// Á
		case 182: character = 'A'; break;	// Â
		case 199: character = 'A'; break;	// Ã
		case 128: character = 'C'; break;	// Ç
		case 144: character = 'E'; break;	// É
		case 210: character = 'E'; break;	// Ê
		case 214: character = 'I'; break;	// Í
		case 224: character = 'O'; break;	// Ó
		case 226: character = 'O'; break;	// Ô
		case 229: character = 'O'; break;	// Õ
		case 233: character = 'U'; break;	// Ú
		case 133: character = 'a'; break;	// à
		case 160: character = 'a'; break;	// á
		case 131: character = 'a'; break;	// â
		case 198: character = 'a'; break;	// ã
		case 135: character = 'c'; break;	// ç
		case 130: character = 'e'; break;	// é
		case 136: character = 'e'; break;	// ê
		case 161: character = 'i'; break;	// í
		case 162: character = 'o'; break;	// ó
		case 147: character = 'o'; break;	// ô
		case 163: character = 'u'; break;	// ú
		case 228: character = 'o'; break;	// õ

		default:
			break;
	}


	return character;
}

int addLeftZeros(char *binInput, char *output){

	char bin[9] = {0x00};
	char aux[9] = {0x00};
	int i = 0;
	int j = 0;

	strcpy(bin, binInput);

	if(strlen(bin) < 8){
		i = 8 - strlen(bin);
		for(j = 0; i > 0; i--, j++){
			aux[j] = '0';
		}
	}
	strcat(aux, bin);

	strcpy(output, aux);
}

char binaryToCharacter(char *binInput){

	char bin[9] = {0x00};
	int binValue = 0;
	int i = 0;
	int exponent = 7;
	char character = 0;

	addLeftZeros(binInput, bin);
	printf(":: %s\n", bin);

	i = 0;
	while(bin[i] != 0 && bin[i] != '\0'){
		if(bin[i] == '1'){
			binValue += pow(2, exponent);
		}
		exponent--;
		i++;
	}

	printf(":: %d\n", binValue);

	character = getCharByAscii(binValue);
	printf(":: %c\n", character);

	return character;
}

int binaryToText(char *binInput, char *output){
	char bin[4096] = {0x00};
	char auxBin[9] = {0X00};
	char result[512] = {0x00};
	int i = 0;

	strcpy(bin, binInput);

	i = 0;
	while(bin[0] != 0 && bin[0] != '\0'){
		subString(0, 8, bin, auxBin);
		delCharArray(bin, 0, strlen(bin), 8);
		result[i] = binaryToCharacter(auxBin);
		i++;
	}

	strcpy(output, result);

	return 0;

}

int main(void){

	int rc = 0;
	char character = 0;
	char binaryText[1024] = {0x00};
	char aux[128] = {0x00};
	char aux2[128] = {0x00};

	rc = textToBinary("KELVIN RONALDO SILVA MARQUES FERREIRA KELVIN RONALDO SILVA MARQUES FERRE", binaryText, false);
	printf(">> %s ::\n", binaryText);


	// binaryToText("01001011010001010100110001010110010010010100111000100000010100100100111101001110010000010100110001000100010011110010000001010011010010010100110001010110010000010010000001001101010000010101001001010001010101010100010101010011001000000100011001000101010100100101001001000101010010010101001001000001001000000100101101000101010011000101011001001001010011100010000001010010010011110100111001000001010011000100010001001111001000000101001101001001010011000101011001000001001000000100110101000001010100100101000101010101010001010101001100100000010001100100010101010010010100100100010101001001", aux);
	// printf(">> %s ::\n", aux);

	return 0;
}