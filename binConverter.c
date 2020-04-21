#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned short boolean;
typedef unsigned char uChar;

boolean true = 1;
boolean false = 0;

int treatEspecialChars(uChar input)
{
    int ascInput = 0;

    switch (input)
    {
    case 128:
        ascInput = 183;
        break; // À
    case 129:
        ascInput = 181;
        break; // Á
    case 130:
        ascInput = 182;
        break; // Â
    case 131:
        ascInput = 199;
        break; // Ã
    case 135:
        ascInput = 128;
        break; // Ç
    case 137:
        ascInput = 144;
        break; // É
    case 138:
        ascInput = 210;
        break; // Ê
    case 141:
        ascInput = 214;
        break; // Í
    case 147:
        ascInput = 224;
        break; // Ó
    case 148:
        ascInput = 226;
        break; // Ô
    case 149:
        ascInput = 229;
        break; // Õ
    case 154:
        ascInput = 233;
        break; // Ú
    case 160:
        ascInput = 133;
        break; // à
    case 161:
        ascInput = 160;
        break; // á
    case 162:
        ascInput = 131;
        break; // â
    case 163:
        ascInput = 198;
        break; // ã
    case 167:
        ascInput = 135;
        break; // ç
    case 169:
        ascInput = 130;
        break; // é
    case 170:
        ascInput = 136;
        break; // ê
    case 173:
        ascInput = 161;
        break; // í
    case 179:
        ascInput = 162;
        break; // ó
    case 180:
        ascInput = 147;
        break; // ô
    case 181:
        ascInput = 228;
        break; // õ
    case 186:
        ascInput = 163;
        break; // ú

    default:
        printf("");

        ascInput = (int)input;
        break;
    }

    return ascInput;
}

int characterToBinary(uChar input, char *output)
{

    int ascInput;
    int bits[] = {128, 64, 32, 16, 8, 4, 2, 1};
    int i = 0;
    char binary[9] = {0x00};

    ascInput = treatEspecialChars(input);
    while (ascInput > -1 && i < 8)
    {
        if (ascInput == 195)
        {
            i++;
            continue;
        }
        if (ascInput >= bits[i])
        {
            binary[i] = '1';
            ascInput -= bits[i];
        }
        else
        {
            binary[i] = '0';
        }
        i++;
    }

    strcpy(output, binary);

    return 0;
}

int textToBinary(char *input, char *output, int space)
{

    int i = 0;

    char *binaryText;
    char text[8192] = {0x00};
    char binaryChars[8][128];

    for (i = 0; i < 8; i++)
    {
        memset(binaryChars[i], 0x00, sizeof(binaryChars));
    }

    strcpy(text, input);

    binaryText = (char *)malloc((strlen(text) * sizeof(char)) * 8);
    memset(binaryText, 0x00, sizeof(binaryText));

    strcpy(binaryText, "");

    i = 0;
    while (text[i] != 0 && text[i] != '\0')
    {
        characterToBinary((uChar)text[i], binaryChars[i]);
        if (space)
        {
            sprintf(binaryText, "%s%s ", binaryText, binaryChars[i]);
        }
        else
        {
            sprintf(binaryText, "%s%s", binaryText, binaryChars[i]);
        }
        i++;
    }

    if (space)
    {
        binaryText[strlen(binaryText) - 1] = '\0';
    }

    strcpy(output, binaryText);

    return 0;
}

int getCharByAscii(int code)
{
    char character[3] = {0x00};

    switch (code)
    {
    case 65:
        strcpy(character, "A");
        break;
    case 66:
        strcpy(character, "B");
        break;
    case 67:
        strcpy(character, "C");
        break;
    case 68:
        strcpy(character, "D");
        break;
    case 69:
        strcpy(character, "E");
        break;
    case 70:
        strcpy(character, "F");
        break;
    case 71:
        strcpy(character, "G");
        break;
    case 72:
        strcpy(character, "H");
        break;
    case 73:
        strcpy(character, "I");
        break;
    case 74:
        strcpy(character, "J");
        break;
    case 75:
        strcpy(character, "K");
        break;
    case 76:
        strcpy(character, "L");
        break;
    case 77:
        strcpy(character, "M");
        break;
    case 78:
        strcpy(character, "N");
        break;
    case 79:
        strcpy(character, "O");
        break;
    case 80:
        strcpy(character, "P");
        break;
    case 81:
        strcpy(character, "Q");
        break;
    case 82:
        strcpy(character, "R");
        break;
    case 83:
        strcpy(character, "S");
        break;
    case 84:
        strcpy(character, "T");
        break;
    case 85:
        strcpy(character, "U");
        break;
    case 86:
        strcpy(character, "V");
        break;
    case 87:
        strcpy(character, "W");
        break;
    case 88:
        strcpy(character, "X");
        break;
    case 89:
        strcpy(character, "Y");
        break;
    case 90:
        strcpy(character, "Z");
        break;
    case 183:
        strcpy(character, "À");
        break;
    case 181:
        strcpy(character, "Á");
        break;
    case 182:
        strcpy(character, "Â");
        break;
    case 199:
        strcpy(character, "Ã");
        break;
    case 128:
        strcpy(character, "Ç");
        break;
    case 144:
        strcpy(character, "É");
        break;
    case 210:
        strcpy(character, "Ê");
        break;
    case 214:
        strcpy(character, "Í");
        break;
    case 224:
        strcpy(character, "Ó");
        break;
    case 226:
        strcpy(character, "Ô");
        break;
    case 229:
        strcpy(character, "Õ");
        break;
    case 233:
        strcpy(character, "Ú");
        break;
    case 133:
        strcpy(character, "à");
        break;
    case 160:
        strcpy(character, "á");
        break;
    case 131:
        strcpy(character, "â");
        break;
    case 198:
        strcpy(character, "ã");
        break;
    case 135:
        strcpy(character, "ç");
        break;
    case 130:
        strcpy(character, "é");
        break;
    case 136:
        strcpy(character, "ê");
        break;
    case 161:
        strcpy(character, "í");
        break;
    case 162:
        strcpy(character, "ó");
        break;
    case 147:
        strcpy(character, "ô");
        break;
    case 163:
        strcpy(character, "ú");
        break;
    case 228:
        strcpy(character, "õ");
        break;

    default:
        break;
    }

    return character;
}

int addLeftZeros(char *binInput, char *output)
{

    char bin[9] = {0x00};
    char aux[9] = {0x00};
    int i = 0;
    int j = 0;

    strcpy(bin, binInput);

    if (strlen(bin) < 8)
    {
        i = 8 - strlen(bin);
        for (j = 0; i > 0; i--, j++)
        {
            aux[j] = '0';
        }
    }
    strcat(aux, bin);

    strcpy(output, aux);
}

char binaryToCharacter(char *binInput)
{

    char bin[9] = {0x00};
    int binValue = 0;
    int i = 0;
    int exponent = 7;
    char character = '0';

    addLeftZeros(binInput, bin);

    i = 0;
    while (bin[i] != 0 && bin[i] != '\0')
    {
        if (bin[i] == '1')
        {
            binValue += pow(2, exponent);
        }
        exponent--;
        i++;
    }

    character = getCharByAscii(binValue);

    printf(">> %c ::\n", character);

    return 0;
}

int main(void)
{

    int rc = 0;
    char character = '0';
    char binaryText[1024] = {0x00};

    // rc = textToBinary("Olá Marilene!", binaryText, false);
    rc = binaryToCharacter("01000001");

    return 0;
}