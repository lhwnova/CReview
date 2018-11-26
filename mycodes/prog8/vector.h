
#ifndef VECTOR_H
#define VECTOR_H

#include "main.h"

#define ID_SIZE 20
#define SPOUSES_SIZE 40


void initialize(Individual **individuals, Family **families, int famCount, int indCount);
void deallocate(Individual *individuals, Family *families, int famCount, int indCount);



#endif