// arithmetic number precision 

#include <stdio.h>

int main(){

  double value, product, result;

  printf("Please enter a monetary value: ");
  scanf("%lf", &value);


  product = value * 1000000; 
  result = product / 1000000;

  printf("%16.2lf\n", result);
  printf("%24.10lf\n", result);
  printf("%34.20lf\n", result);
  

  return 0;
}
