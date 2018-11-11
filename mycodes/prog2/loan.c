// use "gcc -Wall -lm" because the math.h 
// -Wall means show all warning


#include <stdio.h>
#include <math.h>

void get_loan(double *loanAmount, double *interest, int *monthTilPayment, int *monthWishForPayment);
void calc_payments(int loan, double interest, int monthTilPayment, int monthWishForPayment, double *monthlyPay, double *totalPayment);
void show_totals(double monthlyPay, double totalPayment);


int main(){

  int monthTilPayment, monthWishForPayment;
  double loan, interest, monthlyPay, totalPayment;

  get_loan(&loan, &interest, &monthTilPayment, &monthWishForPayment);
  calc_payments(loan, interest, monthTilPayment, monthWishForPayment, &monthlyPay, &totalPayment);
  show_totals(monthlyPay, totalPayment);


  return 0;	
}


void get_loan(double *loanAmount, double *interest, int *monthTilPayment, int *monthWishForPayment){

  printf("Please enter the loan, and interest: ");
  scanf("%lf %lf", loanAmount, interest);
  
  printf("Please enter the number of months until you start payments: ");
  scanf("%d", monthTilPayment);

  printf("Please enter the number of payments you wish to make: ");
  scanf("%d", monthWishForPayment);
 

}

void calc_payments(int loan, double interest, int monthTilPayment, int monthWishForPayment, double *monthlyPay, double *totalPayment){

  double fullLoan; 
 
  fullLoan = loan * pow(1 + interest / 12, monthTilPayment);
  *monthlyPay = (fullLoan * interest / 12) / (1 - exp(-monthWishForPayment * log(1 + interest /12)));
  *totalPayment = monthWishForPayment * *monthlyPay;
  
}



void show_totals(double monthlyPay, double totalPayment){

	printf("For that loan, your monthly payment will be $%0.2lf, for a total of $%0.2lf.\n", monthlyPay, totalPayment);
}