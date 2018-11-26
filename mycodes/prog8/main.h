
#ifndef MAIN_H 
#define MAIN_H

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
	
}Family;




#endif

