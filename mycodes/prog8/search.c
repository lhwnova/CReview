

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search.h"
#include "main.h"

void find_children(int individual_count, int family_count, Individual *individuals, Family *families){

  char name[80];
  int name_index;
  Family family, *family_ptr;
  
  while(1)
  { 
    printf("Please enter a name (Done = exit): ");
    fgets(name, 80, stdin);

    if(strcmp(name, "Done\n") == 0)
      return;

    name_index = find_name(name, individual_count, individuals);

    if(name_index >= 0)
    {
      family.FAM = individuals[name_index].FAMS;

      if(family.FAM == NULL)
        printf("%s never married.\n", name);
      else
      {
        family_ptr = bsearch(&family, families, family_count, sizeof(Family), family_cmp);

        if(family_ptr->chil_count == 0)
          printf("%s had no children.\n", name);
        else // had at least one child
          print_children(family_ptr, individuals, individual_count);
      } // else he married
    }  // if name found
  } // while user doesn't enter Done
  

}

void print_children(Family *family, Individual *individuals, int individual_count){
  
  int i;
  Individual individual_key, *individual_ptr;

  for(i = 0; i < family->chil_count; i++)
  {
    individual_key.INDI = family->CHILs[i];
    individual_ptr = bsearch(&individual_key, individuals, individual_count, sizeof(Individual), individual_cmp);
    printf("%s\n", individual_ptr->NAME);
  } // for i
  
}


int find_name(char name[80], int individual_count, Individual *individuals){
  
  char  name2[80], *name_ptrs[5], *ptr;
  int count = 0, i, j;

  name[strlen(name) - 1] = '\0';
  strcpy(name2, name);

  for(ptr = strtok(name2, " ,\n"); ptr; ptr = strtok(NULL, " ,\n"))
    name_ptrs[count++] = ptr;

  for(i = 0; i < individual_count; i++)
  {
    for(j = 0; j < count; j++)
      if(strstr(individuals[i].NAME, name_ptrs[j]) == NULL)
        break;

    if(j == count)
      return i; // found the name
  } // for i

  printf("%s not found.\n", name);
  return -1;


}


int find_spouse(const char* ID,  int count, Family *families){

  int i;

  for(i = 0; i < count; i++)
    if(strstr(families[i].HUSB, ID) || strstr(families[i].WIFE, ID))
      return i;

  return -1;


}


int individual_cmp(const void *ptr, const void *ptr2)
{
  return strcmp(((Individual*) ptr)->INDI, ((Individual*) ptr2)->INDI);
} // individual_cmp()


int family_cmp(const void *ptr, const void *ptr2)
{
  return strcmp(((Family*) ptr)->FAM, ((Family*) ptr2)->FAM);
} // individual_cmp()





