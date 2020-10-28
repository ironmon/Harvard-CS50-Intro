#include "helpers.h"
#include <stdio.h>
# include <math.h>


int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

/**
 * Find minimum between two numbers.
 */
int min(int num1, int num2)
{
    return (num1 > num2 ) ? num2 : num1;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int max_number = 768;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int color_avg = image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen;
            float percentage = (float)color_avg / (float)max_number;
            int gray_color = (int)(percentage * 255) + 1;
            image[i][j].rgbtBlue = gray_color;
            image[i][j].rgbtRed = gray_color;
            image[i][j].rgbtGreen = gray_color;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            float originalBlue = image[i][j].rgbtBlue;
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue) ;
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            sepiaRed = min(sepiaRed, 255);
            sepiaBlue = min(sepiaBlue, 255);
            sepiaGreen = min(sepiaGreen, 255);
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < round(width / 2); j++){
            int temblue = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width-j-1].rgbtBlue;
            image[i][width-j-1].rgbtBlue = temblue;
            int temred = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width-j-1].rgbtRed;
            image[i][width-j-1].rgbtRed = temred;
            int temgreen = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width-j-1].rgbtGreen;
            image[i][width-j-1].rgbtGreen = temgreen;

        }
    }
    return;
}



// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
        for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int left_bound = max(j - 1, 0);
            int right_bound = min(j + 1, width - 1);
            int up_bound = max(i - 1, 0);
            int low_bound = min(i + 1, height - 1);
            int sum_red = 0;
            int sum_blue = 0;
            int sum_green = 0;
            int count = (right_bound - left_bound  + 1) * (low_bound - up_bound + 1);
            for(int k = up_bound; k <= low_bound; k++){
                for(int v = left_bound; v <= right_bound; v++){
                    sum_red = sum_red + image[k][v].rgbtRed;
                    sum_blue = sum_blue + image[k][v].rgbtBlue;
                    sum_green = sum_green + image[k][v].rgbtGreen;
                }
             }
            image[i][j].rgbtBlue = (int)(sum_blue / count);
            image[i][j].rgbtRed = (int)(sum_red / count);
            image[i][j].rgbtGreen = (int)(sum_green / count);

        }
    }
    return;
}

