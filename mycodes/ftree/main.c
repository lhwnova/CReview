// Author: Huan Wei Li 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file.h"
#include "vector.h"
#include "search.h"
#include "main.h"


typedef enum
{
  done, pchildren, ptree
} Choice;   // enum type


int main(int argc, char **argv)
{
  int individual_count, family_count;
  Individual *individuals;
  Family *families;
  
  FILE *fp;
  
  if(argc != 2)
  {
    printf("Usage: family.out <ged_filname>\n");
    return 1;
  } // if the number of arguments is wrong
  
  fp = count_records(argv[1], &individual_count, &family_count);
  initialize(individual_count, family_count, &individuals, &families);
  read_file(fp, individuals, families);
  qsort(individuals, individual_count, sizeof(Individual), individual_cmp);
  qsort(families, family_count, sizeof(Family), family_cmp);
  run(individual_count, family_count, individuals, families);
  deallocate(individual_count,family_count, individuals, families);
  return 0;
} // main()


void run(int individual_count, int family_count, Individual 
  *individuals, Family *families)
{
  int name_index, usr_in;       char temp, name[80];

  while(1) 
  {
    printf("\n");
    printf("Menu\n0. Done.\n1. Find children.\n2. Print family tree.\n"); 
    printf("Your choice: ");
    scanf("%d", &usr_in);
    scanf("%c", &temp);
    if((Choice) usr_in == done)   return; 
    else
    {
      printf("Please enter a name: ");
      fgets(name, 80, stdin);
      name_index = find_name(name, individual_count, individuals);
      if(name_index >= 0)
      {
        if((Choice) usr_in == pchildren)
        {
          find_children(individuals[name_index].INDI, individual_count,
            family_count, individuals, families);
        } // print children  
        else
        {
          printTree(individuals[name_index].INDI, individual_count,
            family_count, individuals, families);
        } // print family tree 
      } // conditional for name
    } // if not done 
  }  // while loop for menus 
}  // run()









