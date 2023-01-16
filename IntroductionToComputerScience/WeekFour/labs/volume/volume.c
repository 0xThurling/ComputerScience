// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    uint8_t header[HEADER_SIZE];
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);


    fseek(input, 0, SEEK_END);
    int size = ftell(input);
    fseek(input, 0L, SEEK_SET);
    
    int file = 0;
    for (int i = 0; i < HEADER_SIZE; i++)
    {
        fread(&header[i], sizeof(uint8_t), 1, input);
        fwrite(&header[i], sizeof(uint8_t), 1, output);
    }

    uint16_t buffer;
    for (int i = 0; i < size; i++)
    {
        fread(&buffer, sizeof(uint8_t), 1, input);

        uint16_t *bufferFactor = &buffer;
        *bufferFactor *= factor;
        
        
        fwrite(bufferFactor, sizeof(uint8_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
