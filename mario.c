#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //initialize height variable
    int height;
    //get height with do while
    do
    {
        height = get_int("Specify the height of your pyramide: \n");
    }
    while (height > 23 || height < 0)
    //first loop to iterate over all rows
    for (int i = 0; i < height; i++)
    {
        //second loop nested inside a row to calculate white spaces
        for (int j = i; j < height - 1; j++)
        {
            //print white spaces
            printf(" ");
        }
        //third loop nested inside a row to calculate number of hashes
        for (int k = i + 2; k > 0; k--)
        {
            //print hashes
            printf("#");
        }
        //print linebreak
        printf("\n");
    }
}
