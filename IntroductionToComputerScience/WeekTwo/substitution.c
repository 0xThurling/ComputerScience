#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[]){
    if (strlen(argv[1]) != 26)
    {
        printf("Please enter 26 characters");
        return 1111;
    }
    string arg = argv[1];

    string plain_text = get_string("plaintext:  ");

    int capital_base = 65;
    int lower_base = 97;

    for (int i = 0; i < strlen(plain_text); i++)
    {
        if (islower(plain_text[i]))
        {
            plain_text[i] = arg[plain_text[i] - lower_base] + 32;
        } else if (isupper(plain_text[i]))
        {
            plain_text[i] = arg[plain_text[i] - capital_base];
        }
    }
    
    printf("ciphertext: %s\n",plain_text);
    
}