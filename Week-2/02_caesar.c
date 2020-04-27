# include <cs50.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>

int main(int argc, string argv[])
{
    // check if the arguments are respected, in this case only 2.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // store length of the key
    int len = strlen(argv[1]);

    // Loop that checks each digit to see if it's a number behind "isdigit" function
    for (int i = 0; i < len; i++)
    {
        if (isdigit(argv[1][i]) == false)
        {
            printf("Usage: ./caesar key (but just numbers)\n");
            return 1;
        }
    }

    // transform strings in integer values
    int k = atoi(argv[1]);

    // check if the integer is non-negative
    if (k < 0)
    {
        printf("Usage: ./caesar key (just integer and non-negative values\n");
        return 1;
    }
    else
    {
        // prompt user for a code to encrypt
        string code = get_string("plaintext: ");
        
        printf("ciphertext: ");
        for (int i = 0, n = strlen(code); i < n; i++)
        {
            //check if the letter is uppercase or lowercase then convert
            if (islower(code[i]))
            {
                char character = (((code[i] + k) - 97) % 26) + 97; // if the number code[i]+k > 122 the rest of division will restart the count.
                printf("%c", character);
            }
            else if (isupper(code[i]))
            {
                char character = (((code[i] + k) - 65) % 26) + 65; // if the number code[i]+k > 90 the rest of division will restart the count.
                printf("%c", character);
            }
            //if neither then just print whatever it is
            else
            {
                char character = code[i];
                printf("%c", character);
            }
        }
        printf("\n");
        return 0;
    }
}