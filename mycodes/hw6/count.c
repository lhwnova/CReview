// Author: Huan Wei Li and Cort Dalton 

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

FILE *openf();
int checkword(char **unique, char *word, int size, int *wlen);
char **resize(char **unique, int *size);
void print_out(int count, int word_count, int size, int *wlen);
void free_unique(char **unique, int size);
void len_declare(int *wlen); 


int main()
{
  int i,  wlen[30], size = 10;  FILE *file;
  char word[31];   int word_count = 0;   int count = 0; 
  char **unique = (char**) malloc(sizeof(char*) * size);   
  
  file = openf();
  len_declare(wlen);

  while(fscanf(file, "%s", word) != EOF)
  {
    for(i = 0; i < strlen(word); i++)
    {
      if(isalpha(word[i])) 
      {
        word_count++; 
        break;   
      }
    }  // count total word
    
    if(checkword(unique, word, count, wlen))
    {
      unique[count] = (char*) malloc(sizeof(char) * 31);
      strcpy(unique[count], word);
      count++;
    }  // check word
    if((count + 1) == size) unique = resize(unique, &size);      
  } // count word

  print_out(count, word_count, size, wlen);
  free_unique(unique, size);

  return(0);
} // main()


int checkword(char **unique, char *word, int size, int *wlen)
{
  int len, i, j = 0; 
  char tempword[31]; 
  i = 0;

  for(j = 0; j < strlen(word); j++)
  {  
    if(isalpha(word[j]))
    {
      tempword[i] = tolower(word[j]);
      i++;
    }  // if it is letter
    else
      if(i != 0 && isalpha(word[j]) == 0) break;
  }  // loop through string

  tempword[i] = '\0';  
  if(tempword[0] == '\0') return 0;

  strcpy(word, tempword);
  len = strlen(word);
 
  wlen[len] = wlen[len] + 1;
  
  for(i = 0; i < size; i++)
    if(strcmp(unique[i], tempword) == 0) 
     return 0;
   
  return 1; 
} // check_word()


void len_declare(int *wlen)
{
  int i; 

  for(i = 0; i < 30; i++) wlen[i] = 0; 
}  // len_declare()


FILE *openf()
{
  FILE *file;  char fname[80];
 
  printf("Filename: ");
  scanf("%s", fname);
  file = fopen(fname, "r");

  return file;
}  // fopen()


char **resize(char **unique, int *size)
{
  int i;
  char **temp = (char**) malloc(sizeof(char*) * (*size * 2));
  
  for(i = 0; i < *size; i++)
    temp[i] = unique[i];
  
  free(unique);
  *size = *size * 2;

  return temp;  
}  // resize()


void print_out(int count, int word_count, int size, int *wlen)
{
  int i;
  printf("Total words: %d  Unique words: %d  Unique's"
    " size: %d\n", 
    word_count, count, size);

  printf("Length Count\n");
  for(i = 1; i < 30; i++)
    if(wlen[i] != 0)
      printf("%4d   %4d\n", i, wlen[i]);
 
} // print_out()


void free_unique(char **unique, int size)
{
  int i;
  for(i = 0; i < size; i++)
    free(unique[i]);
  
  free(unique);
} //free_unique()



