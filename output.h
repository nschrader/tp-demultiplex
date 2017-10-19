/**
 * @file
 * Création et traitement des données sortantes
 */

#ifndef OUTPUT_H
#define OUTPUT_H

#include "input.h"

/**
 * Nombre de octets de données dans chaque trame sortante
 */
#define DATA_SIZE 7

/**
 * Un seul octet nul
 */
#define A_NULL_BYTE 1

/**
 * @struct OutputFrame
 * Représentation d'une trame dans le format sortant
 *
 * @var OutputFrame::stream
 * Numéro du flux sortant
 * @var OutputFrame::data
 * Données utiles de la trame, terminé par un octet nul
 * @var OutputFrame::size
 * Taille des données utiles dans @ref data
 */
typedef struct {
  int stream;
  char data[DATA_SIZE + A_NULL_BYTE];
  int size;
} OutputFrame;

/**
 * Traitement des trames entrantes et création de la repŕesentation sortante.
 * Le resultat sera écrit dans out et se trouve dans un emplacement static.
 *
 * @param in
 * Trame entrante
 * @param out
 * Pointeur sur le tableau des trames sortantes
 * @param n
 * Pointeur sur le nombre des trames sortantes
 */
void processOutput(InputFrame* in, OutputFrame** out, int* n);

#endif
