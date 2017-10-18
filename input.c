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
  in.data[0] = '\0';
  in.checksum = INVALID;
  return in;
}

static int processStream(char* string) {
  char* err = NULL;
  char cStream[2] = {firstChar(string), '\0'};
  int stream = strtol(cStream, &err, DEC);
  if (*err != '\0') {
      stream = INVALID;
  }
  return stream;
}

static int processChecksum(char* string) {
  char* err = NULL;
  char cChecksum[2] = {lastChar(string), '\0'};
  int checksum = strtol(cChecksum, &err, HEX);
  if (*err != '\0') {
      checksum = INVALID;
  }
  return checksum;
}

static void processData(char* string, InputFrame* in) {
  int len = strlen(string);
  memcpy(in->data, &string[1], sizeof(char) * (len-2));
  in->data[len-2] = '\0';
}

InputFrame processInput(char *string) {
  int len = strlen(string);
  InputFrame in = initInputFrame();

  if (len >= 2) {
     in.stream = processStream(string);
     processData(string, &in);
     in.checksum = processChecksum(string);
  }
  return in;
}

bool checkInput(InputFrame in) {
  bool checksumValid = false;
  if (in.checksum != INVALID) {
    int checksum = strlen(in.data) % 16;
    checksumValid = (checksum == in.checksum);
  }

  bool streamValid = (in.stream != INVALID);
  return streamValid && checksumValid;
}
