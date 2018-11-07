// Author: Sean Davis

#include <stdio.h>

void triangle();
void rectangle();
void lines();
void blank_lines();
void head();

int main()
{
  head();
  triangle();
  lines();
  blank_lines();
  head();
  rectangle();
  lines();
  blank_lines();
  triangle();
  rectangle();
  rectangle();
  lines();
  return 0;
} // main()

void triangle()
{
  printf("  /\\\n");
  printf(" /  \\\n");
  printf("/____\\\n");
   
} // triangle()

void head()
{
  printf(" /---\\\n");
  printf("| 0 0 |\n");
  printf(" \\_-_/\n");
} // rectangle()

void lines()
{
  printf("  /\\\n");
  printf(" /  \\\n");
  printf("/    \\\n");
} // lines()

void rectangle()
{
  printf("|----|\n");
  printf("|    |\n");
  printf("|----|\n");
} // rectangle()

void blank_lines()
{
  printf("\n\n");
}  // blank_lines()

