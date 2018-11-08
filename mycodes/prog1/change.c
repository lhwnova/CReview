// modulus calculation
//
//
//

#include <stdio.h>


int main(){

  int change, quarter, dime, nickel, penny;

  printf("Please enter the amount of change (0 - 99): ");
  scanf("%d", &change);
 
  quarter = change / 25;
  change = change % 25;
  dime = change / 10;
  change = change % 10;
  nickel = change / 5;
  change = change % 5;
  penny = change;
  
  printf("That would be %d quarters, %d dimes, %d nickels, %d pennies.\n", quarter, dime, nickel, penny);
 


  return 0;
}
