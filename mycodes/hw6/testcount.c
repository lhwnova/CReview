// Author: Huan Wei Li 

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

FILE *openf();
int checkword(char **unique, char *word, int size, int *wlen);
char **resize(char **unique, int *size);
void print_out(int count, int word_count, int size, int *wlen);
void free_unique();
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
    }
 
    if(checkword(unique, word, count, wlen))
    {
      unique[count] = (char*) malloc(sizeof(char) * 31);
      strcpy(unique[count], word);
      count++;
    }
    
    if((count + 1) == size)
      unique = resize(unique, &size);      
  }

  print_out(count, word_count, size, wlen);

  return(0);
} // main()


int checkword(char **unique, char *word, int size, int *wlen)
{
  int i, j = 0; 
  char tempword[31]; 

  for(j = 0; isalpha(word[j]); j++) 
    tempword[j] = tolower(word[j]);
   
  tempword[j] = '\0';
  strcpy(word, tempword);

  for(i = 0; i < size; i++)
  {
    if(strcmp(unique[i], tempword) == 0) 
      return 0;
  }
   
  return 1; 
}


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
  printf("Total words: %d  Unique words:  %d  Unique size: %d\n", 
    word_count, count, size);

  printf("Length Count\n");


} // print_out()


void free_unique()
{



} //free_unique()



