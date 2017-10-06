#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MAX_TRAME  64
#define HEADER_FOOTER 2
#define SIZE_MAXI TAILLE_MAX_TRAME+HEADER_FOOTER


void read_frame()
{
    FILE *f=NULL;

    char buffer[SIZE_MAXI];
    int i,ch ;

    f=fopen(INPUT_FILE,"r");

    if (f == NULL)
    {
        printf("NO INPUT FILE");
        exit(EXIT_FAILURE);
    }

    else
    {
        while (!feof(f))
        {
            fgets(buffer,SIZE_MAXI,f);
        }
    }

    fclose(f);

    printf("%s\n",buffer);
}
