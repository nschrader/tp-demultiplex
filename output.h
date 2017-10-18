/**
 * @file
 * Contient les méthodes de création et traitement des données sortantes
 */

#ifndef OUTPUT_H
#define OUTPUT_H

#include "input.h"

/**
 * Nombre de bytes de données
 */
#define DATA_SIZE 7

/**
 * Un seul byte nul
 */
#define A_NULL_BYTE 1

/**
 * @struct OutputFrame
 * Structure contenant les paquets dans le format entrant
 *
 * @var OutputFrame::stream
 * Numero de stream sortant
 */
typedef struct {
  int stream;
  char data[DATA_SIZE + A_NULL_BYTE];
  int size;
} OutputFrame;

/**
 * Traitement paquets entrant et écriture dans les paquets sortants
 */
void processOutput(InputFrame* in, OutputFrame** out, int* n);

#endif
