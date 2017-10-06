#include <stdio.h>
#include <stdlib.h>
#include "demultiplex.h"
#include <stdbool.h>

#define TAILLE_MAX_TRAME  64
#define INPUT_FILE "data.sujet"
#define HEADER_FOOTER 2
#define SIZE_MAXI TAILLE_MAX_TRAME+HEADER_FOOTER

static bool isOpened;
static FILE* outputFiles[MAX_NB_FIC];
static FILE* inputFile;
static FILE* rejectFile;

void readFrame()
{
    FILE *f=NULL;
    
    static char buffer[SIZE_MAXI];

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

void writeFrame(outputData data,int index)
{
   openFiles();

   for(int i = 0; i <= DATA_SIZE; i++)
   {
      fputc(outputFiles[index], data.data);
   }
   
   fprintf(outputFiles[index],"%d",data.size);
} 

void openFiles()
{
    if(!isOpened)
    {
       inputFile=fopen(INPUT_FILE,"r+");
       rejectFile=fopen(REJECT_FILE,"r+");

        for(int i=0; i<MAX_NB_FIC; i++)
        {
            char buffer[16];
            sprintf(buffer,"%s%d",OUTPUT_FILE,i);
            outputFiles[i]=fopen(buffer,"r+");
        }
    }
}
  



    
