// Author: Sean Davis

#include <stdio.h>
#include <math.h>

void compute_line_stats(FILE *fp, int columns, double *average, int num);
FILE* compute_stats(double *average);
void calc_standard_deviation(FILE *fp, double *sd, double average);
void calc_pct(FILE *fp, double sd, double average);


int main()
{
  double average = 0, sd;
  FILE *fp = compute_stats(&average);
  calc_standard_deviation(fp, &sd, average);
  return 0;
} // main()



void calc_standard_deviation(FILE *fp, double *sd, double average)
{
  int num, count = 0;
  *sd = 0;
  rewind(fp);
  
  while(fscanf(fp, "%d", &num) != EOF)
  {
    *sd += (num - average) * (num - average);
    count++;
  }  // while more in file
  
  *sd = sqrt(*sd / (count - 1));
  
  printf("Average: %.2lf Standard deviation: %.2lf\n", average, *sd);
} // calc_standard_deviation()


FILE* compute_stats(double *average)
{
  int columns, num, row = 0;
  FILE *fp = fopen("stats_data.txt", "r");
  int count = 1;
  fscanf(fp, "%d", &columns);
  *average = columns;
  
  while(fscanf(fp, "%d", &num) != EOF)
  {
    compute_line_stats(fp, columns, average, num);
    count += columns;
    if(++row %2 == 0)
      printf("\n");
  }  // while more in the file
  
  if(row % 2 != 0)
    printf("\n");
  
  *average /= (row * columns + 1);
  return fp;
} // compute_stats()

void compute_line_stats(FILE *fp, int columns, double *average, int num)
{
  int col, minimum, maximum;
  double line_average;
  line_average = maximum = minimum = num;
  
  for(col = 1; col < columns; col++)
  {
    fscanf(fp, "%d", &num);
    line_average += num;
    
    if(num < minimum)
      minimum = num;
    
    if(num > maximum)
      maximum = num;
  }  // for col

  *average += line_average;
  printf("min: %-3d max: %-3d avg: %-6.2lf ", minimum, maximum, 
    line_average / columns);
}  // compute_stats()
