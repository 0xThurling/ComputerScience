#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int price;
    string name;
} snack;

int main(void)
{
    snack snacks[3];
    snacks[0].name = "Cookies";
    snacks[0].price = 10;
    snacks[1].name = "Fanta";
    snacks[1].price = 9;
    snacks[2].name = "Burger";
    snacks[2].price = 15;

    string item = get_string("Enter a snack: ");

    bool exists = false;

    for (int i = 0; i < 3; i++)
    {
        if(!strcmp(snacks[i].name, item)){
            printf("Total cost: %i\n", snacks[i].price);
            exists = true;
            break;
        }
    }
    if (!exists)
    {
        printf("Invalid Item!\n");    
    }

    
}