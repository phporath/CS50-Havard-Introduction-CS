#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512 // constant called BLOCK_SIZE with 512 bytes

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Ensure only one argument
    if (argc != 2)
    {
        /*stderr can be used as an argument for any function that takes
        an argument of type FILE* expecting an output stream, like fputs or fprintf*/
        fprintf(stderr, "Usage: recover image\n"); // fprintf (file print f)
        return 1;
    }
    
    // to keep filenames
    char *inputFile = argv[1];
    
    // open input file
    FILE *inptr = fopen(inputFile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", inputFile);
        return 2;
    }
    
    BYTE buffer[512];
    int rasterCount = 0;
    
    char filename[8];
    FILE *outptr = NULL;
    
    while (true)
    {
        // read a block of the memory card image
        size_t bytesRead = fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr);
        
        // break out of the loop when reach the end of the card image
        if (bytesRead == 0 && feof(inptr))
        {
            break;
        }
        
        // check if we found a JPEG
        bool containsJpegHeader = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
        
        // if we found a yet another JPEG, we must close the previous file
        if (containsJpegHeader && outptr != NULL)
        {
            fclose(outptr);
            rasterCount++;
        }
        
        // if a JPEG was found, it's necessary to open the file for writing
        if (containsJpegHeader)
        {
            sprintf(filename, "%03i.jpg", rasterCount);
            outptr = fopen(filename, "w");
        }
        
        // write anytime we have an open file
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE), bytesRead, outptr);
        }
    }
    
    // the last jpeg file should be closed
    fclose(outptr);

    // the last inputFile file should be closedclose
    fclose(inptr);

    return 0;
}
