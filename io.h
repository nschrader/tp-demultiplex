/**
 * @file
 * Gestion des fichiers d'entrée et de sortie
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>

#include "input.h"
#include "output.h"

/**
 * Lecture de la trame dans le fichier d'entrée
 * @returns La trame lue en tant que chaîne de caractères, emplacement static
 */
char* readFrame();

/**
 * Écriture des trames dans le fichier sortant correspondant
 * @param frames
 * Tableau avec les trames sortantes à écrire
 * @param n
 * Nombre de trames dans le tableau
 */
void writeFrames(OutputFrame* frames, int n);

/**
 * Rejeter une trame invalide
 * @param c
 * Trame invalide
 */
void rejectFrame(char* c);

/**
 * Vérifier si le fichier d'entrée est epuisé
 * @returns true (epuisé), false sinon
 */
bool isEndOfInput();

#endif
