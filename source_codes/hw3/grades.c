// Author: Sean Davis

#include <stdio.h>

int main()
{
  int score;
  printf("Please enter a test score: ");
  scanf("%d", &score);
  printf("Letter grade: ");
  
  switch(score / 10)
  {
    case 10:
    case 9:  printf("A\n"); break;
    case 8:  printf("B\n"); break;
    case 7:  printf("C\n"); break;
    case 6:  printf("D\n"); break;
    default: printf("F\n"); break;
  } // switch
  
  return 0;
} // main()

