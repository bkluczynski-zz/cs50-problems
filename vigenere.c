#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool isLetter(char);
char placesToPush(int, int, int, int);
int letterToNumber(char);
char getCypheredLetter(char, int);
string keyHolder(string, string);
int main(int argc, string argv[])
{
    string key = argv[1];

    if (argc != 2)
    {
        printf("Exiting the program");
        return 1;
    }

    for (int p = 0; p< strlen(key); p++)
    {
        if (!isalpha(key[p]))
        {
            printf("Exiting the program");
            return 1;
        }
    }
    string plaintext = get_string("input :");
    string cipher = keyHolder(plaintext, key);
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", getCypheredLetter(plaintext[i], letterToNumber(cipher[i])));
    }
    printf("\n");

}

char getCypheredLetter(char letter, int key)
{
    if (isLetter(letter))

    {
        if (letter >= 65 && letter <= 90 && letter + key > 90)

        {
            return placesToPush(letter, 90, 65, key);
        }

        else if (letter >= 97 && letter <= 122 && letter + key > 122)

        {
            return placesToPush(letter, 122, 97, key);
        }

        else

        {
            return letter + key;
        }

    }

    else

    {
        return letter;
    }


}


bool isLetter(char letter)
{
    return ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'));
}

char placesToPush(int letter, int end, int start, int key)
{
    int pushWith = letter + key - end - 1;
    letter = start;
    return letter + pushWith;
}

int letterToNumber(char letter)
{
    switch(tolower(letter))
    {
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case 'e': return 4;
        case 'f': return 5;
        case 'g': return 6;
        case 'h': return 7;
        case 'i': return 8;
        case 'j': return 9;
        case 'k': return 10;
        case 'l': return 11;
        case 'm': return 12;
        case 'n': return 13;
        case 'o': return 14;
        case 'p': return 15;
        case 'q': return 16;
        case 'r': return 17;
        case 's': return 18;
        case 't': return 19;
        case 'u': return 20;
        case 'v': return 21;
        case 'w': return 22;
        case 'x': return 23;
        case 'y': return 24;
        case 'z': return 25;
        default: return 0;
    }
}

string keyHolder(string plain, string k)
{
int j = 0;
int x = 0;
char *cypher = NULL;
cypher = calloc(1,1);
int plaintextLength = strlen(plain);
    while ( x < plaintextLength )
    {

        if (!isalpha(plain[x]))
        {
        cypher[x] = ' ';
        cypher[x + 1] = k[j];
        }
        else
        {
            cypher[x] = k[j];
            j++;
        }

        x++;

        if (k[j] == 0)
        {
            j = 0;
        }
    }
    return cypher;
}
