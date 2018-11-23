#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void initialize(char ***indIDs, char ***names, char ***spouseIDs, 
	char ***childIDs, int indCount, int famCount){
  

  //printf("%d <> %d\n", indCount, famCount);

  int i;

  *indIDs = (char**) malloc(indCount * sizeof(char*));
  *names = (char**) malloc(indCount * sizeof(char*));
  *spouseIDs = (char**) malloc(famCount * sizeof(char*));
  *childIDs = (char**) malloc(famCount * sizeof(char*));

  for(i = 0; i < indCount; i++){
    (*indIDs)[i] = (char*) malloc(ID_SIZE*sizeof(char));
    (*names)[i] = NULL;
  }

  for(i = 0; i < famCount; i++){
    (*spouseIDs)[i] = (char*)malloc(SPOUSE_SIZE*sizeof(char)); 
    //(*spouseIDs)[0] = '\0';
    (*childIDs)[i] = NULL;

  }

}


void deallocate(char **indIDs, char **names, char **spouseIDs, 
	char **childIDs, int indCount, int famCount){

 int i;

 for(i = 0; i < indCount; i++){
    free(indIDs[i]); 
    if(names[i])
      free(names[i]);
  }

  for(i = 0; i < famCount; i++){
    free(spouseIDs[i]); 
    if(childIDs[i])
      free(childIDs[i]);
  }

  free(indIDs);
  free(names);
  free(spouseIDs);
  free(childIDs);

}



