// Author: Sean Davis

#include <stdio.h>

int main()
{
  int change, pennies, nickels, dimes, quarters;
  printf("Please enter the amount of change (0-99): ");
  scanf("%d", &change);
  quarters = change / 25;
  change = change - quarters * 25;
  dimes = change / 10;
  change -= dimes * 10;
  nickels = change / 5;
  pennies = change % 5;
  printf("That would be %d quarters, %d dimes, %d nickels, and %d pennies.\n",
    quarters, dimes, nickels, pennies);
  return 0;
} // main()

