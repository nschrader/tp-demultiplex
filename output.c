#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "output.h"

#define MAX_OUTPUT_FRAMES 10

static int calculateNumberOfOutputFrames(InputFrame* in) {
  int n = strlen(in->data) / DATA_SIZE;
  n += (strlen(in->data) % DATA_SIZE) ? 1 : 0;
  return n;
}

static int copyDataToOutputFrameAndFill(char* data, OutputFrame *out) {
  int len = strlen(data) + 1;
  size_t n = (len < DATA_SIZE) ? len : DATA_SIZE;
  char* after0 = memccpy(out->data, data, '\0', n);
  out->data[DATA_SIZE] = '\0';
  if (after0 == NULL) {
    return DATA_SIZE;
  } else {
    int copied = after0 - out->data - 1;
    memset(--after0, '?', DATA_SIZE - copied);
    return copied;
  }
}

void processOutput(InputFrame *in, OutputFrame** out, int* n) {
  char* pData = in->data;
  static OutputFrame _out[MAX_OUTPUT_FRAMES];

  *n = calculateNumberOfOutputFrames(in);
  *out = _out;

  for (int i = 0; i < *n; i++) {
    int sizeData = copyDataToOutputFrameAndFill(pData, &_out[i]);
    _out[i].size = sizeData;
    pData += sizeData;
    _out[i].stream = in->stream;
  }
}
