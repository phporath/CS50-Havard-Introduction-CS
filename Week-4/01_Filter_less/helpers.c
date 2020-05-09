#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float rgbGray;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // averages the color intensity and then applies the same value to all the colors to get gray
            rgbGray = round((image[j][i].rgbtRed + image[j][i].rgbtGreen + image[j][i].rgbtBlue) / 3.000);

            image[j][i].rgbtRed = rgbGray;
            image[j][i].rgbtGreen = rgbGray;
            image[j][i].rgbtBlue = rgbGray;
        }
    }
}

// stops max value at 255 preventing overflow
int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sepiaRed = limit(round(0.393 * image[j][i].rgbtRed + 0.769 * image[j][i].rgbtGreen + 0.189 * image[j][i].rgbtBlue));
            sepiaGreen = limit(round(0.349 * image[j][i].rgbtRed + 0.686 * image[j][i].rgbtGreen + 0.168 * image[j][i].rgbtBlue));
            sepiaBlue = limit(round(0.272 * image[j][i].rgbtRed + 0.534 * image[j][i].rgbtGreen + 0.131 * image[j][i].rgbtBlue));

            image[j][i].rgbtRed = sepiaRed;
            image[j][i].rgbtGreen = sepiaGreen;
            image[j][i].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    // Use of a temporary array to swap values
    int temp[3];

    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width / 2; i++)
        {
            temp[0] = image[j][i].rgbtRed;
            temp[1] = image[j][i].rgbtGreen;
            temp[2] = image[j][i].rgbtBlue;

            // swap pixels with the ones on the opposite side of the picture and viceversa
            // the number "1" is used because last position of one array is the length of array minus 1.
            image[j][i].rgbtRed = image[j][width - i - 1].rgbtRed;
            image[j][i].rgbtGreen = image[j][width - i - 1].rgbtGreen;
            image[j][i].rgbtBlue = image[j][width - i - 1].rgbtBlue;

            image[j][width - i - 1].rgbtRed = temp[0];
            image[j][width - i - 1].rgbtGreen = temp[1];
            image[j][width - i - 1].rgbtBlue = temp[2];
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sumBlue, sumGreen, sumRed;
    float counter;
    
    // Create a temporary table of colors to not alter the calculations
    RGBTRIPLE temp[height][width];
    
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sumRed = 0;
            sumGreen = 0;
            sumBlue = 0;
            counter = 0.00;
        
            // sums values of the pixel and 8 neighboring ones, skips iteration if it goes outside the pic
            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }
                
                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }
                    
                    sumRed += image[j + k][i + h].rgbtRed;
                    sumGreen += image[j + k][i + h].rgbtGreen;
                    sumBlue += image[j + k][i + h].rgbtBlue;
                    counter++;
                }
            }
    
            // averages the sum to make picture look blurrier
            temp[j][i].rgbtBlue = round(sumBlue / counter);
            temp[j][i].rgbtGreen = round(sumGreen / counter);
            temp[j][i].rgbtRed = round(sumRed / counter);
        }
    }
    
    // copies values from temporary table
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
        }
    }
}
