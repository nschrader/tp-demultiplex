#define _GNU_SOURCE // We need memccpy form X/Open                 
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "output.h"

static int calculateNumberOfOutputFrames(InputFrame* in) {
  int n = strlen(in->data) / DATA_SIZE;
  n += (strlen(in->data) % DATA_SIZE) ? 1 : 0;
  return n;
}

static int copyDataToOutputFrameAndFill(char* data, OutputFrame *out) {
  char* after0 = memccpy(out->data, data, '\0',DATA_SIZE);
  out->data[DATA_SIZE] = '\0';
  if (after0 == NULL) {
    return DATA_SIZE;
  } else {
    int copied = after0 - out->data;
    memset(after0, '\0', DATA_SIZE - copied);
    return copied;
  }
}

void processOutput(InputFrame *in, OutputFrame** out, int* n) {
  *n = calculateNumberOfOutputFrames(in);
  *out = malloc(*n * sizeof(OutputFrame));

  for (int i = 0; i < *n; i++) {
    out[i]->size = copyDataToOutputFrameAndFill(in->data, out[i]);
    out[i]->stream = in->stream;
  }
}
