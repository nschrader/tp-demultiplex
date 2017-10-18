/**
 * @file
 * Contient les méthodes de traitement des paquets entrants
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>

#include "input.h"
#include "output.h"

/**
 * Lecture de la trame dans le fichier d'entrée
 * @returns La trame lue en tant que chaine de caractères
 */
char* readFrame();

/**
 * Ecriture des trames dans les fichiers sortants
 */
void writeFrames(OutputFrame* frames, int n);

/**
 * Rejetter les trames invalides
 */
void rejectFrame(char* c);

bool isEndOfInput();

#endif
