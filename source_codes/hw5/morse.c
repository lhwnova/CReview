// Author: Sean Davis

#include <stdio.h>
#include <ctype.h>
#define DONE 0
#define READ 1
#define WRITE 2
const char *codes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", 
  "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...",
  "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

int get_choice();
void find_code(char code[], int length);
void read();
void write();

int main()
{
  int choice;
  
  while((choice = get_choice()) != DONE)
  {
    if(choice == READ)
      read();
    else
      write();
  }  // while
  
  return 0;
} // main()


int get_choice()
{
  int choice;
  
  do
  {
    printf("Morse Menu\n");
    printf("0. Done.\n");
    printf("1. Read Morse code.\n");
    printf("2. Write Morse code.\n\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    if(choice < DONE || choice > WRITE)
    {
      printf("That is not between 0 and 2.\n");
      printf("Please try again.\n\n");
    } // if invalid choice
  }  while (choice < DONE || choice > WRITE);
  
  return choice;
} // get_choice


void write()
{
  char c;
  int i;
  
  printf("English message: ");
  scanf("\n%c", &c);
  c = toupper(c);
  
  while(c != '\n')
  {
    if(isalpha(c))
    {
      for(i = 0; codes[c - 'A'][i] != '\0'; i++)
        printf("%c", codes[c - 'A'][i]);
       
      printf(" ");
    } // if letter
    else
      if(c == ' ')
        printf(" ");
      else
        printf("?");
    
    scanf("%c", &c);
    c = toupper(c);
  }  // while not eoln
    
  printf("\n");
}  // write()


void find_code(char code[], int length)
{
  int i, j;
  
  for(i = 0; i < 26; i++)
  {
    for(j = 0; codes[i][j] == code[j] && codes[i][j] != '\0' && j != length; j++);
    
    if(codes[i][j] == '\0' && j == length)
    {
      printf("%c", i + 65);
      return;
    }  // if found code
  } // for i 
  
  printf("?");
  return;
}  // find_code()

void read()
{
 int i;
  char c, code[80];
  printf("Morse code: ");
  scanf("\n%c", &c);
  while(c != '\n')
  {
    i = 0;
    while(c != '\n' && c != ' ')
    {
      code[i++] = c;
      scanf("%c", &c);
    }  // while not at space or eoln
    
    find_code(code, i);
    
    if(c == ' ')
    {
      scanf("%c", &c);
      if(c == ' ')
      {
        printf(" ");
        scanf("%c", &c);
      }
    }
  }  // while not at end of line.
  
  printf("\n");
}  // read()
