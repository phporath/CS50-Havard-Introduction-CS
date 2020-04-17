#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long nuCard; // credit card number
    nuCard = get_long("Insert a number: ");
    
    long rest, quotient = nuCard;
    int i = 1; // iterate along the credit card numbers
    int a = 0, b = 0, c = 0, a1 = 0, a2 = 0;
    
    while (quotient != 0) // this is necessary to take the numbers in a separate way
    {
        rest = quotient % 10; // take the rest of the division
        quotient = quotient / 10; // take the quocient of the division
        
        if (i % 2 == 0) // identifies with a number is pair or impair
        {
            a = rest * 2; // pair's numbers are multiplied by 2 
            if (a > 9) // if the result is bigger than 9, it's necessary to separate the lengthCard. Ex: 12 = 1 + 2
            {
                a1 = a % 10;
                a2 = a / 10;
                a = a1 + a2;
            }
            b = b + a;
            i++;
        }
        else
        {
            c = c + rest;
            i++;
        }
    }
    
    int sum = b + c; // sum of the numbers' credit card
    int checkSum = sum % 10; // checking Luhn's algorithm
    if (checkSum == 0)
    {
        int lengthCard = i - 1; // identifies the number of digits of the card
        int nuStart = nuCard / pow(10, lengthCard - 2); // identifies the two first numbers of the card
        int nuStart2 = nuCard / pow(10, lengthCard - 1); // identifies the first number of the card
        switch (lengthCard)
        {
            case 15: // rules for American Express
                if (nuStart == 34 || nuStart == 37)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;

            case 16: // rules for Mastercard and Visa
                if (nuStart == 51 || nuStart == 52 || nuStart == 53 || nuStart == 54 || nuStart == 55)
                {
                    printf("MASTERCARD\n");
                }
                else if (nuStart2 == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;

            case 13: // rules for Visa
                if (nuStart2 == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;

            default:
                printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
