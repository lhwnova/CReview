// Author: Sean Davis

#include <stdio.h>
#include <math.h>
int is_prime(int num);

int main()
{
  int num, num1, num2;
  
  do
  {
    printf("Please enter two integers greater than one,"
      " and in ascending order: ");
    scanf("%d%d", &num1, &num2);
    
    if(num1 < 2 || num2 < 2 || num1 >= num2)
    {
      if(num1 < 2 || num2 < 2)
        printf("The numbers must both be greater than one.\n");
      else // numbers not in ascending order
        printf("The numbers must be in ascending order.\n");
      
      printf("Please try again.\n\n");
    }  // if numbers are invalid
  }  while(num1 >= num2 || num1 < 2);
  
  for(num = num1; num <= num2; num++)
    if(is_prime(num))
      printf("%d ", num);
    
  printf("\n");
  return 0;
} // main()


int is_prime(int num)
{
  int i;
  
  for(i = 2; i <= sqrt(num); i++)
    if(num % i == 0)
      return 0;
  
  return 1;
}  // is_prime()


