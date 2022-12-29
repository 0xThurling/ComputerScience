#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    } while (height < 1);
    
    
    int space = 2;

    // For a height of n print verticle bricks
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (height * 2) + space; j++)
        {
            int jump = height;
            if (j < jump - (i + 1))
            {
                printf(" ");
            }
            else if (j >= jump && (jump + space) > j)
            {
                printf(" ");
            }
            else if (j > (jump + space) + i)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
            
        }
        printf("\n");
    }
    

}