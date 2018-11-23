#include <stdio.h>
#include <string.h>
#include "file.h"
#include "vector.h"
#include "search.h"

int main(int argc, char const *argv[])
{
    int indCount = 0, famCount = 0;
    char **indIDs, **names, **spouseIDs, **childIDs;
    FILE *fp;

    if(argc != 2){
      printf("Usage: family.out <ged_filename>\n");
      return 1;
    }

    fp = count_records(argv[1], &indCount, &famCount);
    initialize(&indIDs, &names, &spouseIDs, &childIDs, indCount, famCount);
    
    read_file(indIDs, names, spouseIDs, childIDs, fp);


    // for(int i = 0; i < indCount; i++){
    //   //printf(">>%s\n", (indIDs)[i]);
    //   printf(">>%s\n", names[i]);
    // }

    // for(i = 0; i < famCount; i++){
    //   //printf(">>%s\n", spouseIDs[i]);
    //   printf(">>%s\n", childIDs[i]);
    // }
    find_children(indIDs, names, spouseIDs, childIDs, indCount, famCount); 
    deallocate(indIDs, names, spouseIDs, childIDs, indCount, famCount);

    //printf("%d <><> %d\n", indCount, famCount);
   

    fclose(fp);
	return 0;
}