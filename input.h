/**
 * @file
 * Traitemement des trames entrantes
 */

#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>

#include "demultiplex.h"

/**
 * @struct InputFrame
 * Représentation des trames entrantes
 *
 * @var InputFrame::stream
 * Octet identifiant le flux de sortie
 * @var InputFrame::data
 * Chaîne de caractères terminée par un octet null et
 * contenat les données à transporter
 * @var InputFrame::checksum
 * Checksum calculé par la longeur de @ref data modulo 16
 */
typedef struct {
  int stream;
  char data[TAILLE_MAX_TRAME]; //Null terminated
  int checksum;
} InputFrame;

/**
 * Créer la représentation de la trame entrante
 * @param string
 * Trame entrante comme chaîne de caractères
 * @return @ref InputFrame rempli ou vide en cas d'erreur
 */
InputFrame processInput(char* string);

/**
 * Vérifier si la trame entrante est correcte
 * @param in
 * Trame entrante
 * @return true (correcte), false (incorrecte)
 */
bool checkInput(InputFrame in);

#endif
