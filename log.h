/**
 * @file
 * Routines pour le carnet de route
 */

#ifndef LOG_H
#define LOG_H

/**
 * Enregister le rejet d'une trame
 */
void logReject();

/**
 * Enregister l'écriture d'une trame sortante
 * @param stream
 * Numéro du flux sortant dans lequel la trame était écrite
 */
void logWrite(int stream);

/**
 * Enregister la lecure d'une trame
 */
void logRead();

/**
 * Afficher les statistiques
 */
void report();

#endif
