#include <stdio.h>
#include <cs50.h>

int main(void)
{
    const int twenty_five = 25;
    const int ten = 10;
    const int five = 5;
    const int one = 1;
    
    int amount;
    do
    {
        amount = get_int("Change Owed: ");
    } while (amount < 1);

    int coins = 0;

    while (amount > 0)
    {
        if (amount - twenty_five >= 0)
        {
            amount -= twenty_five;
        } else if (amount - ten >= 0)
        {
            amount -= ten;
        } else if (amount - five >= 0)
        {
            amount -= five;
        } else {
            amount -= one;
        }
        
        coins++;
    }
    
    printf("%i\n", coins);
    
}