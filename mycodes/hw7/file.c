// Author: Huan Wei Li 

#include<stdio.h>
#include<stdlib.h>
#include "file.h"
#include<string.h>

FILE *count_records(const char* filename, int *family_count, 
  int *individual_count)
{
  FILE *fp;
  char line[80];
  //printf("%s\n", filename);
  fp = fopen(filename, "r"); 
    
  if(fp == NULL) 
  { 
    printf("Unable to read %s.\n", filename);
    exit(1);
  }  // if no file to read
 
  while(fgets(line, 80, fp) != NULL)
  {
    if(line[0] == '0')
    {
      if(strstr(line, "INDI") != NULL)
        (*individual_count)++;
      else
        if(strstr(line, "FAM") != NULL)
          (*family_count)++;
    } // check tag
  }  // loop through file 

  rewind(fp);  
  return fp;
} // Count_record()


void read_file(char **indiIDs, char **names, char **spousesIDs,
  char **childIDs, FILE *fp)
{
  char line[80], *k;   int countind = 0;   int countfam = 0;

  k = fgets(line, 80, fp);
  while(k != NULL)
  {
    if(line[0] == '0')
    {
      if(strstr(line, "INDI") != NULL)  
        k = read_indi(line, fp, &countind, indiIDs, names);
      else
        if(strstr(line, "FAM") != NULL)
          k = read_family(line, fp, &countfam, spousesIDs, childIDs);
        else
          k = read_other(line, fp);  
    }
  }
}  // read_file()


char *read_indi(char line[], FILE *fp, int *countind, char **indiIDs,
  char **names)
{
  char *k, *fname, *lname;  
 
  k = get_ID(line);
  strcpy(indiIDs[*countind], k); 
   
  k = fgets(line, 80, fp);  
  while(k != NULL)
  { 
    if(strstr(line, "NAME") != NULL)
    {
      fname = strtok(line, " ");
      fname = strtok(NULL, " ");
      fname = strtok(NULL, "/");
      lname = strtok(NULL, "/");
      sprintf(fname, "%s%s", fname, lname);
      names[*countind] = (char*) malloc(sizeof(char) * strlen(fname)); 
      strcpy(names[*countind], fname);
      (*countind)++;
    } // check for NAME tag
    else
      if(line[0] == '0') return k;
 
    k = fgets(line, 80, fp);
  }  // go through the file 
  return NULL;
}  // read_indi()


char *read_family(char line[], FILE *fp, int *countfam, char **spousesIDs, char **childIDs)
{
  char *k, *id, temp[80]; 
 
  k = fgets(line, 80, fp);  
  while(k != NULL){     
    if(strstr(line, "HUSB") != NULL || strstr(line, "WIFE") != NULL){
      id = get_ID(line);
      sprintf(spousesIDs[(*countfam)], "%s %s", spousesIDs[(*countfam)]
        , id);    
    }else    // check for HUSB and WIFE tags
      if(strstr(line, "CHIL") != NULL) {
        id = get_ID(line);
        if(childIDs[(*countfam)] == NULL){
          childIDs[(*countfam)] = (char*) malloc(sizeof(char) * 
            strlen(id));
          strcpy(childIDs[(*countfam)], id);   
        }else{   // check for NULL childIDs 
            strcpy(temp, childIDs[(*countfam)]); 
            sprintf(temp, "%s %s", temp, id);
            childIDs[(*countfam)] = (char*) malloc(sizeof(char) * 
            strlen(temp));  
            strcpy(childIDs[(*countfam)], temp);
          }  // if not 
      } // if childIDs not NULL 
    if(line[0] == '0'){
      (*countfam)++;   return k; }  // if first thing is 0    
    k = fgets(line, 80, fp);
  } // while not null
  return NULL;
}  // read_family()


char *read_other(char line[], FILE *fp)
{
  char *k; 

  k = fgets(line, 80, fp);  
  while(k != NULL)
  {
    if(line[0] == '0')
      return k;
    k = fgets(line, 80, fp);
  } // while not null
  return NULL;
}  // read_other()


char *get_ID(char line[])
{
  char *k;
  
  k = strtok(line, "@");
  k = strtok(NULL, "@");
   
  return k;
}  // get_ID


