#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "output.h"

#define DEC 10
#define HEX 16
#define INVALID -1

static InputFrame initInputFrame() {
  InputFrame in;
  in.stream = INVALID;
  in.data = NULL;
  in.checksum = INVALID;
  return in;
}

static int processStream(char* string) {
  char* err = NULL;
  char cStream[2] = {string[0], '\0'};
  int stream = strtol(cStream, &err, DEC);
  if (err) {
      stream = INVALID;
  }
  return stream;
}

static int processChecksum(char* string) {
  char* err = NULL;
  char cChecksum[2] = {string[strlen(string)-1], '\0'};
  int checksum = strtol(cChecksum, &err, HEX);
  if (err) {
      checksum = INVALID;
  }
  return checksum;
}

static void processData(char* string, InputFrame* in) {
  in->data = in->_data;
  memcpy(in->data, &string[1], sizeof(char) * (strlen(string)-2));
}

InputFrame processInput(char *string) {
  int len = strlen(string);
  InputFrame in = initInputFrame();

  if (len > 3) {
     in.stream = processStream(string);
     processData(string, &in);
     in.checksum = processChecksum(string);
  }

  return in;
}

bool checkInput(InputFrame in) {
  return true;
}
