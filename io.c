#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "io.h"
#include "demultiplex.h"
#include "log.h"
#include "output.h"

#define TAILLE_MAX_TRAME  64
#define HEADER_FOOTER 2
#define SIZE_MAXI TAILLE_MAX_TRAME+HEADER_FOOTER

static bool isOpened;
static FILE* outputFiles[MAX_NB_FIC];
static FILE* inputFile;
static FILE* rejectFile;

static void stopIO()
{
  fclose(inputFile);
  fclose(rejectFile);

  for(int i=0; i<MAX_NB_FIC; i++)
  {
    fclose(outputFiles[i]);
  }
}

static void openFiles()
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
    atexit(&stopIO);
  }
}

char* readFrame()
{
  static char buffer[SIZE_MAXI];
  openFiles();

  while (!feof(inputFile))
  {
    logRead();
    fgets(buffer, SIZE_MAXI, inputFile);
  }

  return buffer;
}

void writeFrame(OutputFrame frame, int stream)
{
  openFiles();
  logWrite(stream);
  fprintf(outputFiles[stream], "%s%d\n", frame.data, frame.size);
}

void rejectFrame(char* c)
{
  openFiles();
  logReject();
  fprintf(rejectFile, "%s\n", c);
}

bool isEndOfInput()
{
  openFiles();
  return feof(inputFile);
}
