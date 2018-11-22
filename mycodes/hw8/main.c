// Author: 

#include "main.h"
#include <stdio.h>
#include "file.h"
#include "vector.h"
#include "search.h"

int main(int argc, char **argv)
{
  char **indiIDs, **names, **spousesIDs, **childIDs;
  int individual_count, family_count;
  FILE *fp;
 
  Individual *individuals;
  Family *families;  
 
  if(argc != 2)
  {
    printf("Usage: family.out <ged_filename>\n");
    return 1;
  } // if the number of arguments is wrong
  
  fp = count_records(argv[1], &individual_count, &family_count);
  initialize(&indiIDs, &names, &spousesIDs, &childIDs, individual_count,
    family_count, &individuals, &families);
  read_file(indiIDs, names, spousesIDs, childIDs, fp);
  find_children(indiIDs, names, spousesIDs, childIDs, individual_count, 
    family_count);
  deallocate(indiIDs, names, spousesIDs, childIDs, individual_count, 
    family_count);
  return 0;
} // main()

