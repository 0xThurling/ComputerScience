#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    int temperature;
} temp;

void sort_cities(temp temps[]);

int main(void)
{
    temp temperatures[5];
    temperatures[0].temperature = 90;
    temperatures[1].temperature = 89;
    temperatures[2].temperature = 70;
    temperatures[3].temperature = 91;
    temperatures[4].temperature = 95;

    sort_cities(temperatures);

    for (int i = 0; i < 5; i++)
    {
        printf("%i\n", temperatures[i].temperature);
    }
    printf("\n");
}

void sort_cities(temp temps[]){

    
    for (int i = 0; i < 5; i++)
    {
        int min_value = i;
        for (int j = i; j < 5; j++)
        {
            if (temps[j].temperature < temps[min_value].temperature)
            {
                min_value = j;
            }
        }
        
        temp tempo = temps[i];
        temps[i] = temps[min_value];
        temps[min_value] = tempo;
    }
}