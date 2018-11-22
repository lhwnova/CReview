// Author: 

#ifndef VECTORS_H
#define	VECTORS_H

#define ID_SIZE 20
#define SPOUSES_SIZE 40

void deallocate(char **indiIDs, char **names, char **spousesIDs, 
  char **childIDs, int individual_count, int family_count);

void initialize(char ***indiIDs, char ***names, char ***spousesIDs, 
  char ***childIDs, int individual_count, int family_count, Individual **individuals, Family **families);

#endif	

