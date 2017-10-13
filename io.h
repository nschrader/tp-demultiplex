/**
 * Contient les méthodes de traitement des paquets entrants
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
/**
 * Taille maximum de la trame
 */
#define TAILLE_MAX_TRAME 64
#include "input.h"
#include "output.h"

/**
 * Lecture de la trame
 */
char* readFrame();
/**
 * Ecriture des trames dans les fichiers sortants
 */
void writeFrames(OutputFrame* frames, int n);
/**
 * Rejette les trames invalides
 */
void rejectFrame(char* c);
bool isEndOfInput();

#endif
