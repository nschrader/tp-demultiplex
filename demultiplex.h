/**
 * @file
 * Définitions globales pour le programme
 */

#ifndef DEMULTIPLEX_H
#define DEMULTIPLEX_H

/**
 * Nombre maximal de flux sortants
 */
#define MAX_NB_FIC 5

/**
 * Fichier d'entrée contenant les trames
 */
#define INPUT_FILE "sujet.data"

/**
 * Fichiers de sortie pour les trames valides demultiplexées.
 * Pour chaque flux le fichier est numéroté.
 */
#define OUTPUT_FILES "f"

/**
 * Fichiers de sortie pour les trames invalides non-depultiplexées
 */
#define REJECT_FILE "rejetes.data"

/**
 * Taille maximale d'une trame d'entrée sans compter:
 * - l'octet de destination
 * - l'octet de checksum
 */
#define TAILLE_MAX_TRAME 64

/**
 * Macro pour designer le premier caractère d'une chaîne de caractères
 */
#define firstChar(x) (x[0])

/**
 * Macro pour designer le dernier caractère d'une chaîne de caractères
 */
#define lastChar(x) (x[strlen(x)-1])

#endif
