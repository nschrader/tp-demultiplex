#include <stdio.h>
#include <stdlib.h>

#include "demultiplex.h"
#include "functions.h"
#include "log.h"

static void summary() {
  printf("Reading from: \t%s\n", INPUT_FILE);
  printf("Writing to: \t%sN\n", OUTPUT_FILE);
  printf("Rejecting to: \t%s\n", REJECT_FILE);
  printf("\n\n");
}

int main() {
  summary();
  while (!isEndOfInput()) {
    char* frameIn = readFrame();
    InputFrame in = processInput(frameIn);
    bool isOk = checkInput(in);
    if (!isOk) {
      rejectFrame(frameIn);
    } else {
      OutputFrame out = processOutput(in);
      writeFrame(out, 0);
    }
  }
  report();
  return EXIT_SUCCESS;
}
