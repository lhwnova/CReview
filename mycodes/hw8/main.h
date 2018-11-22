// Author: Huan Wei Li

#ifndef MAIN_H
#define MAIN_h

typedef struct 
{
  char *INDI;
  char *name;
  char *FAMC; 
  char *FAMS;
} Individual;


typedef struct 
{
  char *FAM;
  char *HUSB;
  char *WIFE;
  int child_count;
  char **CHIL;
} Family; 

#endif
