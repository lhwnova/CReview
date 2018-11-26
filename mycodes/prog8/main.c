
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "file.h"
#include "vector.h"
#include "search.h"


int main(int argc, char const *argv[])
{
	
  int individualCount, familyCount;
  Individual *individuals;
  Family *families;

  FILE *fp;
  
  if(argc != 2){
  	printf("Usage: family.out <ged_filename>\n");
  	return 1;
  }

  fp = count_records(argv[1], &familyCount, &individualCount);
  
  initialize(&individuals, &families, familyCount, individualCount);

  read_file(fp, families, individuals);
  //printf("finally\n");
 
  // for(int i = 0; i < individualCount; i++){
  //   printf(">>%s\n", individuals[i].INDI);
  //   //printf(">>%s\n", individuals[i].name);
  // }

  // for(int i = 0; i < familyCount; i++){
  //   printf(">>%s\n", families[i].FAM);
  //   //printf(">>%s\n", childIDs[i]);
  // }
  
  qsort(individuals, individualCount, sizeof(Individual), individual_cmp);
  qsort(families, familyCount, sizeof(Family), family_cmp);
  //find_children(individual_count, family_count, individuals, families);

  deallocate(individuals, families, familyCount, individualCount);

  //printf("here\n"); 
  printf("%d <> %d\n", familyCount, individualCount);


  fclose(fp);
  return 0;
}