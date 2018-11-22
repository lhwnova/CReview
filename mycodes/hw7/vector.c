// Author: Huan Wei Li

#include<stdlib.h>
#include<stdio.h>
#include "vector.h"


void initialize(int family_count, int individual_count,  char ***indiIDs,
  char ***names, char ***spousesIDs, char ***childIDs)
{
  int i;

  //printf("%d    %d\n", individual_count, family_count);

  (*indiIDs) = (char**) malloc(sizeof(char*) * individual_count);
  (*names) = (char**) malloc(sizeof(char*) * individual_count);
  for(i = 0; i < individual_count; i++)
  {
    (*indiIDs)[i] = (char*) malloc(sizeof(char) * 20);   
    (*names)[i] = NULL;
  }  // allocate space 

  (*spousesIDs) = (char**) malloc(sizeof(char*) * family_count);
  (*childIDs) = (char**) malloc(sizeof(char*) * family_count); 
  for(i = 0; i < family_count; i++)
  {
    (*spousesIDs)[i] = (char*) malloc(sizeof(char) * 40);   
    (*spousesIDs)[i][0] = '\0';
    (*childIDs)[i] = NULL;   
  }  // allocate space
}  // initialize()


void deallocate(char **indiIDs, char **names, char **spousesIDs,
  char **childIDs, int family_count, int individual_count)
{
  int i;
  
  for(i = 0; i < individual_count; i++)
  {
    free(indiIDs[i]);
    if(names[i] != NULL) free(names[i]);
  } // frre heap memory
  
  free(indiIDs);
  free(names);

  for(i = 0; i < family_count; i++)
  {
    free(spousesIDs[i]);
    if(childIDs[i] != NULL) free(childIDs[i]);
  }  // free heap memory 

  free(spousesIDs);
  free(childIDs);
}  //deallocate()









