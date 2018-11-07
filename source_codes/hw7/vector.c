// Author: Sean Davis
#include <stdlib.h>
#include "vector.h"

void deallocate(char **indiIDs, char **names, char **spousesIDs, 
  char **childIDs, int individual_count, int family_count)
{
  int i;
  
  for(i = 0; i < individual_count; i++)
  {
    free(indiIDs[i]);
    if(names[i])
      free(names[i]);
  } // for i
  
  for(i = 0; i < family_count; i++)
  {
    free(spousesIDs[i]);
    
    if(childIDs[i])
      free(childIDs[i]);
  } // for i

  free(indiIDs);
  free(names);
  free(spousesIDs);
  free(childIDs);
} // deallocate


void initialize(char ***indiIDs, char ***names, char ***spousesIDs, 
  char ***childIDs, int individual_count, int family_count)
{
  int i;
  
  *indiIDs = (char**) malloc(individual_count * sizeof(char*));
  *names = (char**) malloc(individual_count * sizeof(char*));
  *spousesIDs = (char**) malloc(family_count * sizeof(char*));
  *childIDs = (char**) malloc(family_count * sizeof(char*));
  
  for(i = 0; i < individual_count; i++)
  {
    (*indiIDs)[i] = (char*) malloc(ID_SIZE);
    (*names)[i] = NULL;
  } // for i
  
  for(i = 0; i < family_count; i++)
  {
    (*spousesIDs)[i] = (char*) malloc(SPOUSES_SIZE);
    (*spousesIDs)[i][0] = '\0';
    (*childIDs)[i] = NULL;
  } // for i
} // initialize()
