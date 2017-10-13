#include <stdbool.h>
#include <stdlib.h>

#include "input.h"
#include "output.h"

#define DEC 10
#define HEX 16
#define INVALID -1

InputFrame processInput(char *string) {
  
  int len = strlen(string);
  char *err = NULL;

  if (len>3){
      
     InputFrame in = {0};
     in.stream = strtol(&string[0], &err, DEC);
     if(!err) {
         in.stream = INVALID ;
         *err = NULL ;
     }
     in.data = &in._data;
     memcpy(in.data,&string[1],sizeOf(char)*(len-2));
     in.checksum = strtol(&string[len-1], &err, HEX);
     if(!err) {
         in.checksum = INVALID ;
     }
  }

  return in;
}

bool checkInput(InputFrame in) {

    int check = in.checksum ;
    bool verif;

    if ((check%16) == 5){
        verif = true ;
    } else {
        verif = false ;
    }

    return verif
}

