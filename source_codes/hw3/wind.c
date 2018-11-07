// Author: Sean Davis

#include <stdio.h>

int main()
{
  int knots;
  
  printf("Please enter the wind velocity in knots: ");
  scanf("%d", &knots);
  printf("That is ");
  
  if(knots < 1)
    printf("calm.\n");
  
  if(knots >= 1 && knots < 4)
    printf("light air.\n");
  
  if(knots > 3 && knots < 28)
    printf("a breeze.\n");

  if(knots > 27 && knots < 48)
    printf("a gale.\n");
    
  if(knots > 47 && knots < 64)
    printf("a storm.\n");
    
  if(knots > 63)
    printf("a hurricane.\n");
  return 0;
} // main()

