#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int min_value = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE temp = image[i][j];
            min_value = temp.rgbtRed;

            if (temp.rgbtGreen < min_value)
            {
                min_value = temp.rgbtGreen;
            } 
            
            if (temp.rgbtBlue < min_value)
            {
                min_value = temp.rgbtGreen;
            }
             image[i][j].rgbtBlue = min_value;
             image[i][j].rgbtGreen = min_value;
             image[i][j].rgbtRed = min_value;
        }
    }
    
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE temp = image[i][j];
            temp.rgbtRed = (roundf(.393) * image[i][j].rgbtRed) + (roundf(.769) * image[i][j].rgbtGreen) + (roundf(.189) * image[i][j].rgbtBlue);
            temp.rgbtGreen = (roundf(.349) * image[i][j].rgbtRed) + (roundf(.686) * image[i][j].rgbtGreen) + (roundf(.168) * image[i][j].rgbtBlue);
            temp.rgbtBlue = roundf((.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue));

            
            image[i][j].rgbtBlue = temp.rgbtBlue;
            image[i][j].rgbtGreen = temp.rgbtGreen;
            image[i][j].rgbtRed = temp.rgbtRed;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][(width - 1) - j];
            image[i][(width - 1) - j] = temp;
        }
           
    }
    

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
