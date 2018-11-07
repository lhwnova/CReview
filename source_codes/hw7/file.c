// Author: Sean Davis
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

char* read_other(char *line, FILE *fp)
{
  char *ptr;

  while((ptr = fgets(line, 1000, fp)) != NULL && line[0] != '0');
  
  return ptr;
} //read_other()


char* get_ID(char *line)
{
  char *ptr = strrchr(line, '@');
  *ptr = '\0';
  ptr = strchr(line, '@');
  return ptr + 1;
} // get_ID()


char* read_indi(char **indiIDs, char **names, int *individual_count, char *line,
  FILE *fp)
{
  char *ptr, name[80];

  strcpy(indiIDs[*individual_count], get_ID(line));
  
  while((ptr = fgets(line, 1000, fp)) != NULL && line[0] != '0')
  {
    if((ptr = strstr(line, "NAME")) != NULL)
    {
      strtok(ptr, " /");
      name[0] = '\0';
      ptr = strtok(NULL, " /\n");

      if(ptr)
        strcpy(name, ptr);
   
      while((ptr = strtok(NULL, " /\n")) != NULL)
        sprintf(name, "%s %s", name, ptr);
      
      names[*individual_count] = (char*) malloc(strlen(name) + 1);
      strcpy(names[(*individual_count)++], name);
    } // if a NAME tagged line
  } // while more in the record
  
  return ptr;
}  // read_indi()


char* read_family(char **spousesIDs, char **childIDs, int *family_count, 
  char *line, FILE *fp)
{
  char *ptr, *temp;
  
  while((ptr = fgets(line, 1000, fp)) != NULL && line[0] != '0')
  {
    if(strstr(line, "HUSB") || strstr(line, "WIFE"))
      sprintf(spousesIDs[*family_count], "%s %s", spousesIDs[*family_count],
        get_ID(line));
    
    if(strstr(line, "CHIL"))
    {
      ptr = get_ID(line);
      
      if(childIDs[*family_count])
      {
        temp = (char*) malloc(strlen(childIDs[*family_count]) + strlen(ptr) + 2);
        sprintf(temp,"%s %s", childIDs[*family_count], ptr);
        free(childIDs[*family_count]);
        childIDs[*family_count] = temp;
      } // if a child already exists
      else  // first child
      {
        childIDs[*family_count] = (char*) malloc(strlen(ptr) + 1);
        strcpy(childIDs[*family_count], ptr);
      } // else first child
    } // if a child
  } // while more in record
  
  (*family_count)++;
  return ptr;
}  // read_family()


void read_file(char **indiIDs, char **names, char **spousesIDs, char **childIDs, 
  FILE *fp)
{
  char line[256], *ptr;
  int individual_count = 0, family_count = 0;
  
  ptr = fgets(line, 256, fp);
  
  while(ptr != NULL)
  {
    if(strstr(line, "INDI"))
      ptr = read_indi(indiIDs, names, &individual_count, line, fp);
    else
      if(strstr(line, "FAM"))
        ptr = read_family(spousesIDs, childIDs, &family_count, line, fp);
      else
        ptr = read_other(line, fp);
    
  } // while more in the file
} // read_file()
