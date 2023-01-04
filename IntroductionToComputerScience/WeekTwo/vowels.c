#include <stdio.h>
#include <cs50.h>
#include <string.h>

string replace(string word);
char get_num_char(char character);

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("No Words have been given\n");
    } else
    {
        printf("%s", replace(argv[1]));
    }
    printf("\n");
}

string replace(string word)
{
    string characters = "aeiouAEIOU";

    for (int i = 0; i < strlen(word); i++)
    {
        for (int j = 0; j < strlen(characters); j++)
        {
            if (word[i] == characters[j])
            {
                word[i] = get_num_char(word[i]);
            }
        }
    }
    
    return word;
}

char get_num_char(char character){
    if (character == 'a' || character == 'A')
    {
        return '4';
    }else if (character == 'e' || character == 'E')
    {
        return '3';
    }else if (character == 'i' || character == 'I')
    {
        return '1';
    }else if (character == 'o' || character == 'O')
    {
        return '0';
    }else
    {
        return 'v';
    }
    
    
    
}