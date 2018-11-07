// Author: Sean Davis

#include <stdio.h>

int main()
{
  double value, product, result;
  printf("Please enter a monetary value: ");
  scanf("%lf", &value);
  product = value / 1000000;
  result = product * 1000000;
  printf("%16.2lf\n%24.10lf\n%34.20lf\n", result, result, result);
  return 0;
} // main()

