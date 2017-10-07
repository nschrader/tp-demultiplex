#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>

#include "input.h"
#include "output.h"

char* readFrame();
void writeFrames(OutputFrame* frames, int n);
void rejectFrame(char* c);
bool isEndOfInput();

#endif
