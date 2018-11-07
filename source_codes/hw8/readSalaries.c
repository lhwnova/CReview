// Author: Sean Davis

#include <stdio.h>
// Author: Sean Davis

#include <stdio.h>

typedef struct 
{
  char occupation_title[31];
  int employment;
	double percent_of_total_employment;	
  double median_hourly_wage;
  double mean_hourly_wage;
  double annual_mean_wage;	
} SalaryInfo;

int main()
{
  int index;
  SalaryInfo info;
  FILE *fp = fopen("salaries.dat", "rb");
  
  do
  {
    printf("Please enter an index (-1 = done): ");
    scanf("%d", &index);
    if(index >= 0)
    {
      fseek(fp, index * sizeof(SalaryInfo), SEEK_SET);
      fread(&info, sizeof(SalaryInfo),1, fp);
      printf("%s: Employment: %d, Percent of employment %.2lf%%\n", 
        info.occupation_title, info.employment,
        info.percent_of_total_employment * 100);
      printf("Median hourly wage: $%.2lf, Mean hourly wage: $%.2lf\n",
        info.median_hourly_wage, info.mean_hourly_wage);
      printf("Mean annual wage: $%.0lf\n\n", info.annual_mean_wage);
    } // if index
  } while(index >= 0);
  
  
  return 0;
} // main()

