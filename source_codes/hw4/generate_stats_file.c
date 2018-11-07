// Author: Sean Davis

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int rows, columns, row, column, seed, maximum;
  FILE *fp = fopen("stats_data.txt", "w");
  printf("Please enter the number of rows and columns: ");
  scanf("%d%d", &rows, &columns);
  printf("Please enter the maximum number: ");
  scanf("%d", &maximum);
  printf("Please enter the seed for the random number generator: ");
  scanf("%d", &seed);
  srand(seed);
  fprintf(fp, "%d\n", columns);
  
  for(row = 0; row < rows; row++)
  {
    for(column = 0; column < columns; column++)
      fprintf(fp, "%d ", rand() % (maximum + 1));
    
    fprintf(fp, "\n");
  } // for each row
  
  fclose(fp);
  return 0;
} // main()

