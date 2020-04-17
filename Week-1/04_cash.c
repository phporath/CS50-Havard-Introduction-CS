#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: "); //receive values in dollar
    }
    while (dollars <= 0);
    int cents = round(dollars * 100); //multiplies dollars by 100
    //printf("%i",cents);

    int coins = 0;
    int restCents = cents;
    while (restCents >= 25) //test if can be used 25 cents.
    {
        restCents = restCents - 25;
        coins ++;
    }
    
    while (restCents >= 10) //test if can be used 10 cents.
    {
        restCents = restCents - 10;
        coins ++;
    }

    while (restCents >= 5) //test if can be used 5 cents.
    {
        restCents = restCents - 5;
        coins ++;
    }

    while (restCents >= 1) //test if can be used 1 cents.
    {
        restCents = restCents - 1;
        coins ++;
    }

    printf("Total Coins: %i\n", coins); // print the total numbers of used coins
}
