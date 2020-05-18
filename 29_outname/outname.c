#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  char *Outname=malloc((strlen(inputName)+8)*sizeof(*Outname));
  if(inputName==NULL)
    return NULL;
  strcpy(Outname,inputName);
  strcat(Outname,".counts");
  return Outname;
}
