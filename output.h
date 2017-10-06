#ifndef OUTPUT_H
#define OUTPUT_H

#include "input.h"

#define DATA_SIZE 7+1 //Null terminated

typedef struct {
  int stream;
  char data[DATA_SIZE]; //Null terminated
  int size;
} OutputFrame;

OutputFrame processOutput(InputFrame in);

#endif
