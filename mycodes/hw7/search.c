// Author: Huan Wei Li

#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include "search.h"

void find_children(char **indiIDs, char **names, char **spousesIDs,
  char **childIDs, int individual_count, int family_count)
{
  char input[80], inname[80];  int len, stop = 1;
  int nameindex, spousesindex;

  while(stop)
  {
    printf("Please enter a name (Done = exit): ");
    fgets(inname, 80, stdin);    len = strlen(inname);
    inname[len - 1] = '\0';      strcpy(input, inname);   
    
    if(strcmp(inname, "Done") == 0) stop = 0; 
    else 
    {
      nameindex = find_name(inname, names, individual_count);
      //printf("%d\n", nameindex);
      if(nameindex == -1) printf("%s not found.\n", input);
      else
      {
        spousesindex = find_ID(spousesIDs, indiIDs, family_count,
          nameindex);
         if(spousesindex == -1) printf("%s never married.\n", input);
         else
           print_out(input, indiIDs, names, spousesindex, childIDs, 
             individual_count);
      } // if input in the list 
    } // stop
  }  // loop to ask user
}  //  find_children()


int find_name(char inname[], char **names, int individual_count)
{
  int len, i, flag = 0;     char *fname, *lname;
 
  len = strlen(inname);
  for(i = 0; i < len; i++){  
    if(ispunct(inname[i])) {
      flag = 1; 
      break;
    }  // if punctuated
  }   // check for punctuation
  if(flag){
    lname = strtok(inname, ","); 
    fname = strtok(NULL, " ");
  }  // id punctuation
  else {
    fname = strtok(inname, " "); 
    lname = strtok(NULL, " ");
  }  // regular name
  for(i = 0; i < individual_count; i++){
    if(fname != NULL && lname != NULL) {
      if(strstr(names[i], fname) != NULL && strstr(names[i], lname)
      != NULL)  return i; }
    else {
      if(fname == NULL){
        if(strstr(names[i], lname) != NULL) return i;}
      else
        if(lname == NULL) {
          if(strstr(names[i], fname) != NULL) return i; }
    } // check name
  }  // check if input name in names[]
  return -1;
}  // find_name()


int find_ID(char **spousesIDs, char **indiIDs, int family_count,
  int index)
{
  int i;

  for(i = 0; i < family_count; i++)
    if(strstr(spousesIDs[i], indiIDs[index]) != NULL)
      return i;

  return -1;
}  // find_ID()


void print_out(char inname[], char **indiIDs, char **names, int index,
  char **childIDs, int countind)
{
   char temp[80], *id;
   int i;

   if(childIDs[index] == NULL)  
   {
     printf("%s had no children.\n", inname);
     return; 
   }  // if no children  
    
   strcpy(temp, childIDs[index]);
   id = strtok(temp, " ");
   while(id != NULL)
   {
     for(i = 0; i < countind; i++)
       if(strstr(id, indiIDs[i]) != NULL) break;
    
     printf("%s\n", names[i]); 
     id = strtok(NULL, " "); 
   }  // print out children 
}  // print_out()








