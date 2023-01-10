#include <stdio.h>
#include <cs50.h>
#include <string.h>

int max(int arr[], int amt);

int main(void)
{
    int amount = get_int("Number of elements");

    int number[amount];
    
    for (int i = 0; i < amount; i++)
    {
        number[i] = get_int("Element %i: ", i);
    }
    
    int max_value = max(number, amount);

    printf("%i\n", max_value);
}

int max(int arr[], int amt)
{
    int value = 0;

    for (int i = 0; i < amt; i++)
    {
        if (arr[i] > value)
        {
            value = arr[i];
        }
    }
    return value;
}