#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

void getCypher(string, int);
bool isLetter(char);
void placesToPush(int, int, int, int);
int main(int argc, string argv[])
{

    if (argc < 2 || argc > 2)
    {
        return 1;
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("input :");
    printf("ciphertext: ");
    getCypher(plaintext, key);

}

void getCypher(string plaintext, int key)
{
    if (key > 26)
    {
        key = key % 26;
    }
    int length = strlen(plaintext);

    for (int i = 0; i < length; i++)
    {
        if (isLetter(plaintext[i]))

        {
            if (plaintext[i] + key > 90 && plaintext[i] + key % 26 < 97)

            {
                placesToPush(plaintext[i], 90, 65, key);
            }

            else if (plaintext[i] + key > 122)

            {
                placesToPush(plaintext[i], 122, 97, key);
            }

            else

            {
                printf("%c", plaintext[i] + key);
            }
        }

        else

        {
            printf("%c", plaintext[i]);
        }

    }
    printf("\n");
}

bool isLetter(char letter)
{
    return ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'));
}

void placesToPush(int letter, int end, int start, int key)
{
    int pushWith = letter + key - end - 1;
    letter = start;
    printf("%c", letter + pushWith);
}
