
#ifndef VECTOR_H 
#define VECTOR_H

#define ID_SIZE 20 
#define SPOUSE_SIZE 40

void initialize(char ***indIDs, char ***names, char ***spouseIDs, 
	char ***childIDs, int indCount, int famCount);

void deallocate(char **indIDs, char **names, char **spouseIDs, 
	char **childIDs, int indCount, int famCount);


#endif
