#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string on = "🟡";
    string off = "⚫";

    string message = get_string("Message: ");

    for (int i = 0; i < strlen(message); i++)
    {
        int char_value = message[i];
        printf("%i\n",char_value);
    }


    
}