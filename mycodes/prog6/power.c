#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_grid(int **grid);
void display_grid(int **grid);
int power_ok(int **grid);
void where_off(int **grid);

int main(int argc, char const *argv[])
{
  
  int ok, **powerGrid;
  

  powerGrid = (int**)malloc(sizeof(int*)*3);

  for(int i = 0; i < 3; i++){
  	powerGrid[i] = (int*)malloc(sizeof(int)*4);
  }

  get_grid(powerGrid);
  display_grid(powerGrid);
  ok = power_ok(powerGrid);
  
  if(ok)
  	printf("Power is on through out the grid.\n");
  else
  	where_off(powerGrid);

  // free the malloc
  // 
  for(int i = 0; i < 3; i++){
  	free(powerGrid[i]);
  }

  free(powerGrid);

  return 0;
}


void where_off(int **grid){


  printf("Power is off in sectors: \n");

  for(int i = 0; i < 3; i++){
  	for(int j = 0; j < 4; j++){
      if(grid[i][j] == 0)
       printf("      (%d,%d)\n", i, j);
    }     
  }

  printf("\n");

}


int power_ok(int **grid){
  
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 4; j++){
       if(grid[i][j] == 0)
       	return 0;
    }     
  }

  return 1;
}


void display_grid(int **grid){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 4; j++){
       printf("%d ", grid[i][j]);
    }     
    printf("\n");
  }
  
  printf("\n");

}


void get_grid(int **grid){

  char fn[80];
  FILE *fp;
  int num; 

  printf("Filename: ");
  scanf("%s", fn);

  fp = fopen(fn, "r");

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 4; j++){
       fscanf(fp, "%d", &num);
       grid[i][j] = num; 
    }     
  }

  fclose(fp);
}
