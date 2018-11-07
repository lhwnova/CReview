// Author: Sean Davis

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
  SalaryInfo info[1000];
  int i = 0;
  char line[1000];
  FILE *fp = fopen("salaries.csv", "r");
  fgets(line, 1000, fp);
  
  while(fgets(line, 1000, fp) != NULL)
  {
    strncpy(info[i].occupation_title,strtok(line, ","), 30);
    info[i].occupation_title[30] = '\0';
    info[i].employment = atoi(strtok(NULL, ","));
    info[i].percent_of_total_employment = atof(strtok(NULL, ","));
    info[i].mean_hourly_wage = atof(strtok(NULL, ","));
    info[i].median_hourly_wage = atof(strtok(NULL, ","));
    info[i].annual_mean_wage = atof(strtok(NULL, "\n,"));
    i++;
  }
  
  fclose(fp);
  fp = fopen("salaries.dat", "wb");
  printf("%d\n", fwrite(info, sizeof(SalaryInfo), i, fp));
  fclose(fp);
  return 0;
} // main()

