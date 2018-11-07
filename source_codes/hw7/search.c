// Author: Sean Davis

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search.h"



void find_children(char **indiIDs, char **names, char **spousesIDs, 
  char **childIDs, int individual_count, int family_count)
{
  char name[80], *ptr, line[1000];
  int name_index, family_index, child_index;
  
  while(1)
  {
    printf("Please enter a name (Done = exit): ");
    fgets(name, 80, stdin);
    
    if(strcmp(name, "Done\n") == 0)
      return;
    
    name_index = find_name(name, names, individual_count);
    
    if(name_index >= 0)
    {
      family_index = find_ID(indiIDs[name_index], spousesIDs, family_count);

      if(family_index == -1)
        printf("%s never married.\n", name);
      else
      {
        if(childIDs[family_index] == NULL)
          printf("%s had no children.\n", name);
        else // had at least one child
        {
          strcpy(line, childIDs[family_index]);
        
          for(ptr = strtok(line, " "); ptr; ptr = strtok(NULL, " "))
          {
            child_index = find_ID(ptr, indiIDs, individual_count);
            printf("%s\n", names[child_index]);
          }
        } // else had at least one child
      } // else he married
    }  // if name found 
  } // while user doesn't enter Done
} // find_children()


int find_ID(const char* ID, char **IDs, int count)
{
  int i;
  
  for(i = 0; i < count; i++)
    if(strstr(IDs[i], ID))
      return i;
  
  return -1;
} // find_ID
 

int find_name(char name[80], char **names, int individual_count)
{
  char  name2[80], *name_ptrs[5], *ptr;
  int count = 0, i, j;

  name[strlen(name) - 1] = '\0';
  strcpy(name2, name);
  
  for(ptr = strtok(name2, " ,\n"); ptr; ptr = strtok(NULL, " ,\n"))
    name_ptrs[count++] = ptr;
    
  for(i = 0; i < individual_count; i++)
  {
    for(j = 0; j < count; j++)
      if(strstr(names[i], name_ptrs[j]) == NULL)
        break;
      
    if(j == count)
      return i; // found the name
  } // for i
  
  printf("%s not found.\n", name);
  return -1;
} // find_name()
