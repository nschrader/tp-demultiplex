#include <stdio.h>
#include <stdlib.h>

#include "demultiplex.h"

static void summary() {
  printf("Reading from: \t%s\n", INPUT_FILE);
  printf("Writing to: \t%sN\n", OUTPUT_FILE);
  printf("Rejecting to: \t%s\n", REJECT_FILE);
  printf("\n\n");
}

int main() {
  summary();

  return EXIT_SUCCESS;
}
