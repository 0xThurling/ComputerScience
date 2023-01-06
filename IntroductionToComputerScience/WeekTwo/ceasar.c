#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[]){
    string plain_text = get_string("plaintext:  ");

    int key = atoi(argv[1]);
    int max_range_capital = 90;
    int min_range_capital = 65;
    int max_range_lower = 122;
    int min_range_lower = 97;

    int move;
    if (key > 26)
    {
        move = key % 26;
    }

    for (int i = 0; i < strlen(plain_text); i++)
    {
        if (islower(plain_text[i]) && ((int)plain_text[i] + key) > max_range_lower)
        {
            plain_text[i] = (min_range_lower - 1) + ((int)plain_text[i] + key) - max_range_lower;
        } else if (islower(plain_text[i]))
        {
            plain_text[i] = plain_text[i] + key;
        }
        
        

        if (isupper(plain_text[i]) && ((int)plain_text[i] + key) > max_range_capital)
        {
            plain_text[i] = (min_range_capital - 1) + ((int)plain_text[i] + key) - max_range_capital;
        } else if (isupper(plain_text[i]))
        {
            plain_text[i] = plain_text[i] + key;
        }
        
    }
    printf("ciphertext: %s\n", plain_text);
}