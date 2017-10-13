#ifndef INPUT_H
#define INPUT_H value

#include <stdbool.h>

#include "demultiplex.h"

typedef struct {
  int stream;
  char* data; //Null terminated
  char _data[TAILLE_MAX_TRAME]; //Hidden memory allocation
  int checksum;
} InputFrame;

InputFrame processInput(char *string);
bool checkInput(InputFrame in);

#endif
