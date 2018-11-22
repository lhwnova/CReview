// Auhor: Huan Wei Li

#include<stdlib.h>
#include<stdio.h>
#include "file.h"
#include "vector.h"
#include "search.h"

int main(int argc, char *argv[])
{
  int countfam = 0;  int countind = 0;  FILE *file;
  char **indiIDs, **names, **spousesIDs, **childIDs;

  if(argc != 2)
  {
    printf("Usage: family.out <ged_filename>\n");
    return 1; 
  }  // no input file
  
  file = count_records(argv[1], &countfam, &countind);
  initialize(countfam, countind, &indiIDs, &names, &spousesIDs, &childIDs);

  read_file(indiIDs, names, spousesIDs, childIDs, file);
  find_children(indiIDs, names, spousesIDs, childIDs, countind, countfam);
  deallocate(indiIDs, names, spousesIDs, childIDs, countfam, countind);
 
  return 0;
}  // main()
