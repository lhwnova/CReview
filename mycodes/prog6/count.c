#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// read file and parse
// check and resize if necessary
// 


char** resize(char **uarray, int *size);
void cleanUp(char **uarray, int size);
int checkWord(char *word, int *wordCount, char **uarray, int size); 
void print_out(int wordCount, int uniqueWord, int arraySize, int *wordLen);


int main(int argc, char const *argv[])
{
  int arraySize = 10;
  char word[80];
  char **unique = (char**) malloc(sizeof(char*)*arraySize);
  int wordCount[31];
  int arrayIndex = 0;
  int totalWord = 0;
   

  FILE *fp = fopen("gettysburg.txt", "r");
 
  for(int j = 0; j < 31; j++)
  	wordCount[j] = 0;

  while(fscanf(fp, "%s", word) != EOF){
    
    if(isalpha(word[0])) totalWord++; 

    if(checkWord(word, wordCount, unique, arrayIndex)){
      
      unique[arrayIndex] = (char*)malloc(sizeof(char)*strlen(word) + 1);

      strcpy(unique[arrayIndex], word); 
      //printf("%s\n", word);
      arrayIndex = arrayIndex + 1;
    }
    
    if((arrayIndex + 1) == arraySize) 
      unique = resize(unique, &arraySize);

  }  
    
  print_out(totalWord, arrayIndex, arraySize, wordCount);
  cleanUp(unique, arraySize);
  
  fclose(fp);

  return 0;
}


int checkWord(char *word, int *wordCount, char **uarray, int size){
  
  char tempWord[80];
  int len, i, wordLen; 

  for(wordLen = 0; word[wordLen]; wordLen++){
    if(isalpha(word[wordLen])){
      tempWord[wordLen] = tolower(word[wordLen]);
    }else{
       break;
    }
  }  

  tempWord[wordLen] = '\0';
  
  if(tempWord[0] == '\0') return 0;

  len = strlen(tempWord);
  wordCount[len] = wordCount[len] + 1;
  strcpy(word, tempWord);
  
  //printf("%s*", tempWord);
  for(i = 0; i < size; i++){
    if(strcmp(tempWord, uarray[i]) == 0){ 
      
      return 0;
    }
  }

  return 1;
}


void print_out(int wordCount, int uniqueWord, int arraySize, int *wordLen){
  
  printf("Total word: %d  Unique Word: %d  Unique Size: %d\n", wordCount, uniqueWord, arraySize);


  printf("Length   Count\n");
  for(int i = 1; i < 31; i++){
    if(wordLen[i] != 0)
      printf("%4d   %4d\n", i, wordLen[i]);

  }

}


char** resize(char **uarray, int *size){
  
  int i;
  char** temp = (char**) malloc(*size * 2 * sizeof(char*));

  // temp point to the same thing as uarrary
  for(i = 0; i < *size; i++){
  	temp[i] = uarray[i];
  }

 *size = *size * 2;
 free(uarray);

 return temp;
}


void cleanUp(char **uarray, int size){
   int i;

   for(i = 0; i < size; i++){
     free(uarray[i]);
   }

   free(uarray);
}


