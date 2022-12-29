#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    long card;
    do
    {
        card = get_long("Number: ");
    } while (card < 1);
    
    char num[256];
    sprintf(num, "%ld", card);
    int card_length = strlen(num);

    char final[256] = "";
    for (int i = card_length - 2; i >= 0; i -= 2)
    {
        char *str = malloc(sizeof(char));
        *str = num[i];
        int x = atoi(str);
        char temp[256];
        sprintf(temp, "%d", x * 2);
        strcat(final, temp);
    }

    int addedNum = 0;
    for (int i = 0; i < strlen(final); i++)
    {
        char *str = malloc(sizeof(char));
        *str = final[i];
        int x = atoi(str);
        addedNum += x;
    }

    int addFinal = 0;
    for (int i = card_length - 1; i >= 0; i -= 2)
    {
        char *str = malloc(sizeof(char));
        *str = num[i];
        int x = atoi(str);
        addFinal += x;
    }
    
    int finalNum = addedNum + addFinal;

    if (finalNum % 10 != 0)
    {
        printf("Invalid!");
    } else
    {
        if (num[0] == '4')
        {
            printf("VISA");
        } else if (num[0] == '3' && (num[1] == '4' || num[1] == '7'))
        {
            printf("AMEX");
        }
        else
        {
            printf("MASTERCARD");
        }
    }
    
    
    printf("\n");
}