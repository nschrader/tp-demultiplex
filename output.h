#ifndef OUTPUT_H
#define OUTPUT_H

#include "input.h"

#define DATA_SIZE 7
#define A_NULL_BYTE 1

typedef struct {
  int stream;
  char data[DATA_SIZE + A_NULL_BYTE];
  int size;
} OutputFrame;

void processOutput(InputFrame* in, OutputFrame** out, int* n);

#endif
