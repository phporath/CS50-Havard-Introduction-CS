# include <cs50.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <math.h>

int main(void)
{
    int letters = 0, words = 1, sentences = 0, spaces = 0; // "words" is initialized with 1 for take the correct numbers of words. 

    string text = get_string("Text: ");
    
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i])) // numbers of letters
        {
            letters = letters + 1;
        }
        else if (isspace(text[i]) && (isalpha(text[i + 1]) || ispunct(text[i + 1]))) // numbers of words
        {
            words = words + 1;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?') // numbers of sentences
        {
            sentences = sentences + 1;
        }
    }

    float l = ((float)letters / (float)(words)) * 100; // l value for Coleman–Liau index
    float s = ((float)sentences / (float)(words)) * 100; // s value for Coleman–Liau index
    float index = 0.0588 * l - 0.296 * s - 15.8; // Coleman–Liau index
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }
}