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
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    int len = strlen(argv[1]); // global variable for len of argv[1]
    
    // check if the key has 26 characters.
    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    
    // checks    
    for (int i = 0; i < len; i++)
    {
        // check if just have letters at the key.
        if (isalpha(argv[1][i]) == false)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        
        // check if letters appears exactly once
        int uniqueChars = 0;
        char n = argv[1][i];
        for (int j = 0; j < len; j++)
        {
            if (n == argv[1][j])
            {
                uniqueChars = uniqueChars + 1;
            }
        }
        if (uniqueChars > 1)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    
    // original key
    char originalKey[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    // prompt user for a code to encrypt
    string code = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(code); i++)
    {
        char character = code[i]; // identify the character [i] into a loop
        
        if (isalpha(character)) // identify just letters
        {
            for (int j = 0; j < len; j++) //len = strlen(argv[1])
            {
                if (islower(character))
                {
                    if (character == tolower(originalKey[j])) // transform the char of originalKey[j] in a lower case
                    {
                        char cipher = tolower(argv[1][j]); // transform the char of the key[j] in a lower case
                        printf("%c", cipher);
                    }
                }
                    
                else if (isupper(character))
                {
                    if (character == toupper(originalKey[j])) // transform the char of originalKey[j] in a uuper case
                    {
                        char cipher = toupper(argv[1][j]); // transform the char of the key[j] in a upper case
                        printf("%c", cipher);
                    }
                }
            }
        }
        else
        {
            char cipher = character; // others characters such as " ,!.?" should be exactily the same
            printf("%c", cipher);
        }
    }
    printf("\n");
    return 0;
}