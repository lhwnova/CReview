// Author: Huan Wei Li

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replace_first_x(char *user_input, char *ones, char *zeroes);
int display(char *line);


int main()
{
  char line[80];

  printf("Binary number: ");
  gets(line);
  display(line);

  return 0;
}  // main()


int replace_first_x(char *user_input, char *ones, char *zeroes)
{
  char *ptr;
  int length;
  
  length = strlen(user_input);
  user_input[length] = '\0';
  ptr = strchr(user_input, 'x');

  while(ptr != NULL)
  {
    *ptr = '1';
    strcpy(ones, user_input);

    *ptr = '0';
    strcpy(zeroes, user_input);

    return 1;
  }  // replaces x with either 1 or 0

  return 0;
}  // replace_first_x()


int display(char *line)
{
  char ones[80], zeroes[80];
  
  if(replace_first_x(line, ones, zeroes) == 0)
  {
    printf("%s\n", line);
    return 0;
  }  // print line after replace_first_x function

  display(zeroes);
  display(ones);

  return 0;
}  // display()


