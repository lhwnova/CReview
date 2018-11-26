#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file.h"
#include "vector.h"

FILE* count_records(const char *filename, int *individual_count,
  int *family_count)
{
  char line[1000];
  FILE *fp = fopen(filename, "r");

  if(fp == NULL)
  {
    printf("Unable to read %s.\n", filename);
    exit(1);
  }  // if unable to open file

  *individual_count = *family_count = 0;

  while(fgets(line, 1000, fp) != NULL)
  {

    if(strstr(line, "INDI") && line[0] == '0')
      (*individual_count)++;

    if(strstr(line, "FAM") && line[0] == '0')
      (*family_count)++;
  } // while more in file

  rewind(fp);
  return fp;
} // count_records()



void read_file(FILE *fptr, Family *families, Individual *individuals){


  char line[256], *ptr;
  int individual_count = 0, family_count = 0;

  ptr = fgets(line, 256, fptr);

  while(ptr != NULL)
  {
    if(strstr(line, "INDI")){
      //printf("line: %s\n", line);
      ptr = read_indi(individuals, &individual_count, line, fptr);
      //printf("here\n");
    }
    else{
      if(strstr(line, "FAM")){
        ptr = read_family(families, &family_count, line, fptr);
        //printf("here\n");
      }else{
        ptr = read_other(line, fptr);
      }
    }
  }

}

char* get_ID(char *line){

  char *temp, *ptr;

  ptr = strtok(line, "@");
  ptr = strtok(NULL, "@");
  
  //printf("Ptr: %s\n", ptr);
  temp = (char*)malloc(strlen(ptr));
  strcpy(temp, ptr);
  
  //printf("temp: %s\n", temp);
  return temp;
}


char* read_other(char *line, FILE *fp){

  char *ptr = fgets(line, 256, fp);

  while(ptr != NULL && line[0] != '0'){
    ptr = fgets(line, 256, fp);
  }

  return ptr;

}

char* read_indi(Individual *individuals, int *individual_count, char *line, FILE *fp){

  char name[81], temp[80];
  char *ptr;
  
  //printf("line: %s\n", line);
  //printf("get_ID: %s\n", get_ID(line));

  individuals[*individual_count].INDI = get_ID(line);
  //printf("IND_ID: %s\n", individuals[*individual_count].INDI);

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
      
      individuals[*individual_count].name = (char*)malloc(strlen(name)+1);
      strcpy(individuals[*individual_count].name, name);

    }else if(strstr(line, "FAMC")){

      individuals[*individual_count].FAMC = get_ID(line);

    }else if(strstr(line, "FAMS")){

      individuals[*individual_count].FAMS = get_ID(line);

    }

    ptr = fgets(line, 256, fp);
  }

  *individual_count = *individual_count + 1;
  return ptr;

}

char* read_family(Family *families, int *family_count, char *line, FILE *fp){

  char *ptr; // *temp, *tvar;

  families[*family_count].FAM = get_ID(line);

  ptr = fgets(line, 256, fp);
  
  //printf("Family ID: %s\n", families[*family_count].FAM);
  while(ptr != NULL && line[0] != '0'){
    
    if(strstr(line, "HUSB")){
      families[*family_count].HUSB = get_ID(line);
      
    } 

    if(strstr(line, "WIFE")){
      families[*family_count].WIFE = get_ID(line);
    
    }

    if(strstr(line, "CHIL")){
      add_child(line, &families[*family_count]);

    }
    
    ptr = fgets(line, 256, fp);
  }
    
  *family_count = *family_count + 1;

  return ptr;
}


void add_child(char *line, Family *families){

  int i; 
  char **temp;
  
  temp = (char**) malloc((families->child_count + 1) * sizeof(char*));

  for(i = 0; i < families->child_count; i++){
  	temp[i] = families->CHIL[i];
  } // copying ?????

  temp[i] = get_ID(line);
  free(families->CHIL);
  families->CHIL = temp;
  families->child_count = families->child_count + 1;

}


