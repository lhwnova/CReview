#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"


FILE* count_records(const char* filename, int *individualCount, int *familyCount){
  
  FILE *fptr = fopen(filename, "r");
  char line[80];
  //*individualCount = *familyCount = 0;

  //printf("Filename: %s\n", filename);
  
  if(fptr == NULL){
    printf("Unable to read %s.\n", filename);
    exit(1); 	
  }
 
 
  while(fgets(line, 80, fptr) != NULL){
    //printf("here\n");
    if(strstr(line, "INDI") && line[0] == '0'){
      //printf("%s\n", line);
      *individualCount = *individualCount + 1;
    }

    if(strstr(line, "FAM") && line[0] == '0'){
      //printf("%s\n", line);
      *familyCount = *familyCount + 1;
    }

  }


  rewind(fptr);
  return fptr;
}


void read_file(char **indIDs, char **names, char **spouseIDs, char **childIDs, 
  FILE *filePtr){

  int ind_count = 0, fam_count = 0;
  char *ptr, line[256];

  ptr = fgets(line, 256, filePtr);

  while(ptr){
 
    if(strstr(line, "INDI")){
      ptr = read_indi(indIDs, names, &ind_count, line, filePtr);

    }else if(strstr(line, "FAM")){
      ptr = read_family(spouseIDs, childIDs, &fam_count, line, filePtr);

    }else{
      ptr = read_other(line, filePtr);
    }

  }
}


char* get_ID(char *line){
  
  char *ptr = strchar(line, '@');
  *ptr = '\0';
  ptr = strchar(line, '@');

  return ptr + 1;

}


char* read_indi(char **indIDs, char **names, int *ind_count, char *line, FILE *fp){


  char name[80];
  char *ptr;

  strcpy(indIDs[*ind_count], get_ID[line]);
 
  ptr = fgets(line, 1000, fp);

  while(ptr != NULL && line[0] != '0'){
    
    ptr = strstr(line, "NAME");

    if(ptr != NULL){
      strtok(ptr, " /");
      name[0] = '\0';
      ptr = strtok(NULL, " /\n");

      if(ptr){
        strcpy(name, ptr);
      }
      
      ptr = strtok(NULL, " /\n");
      while(ptr != NULL){
        sprintf(name, "%s %s", name, ptr);
        ptr = strtok(NULL, " /\n"); 
      }

      names[*ind_count] = (char*)malloc(strlen(name) + 1);
      *ind_count = *ind_count + 1;
      strcpy(names[*ind_count], name);
      
    } 

    ptr = fgets(line, 1000, fp); 
  }

  return ptr;
}


char* read_family(char **spouseIDs, char **childIDs, int *fam_count, char *line, FILE *fp){
  
  char *ptr, *temp;

  ptr = fgets(line, 1000, fp);

  while(ptr != NULL && line[0] != '0'){
    
    if(strstr(line, "HUSB") || strstr(line, "WIFE")){
      sprintf(spouseIDs[*fam_count], "%s %s", spouseIDs[*fam_count], get_ID(line));
    }

    if(strstr(line, "CHIL")){
      ptr = get_ID(line);

      if(childIDs[*fam_count]){
        temp = (char*) malloc(childIDs[*fam_count] + strlen(ptr) + 2);
        sprintf(temp, "%s %s", childIDs[*fam_count], ptr);
        free(childIDs[*fam_count]);
        childIDs[*fam_count] = temp;

      }else{
        
        childIDs[*fam_count] = (char*)malloc(strlen(ptr) + 1);
        strcpy(childIDs[*fam_count], ptr);

      }

    }


    ptr = fgets(line, 1000, fp); 

  }

  *fam_count = *fam_count + 1;

  return ptr;
}

char* read_other(char *line, FILE * fp){

  char *ptr = fgets(line, 256, fp);

  while(ptr != NULL && line[0] != '0'){
    ptr = fgets(line, 256, fp); 
  }

  return ptr;
}