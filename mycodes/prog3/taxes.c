#include <stdio.h>


int main(){
  
  double income, taxes;
  

  printf("Please enter your gross taxable_income for 201x: ");
  scanf("%lf", &income);
  income = income - 5950;

  if(income <= 0){
    taxes = 0;
  }else{
    if(income <= 8700){
      taxes = income * 0.1;
    }else{
      if(income > 8700 && income <= 35350){
        taxes = 870 + 0.15*(income - 8700);     
      }else{
        if(income > 35350 && income <= 85650){
          taxes = 4867.50 + 0.25*(income - 35350);
          printf("Here\n");
        }else{
          if(income > 85650 && income <= 178650){
            taxes = 17422.50 + 0.28 * (income - 85650);
            printf("%lf    %lf\n", 0.28*(income - 85650) + 17422.50, taxes);
          }else{
            if(income > 178650 && income <= 388350){
 		      taxes = 43482.50 + 0.33*(income - 178650);
 		      printf("Here\n");
            }else{
              if(income > 388350){
 		        taxes = 112683.50 + 0.35*(income - 388350);
              }
            }    
          }
        }
      }
    }
  }

  printf("The taxes in $%0.2lf is $%0.2lf\n", income, taxes);


  

  return 0;
}