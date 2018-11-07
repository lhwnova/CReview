// Author: Sean Davis

#include <stdio.h>
#include <math.h>
void get_loan(double *loan, double*interest, int *months, int *college_months);
void calc_payments(double loan, double interest, int months, int college_months, 
  double *payment, double *total);
void show_totals(double payment, double total);


int main()
{
  double loan, interest, total, payment;
  int num_payments, college_months;
  get_loan(&loan, &interest, &num_payments, &college_months);
  calc_payments(loan, interest, num_payments, college_months, &payment, &total);
  show_totals(payment, total);
  return 0;
} // main()

 void get_loan(double *loan, double*interest, int *num_payments, int *college_months)
 {
   printf("Please enter the loan, and interest: ");
   scanf("%lf%lf", loan, interest);
   printf("Please enter the number of months until you start payments: ");
   scanf("%d", college_months);
   printf("Please enter the number of payments you wish to make: ");
   scanf("%d", num_payments);
 } // get_loan()
 
 void calc_payments(double loan, double interest, int num_payments, int college_months, 
    double *payment, double *total)
 {
   double full_loan;
   full_loan = loan * pow(1 + interest / 12, college_months);
   *payment = (full_loan  * interest / 12) 
     / (1 - exp(-num_payments * log(1 + interest / 12)));
   *total = num_payments * *payment;
 } // calc_payments()
 
 void show_totals(double payment, double total)
 {
   printf("For that loan, your monthly payment will be $%0.2lf, ", payment);
   printf("for a total of $%0.2lf.\n", total);
 } // show_totals()
