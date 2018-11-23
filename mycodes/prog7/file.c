#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "vector.h"


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
  //printf("hello here\n");
  while(ptr){
 
    if(strstr(line, "INDI")){
      ptr = read_indi(indIDs, names, &ind_count, line, filePtr);
      
    }else if(strstr(line, "FAM")){
      ptr = read_family(spouseIDs, childIDs, &fam_count, line, filePtr);
      //printf("here\n");
    }else{
      ptr = read_other(line, filePtr);
    }

  }
}


char* get_ID(char *line){
  
  char *ptr;

  ptr = strtok(line, "@");
  ptr = strtok(NULL, "@");
  //printf("line: %s\n", line);
  //printf(">>%s\n", ptr);
  
  return ptr;
  
}


char* read_indi(char **indIDs, char **names, int *ind_count, char *line, FILE *fp){


  char name[81], temp[80];
  char *ptr;
  
  //puts(get_ID(line));

  strcpy(indIDs[*ind_count], get_ID(line));
  
  ptr = fgets(line, 256, fp);

  //printf("here\n");
  while(ptr != NULL && line[0] != '0'){
    
    ptr = strstr(line, "NAME");
     
    if(ptr != NULL){
      strtok(ptr, " /");
      temp[0] = '\0';
      ptr = strtok(NULL, " /\n");
      
      if(ptr){
        strcpy(temp, ptr);
      }
      
      ptr = strtok(NULL, " /\n");
      while(ptr != NULL){

        sprintf(name, "%s %s", temp, ptr);
        //strcpy(name, temp);
        ptr = strtok(NULL, " /\n"); 
      }
      
      names[*ind_count] = (char*)malloc(strlen(name) + 1);
      strcpy(names[*ind_count], name);

      *ind_count = *ind_count + 1;
      
    } 

    ptr = fgets(line, 256, fp); 
  }

  return ptr;
}


char* read_family(char **spouseIDs, char **childIDs, int *fam_count, char *line, FILE *fp){
  
  char *ptr, *temp, *tvar;

  ptr = fgets(line, 256, fp);

  while(ptr != NULL && line[0] != '0'){
    
    if(strstr(line, "HUSB") || strstr(line, "WIFE")){
      //printf(">>%s\n", get_ID(line));
      //printf(">>%s\n", spouseIDs[*fam_count]);
      //strcat(spouseIDs[*fam_count], get_ID(line));
      tvar = spouseIDs[*fam_count];
      sprintf(spouseIDs[*fam_count], "%s %s", tvar, get_ID(line));
      //printf(">>%s\n", spouseIDs[*fam_count]);
      //strcpy(spouseIDs[*fam_count], tvar);      
      
    }
    
    if(strstr(line, "CHIL")){
      ptr = get_ID(line);

      if(childIDs[*fam_count]){
        temp = (char*) malloc(strlen(childIDs[*fam_count]) + strlen(ptr) + 2);
        sprintf(temp, "%s %s", childIDs[*fam_count], ptr);
        free(childIDs[*fam_count]);
        childIDs[*fam_count] = temp;

      }else{
        
        childIDs[*fam_count] = (char*)malloc(strlen(ptr) + 1);
        strcpy(childIDs[*fam_count], ptr);

      }

    }


    ptr = fgets(line, 256, fp); 

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