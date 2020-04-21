#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void toBinary(char * bitMap, char * binary){
	int i = 0;
	for(; i < strlen(bitMap); i++){
		bitMap[i] == '1' ? strcat(binary, "0001") : '';
		bitMap[i] == '2' ? strcat(binary, "0010") : '';
		bitMap[i] == '3' ? strcat(binary, "0011") : '';
		bitMap[i] == '4' ? strcat(binary, "0100") : '';
		bitMap[i] == '5' ? strcat(binary, "0101") : '';
		bitMap[i] == '6' ? strcat(binary, "0110") : '';
		bitMap[i] == '7' ? strcat(binary, "0111") : '';
		bitMap[i] == '8' ? strcat(binary, "1000") : '';
		bitMap[i] == '9' ? strcat(binary, "1001") : '';
		bitMap[i] == 'A' ? strcat(binary, "1010") : '';
		bitMap[i] == 'B' ? strcat(binary, "1011") : '';
		bitMap[i] == 'C' ? strcat(binary, "1100") : '';
		bitMap[i] == 'D' ? strcat(binary, "1101") : '';
		bitMap[i] == 'E' ? strcat(binary, "1110") : '';
		bitMap[i] == 'F' ? strcat(binary, "1111") : '';
	}
}

void delCharArray(char * array, int posicao, int arraySize, int qtd){
    int i = 0, j = 0;
    array[arraySize] = 0;
	printf("arraySize %d", arraySize);
	for(j = 0; j < qtd; j++){
		for (i = posicao; i < arraySize; i++){
			array[i] = array[i+1];
		}
	}
}

void subString(int inicio, int qtd, char *msg, char *destino){
	qtd += inicio-1;
	int i = inicio, j = 0;
	for(; i <= qtd; i++){
		destino[j] = msg[i];
		j++;
	}
}

int main(){
  
	char binaryBitMap[129];
	char iso[5001];
	char isoAux[5001];
	char mti[5], bitMap[33], bits[127][1000];
	int numBits = sizeof(bits)/sizeof(bits[0]);
	int i;
	const int pontoInicial = 0;

	memset(binaryBitMap, 0, sizeof(binaryBitMap));
	memset(iso, 0, sizeof(iso));
	memset(bitMap, 0, sizeof(bitMap));
	memset(mti, 0, sizeof(mti));
	i = 0;
	for(; i < numBits; i++){
		memset(bits[i], 0, sizeof(bits[i]));
	}

	strcpy(iso, "0200B238060000C0920A24000000000004A800300000000000500007261256400000941256400726051000001170328003643000000076600763000135986D264A4E85B90891B3289F260813CA3CDEAFAD32F59F2701809F10200FA501A030F8000000000000000000000F0000000000000000000000000000009F3704F15DDCC49F360200019505220004E0009A031907269C01009F02060000000050009F03060000000000005F2A020986820258009F1A0200769F3501229F34034203005F24032112319F3303E0F0C85F280200768407A00000049410109F12074352454449544F50074352454449544F0160010020100200201031001025PVTE_C01                 0100000201052001020FFFFF444020000000AC3002020FFFFF5040200000005BE04000102089550532190045917204002008CLARO BR192537C8C9B2223DA116A72973D89C0A541AA8941BE9A68E2E87B39CF407CA68D52F66CE4E9116935CC801BDDC3B7EA0B4D92D804D6180107EE5280192F222096B32ABABB30EA7657B669E66712E56800999FD6CA9771F535FE3D7E13D567526EDF");
	strcpy(isoAux, iso);



	subString(pontoInicial, 4, iso, mti);
	delCharArray(iso, pontoInicial, strlen(iso), strlen(mti));
	
	subString(pontoInicial, 32, iso, bitMap);
	delCharArray(iso, pontoInicial, strlen(iso), strlen(bitMap));
	
	toBinary(bitMap, binaryBitMap);

	printf("==> %s", binaryBitMap);

}