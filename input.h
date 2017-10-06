#ifndef INPUT_H
#define INPUT_H value

#include <stdbool.h>

typedef struct {
  int stream;
  char* data; //Null terminated
  int checksum;
} InputFrame;

InputFrame processInput(char *string);
bool checkInput(InputFrame in);

#endif
