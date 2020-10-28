#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    if (argc == 2)
    {
        char *infile = argv[1];
        FILE *file = fopen(infile, "r");
        if (file == NULL)
        {
            fprintf(stderr, "Could not open %s.\n", infile);
            return 1;
        }
        //
        unsigned char buffer[512];
        char filename[8];
        int img_num = 0;
        FILE *outfile;
        bool jpeg = false;
        while (fread(buffer, sizeof(buffer), 1, file))
        {
            //
            if (buffer[0] == 0xff &&
                buffer[1] == 0xd8 &&
                buffer[2] == 0xff &&
                (buffer[3] & 0xf0) == 0xe0)
            {
                if (jpeg)
                {
                    fclose(outfile);
                    jpeg = false;
                }
                sprintf(filename, "%03i.jpg", img_num);
                outfile = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, outfile);
                jpeg = true;
                img_num++;
            }
            //
            else
            {
                if (jpeg)
                {
                    fwrite(buffer, sizeof(buffer), 1, outfile);
                }
            }
        }
        fclose(file);
        fclose(outfile);
        return 0;
    }

}
