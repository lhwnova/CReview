// Author: Huan Wei Li

#ifndef VECTOR_H
#define VECTOR_H
#define INDI_SIZE 20
#define FAM_SIZE 40

void initialize(int family_count, int individual_count, char ***indiIDs, 
  char ***names, char ***spousesIDs, char ***childIDs);

void deallocate(char **indiIDs, char **names, char **spousesIDs,
  char **childIDs, int family_count, int individual_count);

#endif

                             
