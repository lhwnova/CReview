#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search.h"



void find_children(char **indIDs, char **names, char **spouseIDs, char **childIDs, 
  int indCount, int famCount){

  char inputName[80], line[1000], *ptr;

  int nameIndex, famIndex, childIndex;

  
  while(1){
  
    printf("Please enter a name (Done = exit): ");
    fgets(inputName, 80, stdin);
    //printf("%s", inputName);
     
    if(strcmp(inputName, "Done\n") == 0){
    	
    	return;
    }

    nameIndex = find_name(names, indCount, inputName);

    if(nameIndex>= 0){

      famIndex = find_ID(indIDs[nameIndex], spouseIDs, famCount);
      
      if(famIndex == -1){
        printf("%s never married.\n", inputName);

      }else{
         if(childIDs[famIndex] == NULL){
         	printf("%s has no children.\n", inputName);

         }else{
            strcpy(line, childIDs[famIndex]);

            for(ptr = strtok(line, " "); ptr; ptr = strtok(NULL, " ")){
            	childIndex = find_ID(ptr, indIDs, indCount);
            	printf("%s\n", names[childIndex]);
            }

         }

      }

    }
   

  }
}



int find_name(char **names, int indCount, char inName[80]){

  char  name2[80], *name_ptrs[5], *ptr;
  int count = 0, i; // j;

  inName[strlen(inName) - 1] = '\0';

  strcpy(name2, inName);

  for(ptr = strtok(name2, " ,\n"); ptr; ptr = strtok(NULL, " ,\n")){
    name_ptrs[count++] = ptr;
    //printf("%s\n", ptr);
  }

  for(i = 0; i < indCount; i++)
  {
  	if(strstr(names[i], name_ptrs[0])){
      if(strstr(names[i], name_ptrs[count - 1])){
        return i;
      }
  	}

    // for(j = 0; j < count; j++){
    //   if(strstr(names[i], name_ptrs[j]) == NULL){
    //     //printf("%s\n", name_ptrs[j]);
    //     break;
    //   }
    // }
    
    // if(j == count)
    //   return i; // found the name
  } // for i

  printf("%s not found.\n", inName);
  return -1;

}



int find_ID(const char *ID, char **IDs, int count){

  int i;

  for(i = 0; i < count; i++){

  	if(strstr(IDs[i], ID)){
  		return i;
  	}
  }

  return -1;
}


