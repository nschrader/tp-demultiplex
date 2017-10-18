/**
 * @mainpage
 * Hi!
 *
 * @see demultiplex.h
 * @see input.h
 * @see output.h
 * @see log.h
 * @see io.h
 */

#include <stdio.h>
#include <stdlib.h>

#include "demultiplex.h"
#include "io.h"
#include "input.h"
#include "output.h"
#include "log.h"

static void summary() {
  printf("Reading from: \t%s\n", INPUT_FILE);
  printf("Writing to: \t%s(0,1,...)\n", OUTPUT_FILES);
  printf("Rejecting to: \t%s\n\n", REJECT_FILE);
}

int main() {
  summary();
  while (!isEndOfInput()) {
    char* frameIn = readFrame();
    if (frameIn == NULL) {
      continue;
    }
    InputFrame in = processInput(frameIn);
    bool isOk = checkInput(in);
    if (!isOk) {
      rejectFrame(frameIn);
    } else {
      OutputFrame* out;
      int outN;
      processOutput(&in, &out, &outN);
      writeFrames(out, outN);
    }
  }
  report();
  return EXIT_SUCCESS;
}
