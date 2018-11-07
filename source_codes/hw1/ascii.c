// Author: Sean Davis

#include <stdio.h>

int main()
{
  char c1, c2, result;
  int num;
  printf("Please enter two characters and an integer: ");
  scanf("%c%c%d", &c1, &c2, &num);
  result = c1 + c2;
  printf("c1 + c2 = %c (char), %d (int).\n", result, result);
  result = c1 - c2;
  printf("c1 - c2 = %c (char), %d (int).\n", result, result);
  result = c1 + num;
  printf("c1 + num = %c (char), %d (int).\n", result, result);
  return 0;
} // main()

