#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[]){
    string plain_text = get_string("plaintext: ");

    int key = atoi(argv[1]);

    for (int i = 0; i < strlen(plain_text); i++)
    {
        int value = (int)plain_text[i] + key;
        printf("%i", value);
    }
    printf("\n");
}