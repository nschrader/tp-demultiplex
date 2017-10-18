/**
 * @file
 *
 */

#ifndef INPUT_H
#define INPUT_H value

#include <stdbool.h>

#include "demultiplex.h"

typedef struct {
  int stream;
  char data[TAILLE_MAX_TRAME]; //Null terminated
  int checksum;
} InputFrame;

InputFrame processInput(char *string);
bool checkInput(InputFrame in);

#endif
