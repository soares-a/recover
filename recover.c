#include <stdio.h>
#include <stdlib.h>

// Defines the size of the buffer for reading blocks
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Checks that exactly one command line argument was provided
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s image\n", argv[0]);
        return 1;
    }

    // Open the forensic image file for reading
    FILE *forensic_image = fopen(argv[1], "r");
    if (forensic_image == NULL)
    {
        fprintf(stderr, "Could not open forensic image %s.\n", argv[1]);
        return 1;
    }

    // Variables for controlling JPEG files
    FILE *jpeg = NULL;
    char filename[8];
    unsigned char buffer[BLOCK_SIZE];
    int jpeg_count = 0;

    // Steps through the forensic image in blocks
    while (fread(buffer, BLOCK_SIZE, 1, forensic_image))
    {
        // Checks if the block starts with the signature of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            // Closes the previous JPEG file (if open)
            if (jpeg != NULL)
            {
                fclose(jpeg);
            }

            // Create a new file JPEG
            sprintf(filename, "%03i.jpg", jpeg_count);
            jpeg = fopen(filename, "w");
            jpeg_count++;
        }

        // If writing to a JPEG file, write the block to the file
        if (jpeg != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, jpeg);
        }
    }

    // Closes the last JPEG file (if open)
    if (jpeg != NULL)
    {
        fclose(jpeg);
    }

    // Close the forensic image file
    fclose(forensic_image);

    return 0;
}
