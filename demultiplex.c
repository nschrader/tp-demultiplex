/**
 * @mainpage
 * Ce programme permet de démultiplexer un fichier de trames réseaux en
 * differents fichiers de paquets.
 *
 * @section Make
 * Pour compiler:
 * @code
 * make main
 * @endcode
 * Pour exécuter:
 * @code
 * make run
 * @endcode
 * Pour générer la documentation:
 * @code
 * make doc
 * @endcode
 * Pour nettoyer:
 * @code
 * make clean
 * @endcode
 * Pour faire tout (sauf nettoyer):
 * @code
 * make all
 * @endcode
 *
 * @section programme Logique du programme:
 * @snippet demultiplex.c main
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

//! [main]
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
//! [main]
