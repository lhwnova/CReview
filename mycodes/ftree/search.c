// Author: Huan Wei Li  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search.h"
#include "main.h"

int family_cmp(const void *ptr, const void *ptr2)
{
  return strcmp(((Family*) ptr)->FAM, ((Family*) ptr2)->FAM);
} // individual_cmp()


void find_children(char *indID, int individual_count, int family_count, 
  Individual *individuals, Family *families)
{
   Family family, *family_ptr;
   int i;
 
   for(i = 0; i < individual_count; i++)
     if (strcmp(individuals[i].INDI, indID) == 0)
        break;
   
   family.FAM = individuals[i].FAMS;
   if(family.FAM == NULL)
     printf("%s never married.\n", individuals[i].NAME);
   else
   {
     family_ptr = bsearch(&family, families, family_count, 
       sizeof(Family), family_cmp);
     if(family_ptr->chil_count == 0) {
       printf("%s had no children.\n", individuals[i].NAME); }
     else 
     {
       printf("%s: ", individuals[i].NAME);
       print_children(family_ptr, individuals, individual_count);
     } // had at least one child
   } // else he married
} // find_children()


void printTree(char *indID, int individual_count, int family_count, 
  Individual *individuals, Family *families)
{
  int i; 
  Family family, *family_ptr;
  
  find_children(indID, individual_count, family_count, individuals,
    families);
     
  for(i = 0; i < individual_count; i++)
    if (strcmp(individuals[i].INDI, indID) == 0)
      break;
  
  family.FAM = individuals[i].FAMS;
  if(family.FAM != NULL)
  {
    family_ptr = bsearch(&family, families, family_count, 
      sizeof(Family), family_cmp);
    
    for(i = 0; i < family_ptr->chil_count; i++)
    {
      printTree(family_ptr->CHILs[i], individual_count, 
        family_count, individuals, families);
    }  // print family tree
  } // if has a family 
}  // printTree()


int find_spouse(const char* ID, int count, Family *families)
{
  int i;
  
  for(i = 0; i < count; i++)
    if(strstr(families[i].HUSB, ID) || strstr(families[i].WIFE, ID))
      return i;
  
  return -1;
} // find_IDs
 
int find_name(char name[80], int individual_count,  Individual *individuals)
{
  char  name2[80], *name_ptrs[5], *ptr;
  int count = 0, i, j;

  name[strlen(name) - 1] = '\0';
  strcpy(name2, name);
  
  for(ptr = strtok(name2, " ,\r\n"); ptr; ptr = strtok(NULL, " ,\r\n"))
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
} // find_name()


int individual_cmp(const void *ptr, const void *ptr2)
{
  return strcmp(((Individual*) ptr)->INDI, ((Individual*) ptr2)->INDI);
} // individual_cmp()


void print_children(Family *family, Individual *individuals, 
  int individual_count)
{
  int i;
  Individual individual_key, *individual_ptr;
 
  for(i = 0; i < family->chil_count; i++)
  {
    individual_key.INDI = family->CHILs[i];
    individual_ptr = bsearch(&individual_key, individuals,
      individual_count, sizeof(Individual), individual_cmp);

    printf("%s", individual_ptr->NAME);
    if((i + 1) < family -> chil_count)
      printf(", ");    // commas 
    else
      printf("\n"); 
  } // for i
} // print_children()
