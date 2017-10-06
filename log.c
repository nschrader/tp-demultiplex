#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "demultiplex.h"
#include "log.h"

static int inputFramesCount;
static int rejectedFramesCount;
static int outputFramesCount[MAX_NB_FIC];
static bool isInited = false;

static void initLog() {
  if (!isInited) {
    memset(outputFramesCount, 0, MAX_NB_FIC);
    inputFramesCount = 0;
    rejectedFramesCount = 0;
  }
  isInited = true;
}

static int sumUpCounters() {
  int sum = inputFramesCount;
  for (size_t i = 0; i < MAX_NB_FIC; i++) {
    sum += outputFramesCount[i];
  }
  return sum;
}

void logReject() {
  initLog();
  rejectedFramesCount++;
}

void logWrite(int stream) {
  initLog();
  outputFramesCount[stream]++;
}

void logRead() {
  initLog();
  inputFramesCount++;
}

void report() {
  initLog();
  assert(sumUpCounters() == rejectedFramesCount);
  printf("------------REPORT------------\n");
  printf("Frames read: \t%d\n", inputFramesCount);
  printf("Frames rejected: \t%d\n", rejectedFramesCount);
  printf("Frames written: \t%d\n", outputFramesCount);
  printf("------------------------------\n");
}
