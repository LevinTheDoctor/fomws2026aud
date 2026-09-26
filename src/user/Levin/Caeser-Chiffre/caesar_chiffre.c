#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

void shiftCharArray(char alphabet[], int shiftNumber, char result[])
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        int newIndex = (i + shiftNumber) % ALPHABET_SIZE;
        result[newIndex] = alphabet[i];
    }
    result[ALPHABET_SIZE] = '\0';
}

int findIndex(char element, char array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int checkForbiddenText(char character, char forbiddenCharacters[], int forbiddenSize)
{
    for (int i = 0; i < forbiddenSize; i++)
    {
        if (character == forbiddenCharacters[i])
        {
            return 1;
        }
    }
    return 0;
}

void changeText(char text[], char alphabet[], char alphabetAltered[],
                char forbiddenCharacters[], int forbiddenSize, char textEncoded[])
{
    int size = strlen(text);

    for (int i = 0; i < size; i++)
    {
        int isCharForbidden = checkForbiddenText(text[i], forbiddenCharacters, forbiddenSize);
        if (isCharForbidden == 1)
        {
            textEncoded[i] = text[i];
        }
        else
        {
            int index = findIndex(text[i], alphabet, ALPHABET_SIZE);
            textEncoded[i] = alphabetAltered[index];
        }
    }
    textEncoded[size] = '\0';
}

void caesarChiffre(char text[], int position, char output[])
{
    int positionClean = position % ALPHABET_SIZE;

    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char forbiddenCharacters[] = " ,.?!";
    int forbiddenSize = strlen(forbiddenCharacters);

    char alphabetAltered[ALPHABET_SIZE + 1];
    shiftCharArray(alphabet, positionClean, alphabetAltered);

    int textLength = strlen(text);
    char textCleaned[textLength + 1];
    for (int i = 0; i < textLength; i++)
    {
        textCleaned[i] = tolower(text[i]);
    }
    textCleaned[textLength] = '\0';

    changeText(textCleaned, alphabet, alphabetAltered, forbiddenCharacters, forbiddenSize, output);
}

int main(void)
{
    char text[] = "Hallo Welt";
    char output[100];

    caesarChiffre(text, 6, output);

    printf("%s\n", output);

    return 0;
}