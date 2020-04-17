#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8); // choose numbers from 1 to 8

    int m = n; // pyramid effect
    
    for (int i = 0; i < n; i++) // print numbers of lines
    {    
        m = m - 1;

        for (int j = 0; j < m; j++) //print left spaces
        {
            printf(" ");
        }

        for (int j = m; j < n; j++) //print left hashes
        {
            printf("#");
        }
        
        printf("\n");
    }
}
