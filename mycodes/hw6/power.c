// Author: Huan Wei Li and Cort Dalton

#include<stdio.h>
#include<stdlib.h>

void get_grid(int **grid);
void display_grid(int **grid);
int power_ok(int **grid);
void where_off(int **grid);


int main()
{
  int **grid, i, r; 

  grid = (int**) malloc(sizeof(int*) * 3);
  for(i = 0; i < 4; i++) 
    grid[i] = (int*) malloc(sizeof(int) * 4);
 
  get_grid(grid);
  display_grid(grid);
  
  if(power_ok(grid))
    printf("Power is on throughout grid.\n");
  else
    where_off(grid);

  for(r = 0; i < 3; i++)
    free(grid[r]); 

  return(0);
} // main()


void get_grid(int **grid)
{
  char fn[80];
  FILE *fp; 
  int r, c, temp;
 
  printf("Filename: ");
  scanf("%s", fn);
  
  fp = fopen(fn, "r");
  
  for(r = 0; r < 3; r++)
  {
    for(c = 0; c < 4; c++)
    {
      fscanf(fp, "%d", &temp);
      grid[r][c] = temp;
    }  // get colum grid
  } // get row grid

  fclose(fp);
}  // get_grid()


void display_grid(int **grid)
{
  int r, c;

  for(r = 0; r < 3; r++)
  {
    for(c = 0; c < 4; c++)
      printf("%-2d", grid[r][c]);
    printf("\n");
  }  // print ou the grid 

  printf("\n");
}  // diaplay_grid()


int power_ok(int **grid)
{
  int r, c;

  for(r = 0; r < 3; r++)
    for(c = 0; c < 4; c++)
      if(grid[r][c] == 0)
        return 0;
  
  return 1;
}  // power_ok()


void where_off(int **grid)
{
  int r, c, count = 0;

  for(r = 0; r < 3; r++)
    for(c = 0; c < 4; c++)
      if(grid[r][c] == 0)
      {
        count++; 
        if(count == 1)
          printf("Power is off in sectors:\n");
        printf("      (%d,%d)\n", r, c);
      }  // get where grid is zero
}  // power_ok()





