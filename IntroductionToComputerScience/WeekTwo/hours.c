#include <stdio.h>
#include <cs50.h>

float average(int hours[], int weeks);
int total(int hours[], int weeks);

int main(void)
{
    int weeks = get_int("Number of weeks taking cs50: ");
    int hours[weeks];
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i: ", i);
    }

    char choice = get_char("Enter T for total hours, A for average hours per week: ");

    if (choice == 'A')
    {
        printf("Average hours %f\n", average(hours, weeks));
    } else
    {
        printf("Total hours %i\n", total(hours, weeks));
    }
}

float average(int hours[], int weeks)
{
    int total = 0;
    for (int i = 0; i < weeks; i++)
    {
        total += hours[i]; 
    }

    return total / (float) weeks;
}

int total(int hours[], int weeks)
{
    int total = 0;
    for (int i = 0; i < weeks; i++)
    {
        total += hours[i]; 
    }
    return total;
}