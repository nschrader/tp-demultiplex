#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "io.h"
#include "demultiplex.h"
#include "log.h"
#include "output.h"


#define HEADER_FOOTER 2
#define SIZE_MAXI (TAILLE_MAX_TRAME+HEADER_FOOTER)

static bool isOpened;
static FILE* outputFiles[MAX_NB_FIC];
static FILE* inputFile;
static FILE* rejectFile;

static void stopIO() {
  fclose(inputFile);
  fclose(rejectFile);

  for (int i = 0; i<MAX_NB_FIC; i++) {
    fclose(outputFiles[i]);
  }
}

static void openInputFile() {
  inputFile=fopen(INPUT_FILE, "r");
  if (inputFile == NULL) {
    perror("Could not open input file");
    exit(EXIT_FAILURE);
  }
}

static void openRejectFile() {
  rejectFile=fopen(REJECT_FILE, "w");
  if (rejectFile == NULL) {
    perror("Could not open reject file");
    exit(EXIT_FAILURE);
  }
}

static void openOutputFiles() {
  for (int i = 0; i < MAX_NB_FIC; i++)
  {
    char buffer[16];
    sprintf(buffer, "%s%d", OUTPUT_FILES, i);
    outputFiles[i] = fopen(buffer, "w");
    if (outputFiles[i] == NULL) {
      perror("Could not open output file");
      exit(EXIT_FAILURE);
    }
  }
}

static void openFiles() {
  if(!isOpened) {
    openInputFile();
    openRejectFile();
    openOutputFiles();
    atexit(&stopIO);
    isOpened = true;
  }
}

char* readFrame() {
  static char buffer[SIZE_MAXI];
  openFiles();
  logRead();
  char* status = fgets(buffer, SIZE_MAXI, inputFile);
  if (status != NULL) {
    lastChar(buffer) = '\0'; //Get rid of \n
    return buffer;
  } else {
    return NULL;
  }
}

static void writeFrame(OutputFrame* frame) {
  openFiles();
  logWrite(frame->stream);
  fprintf(outputFiles[frame->stream], "%s%d\n", frame->data, frame->size);
}

void writeFrames(OutputFrame* frames, int n) {
  for (int i = 0; i < n; i++) {
    writeFrame(&frames[i]);
  }
}

void rejectFrame(char* c) {
  openFiles();
  logReject();
  fprintf(rejectFile, "%s\n", c);
}

bool isEndOfInput() {
  openFiles();
  return feof(inputFile);
}
