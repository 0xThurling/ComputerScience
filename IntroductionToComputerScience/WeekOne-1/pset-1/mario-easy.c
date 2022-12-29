#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = get_int("Height: ");

    // For a height of n print verticle bricks
    for (int i = 0; i < height; i++)
    {
        for (int j = height - 1; j >= 0; j--)
        {
            if (j > i)
            {
                printf(" ");
            } else
            {
                printf("#");
            }
        }
        
        printf("\n");
    }
    

}