// Author: Sean Davis
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char** processWord(char **unique, int counts[], int *size, int *count, 
  char *word);

char** resize(char **unique, int *size);
void show_results(int counts[], int count, int size);
void free_unique(char **unique, int count);


int main() 
{
  char **unique, filename[80], word[80];
  int counts[31], size = 10, i, count = 0;
  FILE *fp;
  unique = malloc(10 * sizeof(char*));
  printf("Filename: ");
  scanf("%s", filename);
  
  if((fp = fopen(filename, "r")) == NULL)
  {
    printf("Unable to read %s.\n", filename);
    return -1;
  }  // if not able to open file
  
  for(i = 0; i <= 30; i++)    
    counts[i] = 0;
  
  while(fscanf(fp, "%s", word) != EOF)
    unique = processWord(unique, counts, &size, &count, word);
  
  show_results(counts, count, size);
  free_unique(unique, count);
  
  return 0;
} // main()


void free_unique(char **unique, int count)
{
  int i;
  
  for(i = 0; i < count; i++)
    free(unique[i]);
  
  free(unique);
} // free_unique


char** processWord(char **unique, int counts[], int *size, int *count, 
  char *word2)
{
  char word[31];
  int i, j;
  
  for(i = 0; word2[i] &&  !isalpha(word2[i]); i++);
  
  for(j = 0; isalpha(word2[i]); j++)
    word[j] = tolower(word2[i++]);
  
  word[j] = '\0';
  
  if(word[0] != '\0') // word not empty
  {
    counts[strlen(word)]++;
    
    for(i = 0; i < *count; i++)
      if(strcmp(word, unique[i]) == 0)
        break;
    
    if(i == *count) // not found
    {
      if(*count == *size)
        unique = resize(unique, size);
      
      unique[*count] = (char*) malloc(strlen(word) + 1);
      strcpy(unique[*count], word);
      ++(*count);
    } // if not found
  } // word not empty
  
  return unique;
}  // processWord

char** resize(char **unique, int *size)
{
  int i;
  char** temp = malloc(2 * *size * sizeof(char*));
  
  for(i = 0; i < *size; i++)
    temp[i] = unique[i];
  
  free(unique);
  *size *= 2;
  return temp;
} // resize()


void show_results(int counts[], int count, int size)
{
  int i, total = 0;
  
  for(i = 0; i <= 30; i++)
    total += counts[i];
  
  printf("Total words: %d  Unique words: %d  Unique's size: %d\n",  total,
    count, size);
  printf("Length Count\n");
  for(i = 0; i <= 30; i++)
    if(counts[i] != 0)
      printf("%4d%7d\n", i, counts[i]);
}  // show_results()