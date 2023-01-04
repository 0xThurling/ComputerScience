#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

bool check_password(string password);

int main(int argc, string argv[])
{
    bool isCorrect;
    if (argc == 1)
    {
        printf("No argument given\n");
        return 1;
    } else {
        isCorrect = check_password(argv[1]);
    }

    if (isCorrect)
    {
        printf("Your password is valid.");
    } else {
        printf("You password needs at least one uppercase letter, lowercase letter, number and symbol.");
    }
    printf("\n");
}

bool check_password(string password)
{
    bool has_upper = false;
    bool has_lower = false;
    bool has_number = false;
    bool has_symbol = false;

    for (int i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            has_number = true;
        } else if (islower(password[i]))
        {
            has_lower = true;
        } else if (isupper(password[i]))
        {
            has_upper = true;
        } else if (ispunct(password[i]))
        {
            has_symbol = true;
        }
    }
    
    return has_lower && has_number && has_symbol && has_upper;  
}