#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>

#include "input.h"
#include "output.h"

char* readFrame();
void writeFrame(OutputFrame data, int index);
void rejectFrame(char* c);
bool isEndOfInput();

#endif
