#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "main.h"

void initialize(Individual **individuals, Family **families, int famCount, int indCount){

  int i;

  *families = (Family*) malloc(famCount*sizeof(Family));
  *individuals = (Individual*) malloc(indCount*sizeof(Individual));

  for(i = 0; i < indCount; i++){
    (*individuals)[i].INDI = NULL;
    (*individuals)[i].name = NULL;
    (*individuals)[i].FAMC = NULL;
    (*individuals)[i].FAMS = NULL;
  }


  for(i = 0; i < famCount; i++){
    (*families)[i].FAM = NULL;
    (*families)[i].HUSB = NULL;
    (*families)[i].WIFE = NULL;
    (*families)[i].CHIL = NULL;
    (*families)[i].child_count = 0;

  }

  
}



void deallocate(Individual *individuals, Family *families, int famCount, int indCount){

  int i, j;
  
  //printf("indCount: %d\n", famCount);
  for(i = 0; i < indCount; i++){

    if(individuals[i].INDI != NULL){ 
      free(individuals[i].INDI);
      //printf("%s \n", individuals[i].INDI);
    }

    if(individuals[i].name != NULL) 
      free(individuals[i].name);
    
    if(individuals[i].FAMC != NULL) 
      free(individuals[i].FAMC);

    if(individuals[i].FAMS != NULL) 
      free(individuals[i].FAMS);
    
  }

  //printf("hello man\n");
  for(i = 0; i < famCount; i++){
    if(families[i].HUSB)
      free(families[i].HUSB);

    if(families[i].WIFE)
      free(families[i].WIFE);

    if(families[i].FAM)
      free(families[i].FAM);
    //free(family[i].CHIL);

    //free(family)[i].child_count = 0;
    for(j = 0; j < families[i].child_count; j++){
      free(families[i].CHIL[j]);
    }

  }


  free(families);
  free(individuals); 

}






