#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char* convert_to_binary(int value);
void print_bulb(string word, int array_length);

int main(void)
{
    string on = "🟡";
    string off = "⚫";

    string message = get_string("Message: ");

    int char_value[strlen(message)];
    for (int i = 0; i < strlen(message); i++)
    {
        char_value[i] = message[i];
    }

    string binary[strlen(message)];
    for (int i = 0; i < strlen(message); i++)
    {
        binary[i] = convert_to_binary(char_value[i]);
    }
    
    for (int i = 0; i < strlen(message); i++)
    {
        print_bulb(binary[i], strlen(message));
    }
    printf("\n");
}

void print_bulb(string word, int array_length)
{
    string on = "🟡";
    string off = "⚫";

    for (int j = 0; j < 8; j++)
    {
        if (word[j]=='0')
        {
            printf("%s", off);
        } else if (word[j]=='1')
        {
            printf("%s", on);
        }
    }
    printf("\n");
}

char *convert_to_binary(int value){
    char* bits = malloc(8);

    int temp = value;
    for (int i = 7; i >= 0; i--)
    {
        if (temp % 2 == 0)
        {
            bits[i] = '0';
        } else
        {
            bits[i] = '1';
        }
        temp /= 2;
    }

    return bits;
}