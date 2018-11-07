// Author: Sean Davis

#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "vector.h"
#include "search.h"
#include "main.h"


int main(int argc, char **argv)
{
  int individual_count, family_count;
  Individual *individuals;
  Family *families;
  
  FILE *fp;
  
  if(argc != 2)
  {
    printf("Usage: family.out <ged_filname>\n");
    return 1;
  } // if the number of arguments is wrong
  
  fp = count_records(argv[1], &individual_count, &family_count);
  initialize(individual_count, family_count, &individuals, &families);
  read_file(fp, individuals, families);
  qsort(individuals, individual_count, sizeof(Individual), individual_cmp);
  qsort(families, family_count, sizeof(Family), family_cmp);
  find_children(individual_count, family_count, individuals, families);
  deallocate(individual_count,family_count, individuals, families);
  return 0;
} // main()

