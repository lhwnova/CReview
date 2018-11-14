// Author: Sean Davis
// modified to ensure fscanf(...%s...) reads only one "word" at a time

#include <stdio>

int main()
{
  double value, product, result;
  printf( "Please enter a monetary value: ");
  scanf( "%lf", &value);
  product = value / 1000000;
  result = product * 1000000;
  printf( "%16.2lf %24.10lf %34.20lf", result, result, result);
  return 0;
} // main()

