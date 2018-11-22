// Author: Huan Wei Li

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
  char occupation[31];
  int employment; 
  double percent_of_total_employment;
  double median_hourly_wage;
  double mean_hourly_wage;
  double annual_mean_wage;
} SalaryInfo;  // declare new data type

int main()
{
  FILE *fp;
  int index;
  SalaryInfo salary;
  
  fp = fopen("salaries.dat", "rb");
  while(fp != NULL)
  {
    printf("Please enter an index (-1 = done): ");
    scanf("%d", &index);

    if(index == -1) exit(1);
    fseek(fp, index*sizeof(SalaryInfo), SEEK_SET);
    fread(&salary, sizeof(SalaryInfo), 1, fp); 

    printf("%s: ", salary.occupation);
    printf("Employment: %d, ", salary.employment);
    printf("Percent of employment %.2lf%%\n", 
      salary.percent_of_total_employment * 100);
    printf("Median hourly wage: $%.2lf, ",
      salary.median_hourly_wage);
    printf("Mean hourly wage: $%.2lf\n", 
      salary.mean_hourly_wage);
    printf("Mean annual wage: $%.0lf\n\n",
       salary.annual_mean_wage); 
  }  // loop ask for input and print out stuff 
  return 0; 
} // main()



