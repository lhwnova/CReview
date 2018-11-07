// Author: Sean Davis

#include <stdio.h>

int main()
{
  double gross_income, taxable_income, tax;
  printf("Please enter your gross taxable_income for 2012: ");
  scanf("%lf", &gross_income);
  taxable_income = gross_income - 5950;
  
  if(taxable_income <= 0)
    tax = 0;
  else // taxable_income > 0
    if(taxable_income <= 8700)
      tax = taxable_income * 0.10;
    else // taxable_income > $8700
      if(taxable_income <= 35350)
        tax = 870 + 0.15 * (taxable_income - 8700);
      else  // taxable_income > $35350
        if(taxable_income <= 85650)
          tax = 4867.50 + 0.25 * (taxable_income - 35350);
        else // taxable_income > $85650
          if(taxable_income <= 178650)
            tax = 17422.50 + 0.28 * (taxable_income - 85650);
          else  // taxable_income > $178650
             if(taxable_income <= 388350)
               tax = 43482.50 + 0.33 * (taxable_income - 178650);
             else  // taxable_income > $388350
               tax = 112683.50 + 0.35 * (taxable_income - 388350);
        
  printf("The tax on $%.2lf is $%.2lf.\n", gross_income, tax);
  return 0;
} // main()

