#include <stdio.h>
#include <stdlib.h>

void find_path(char maze[8][8], int x, int y);

int main(int argc, char const *argv[])
{

  int r, c, x, y;
  FILE *fp;

  char maze[8][8];

  fp = fopen(argv[1], "r");

  for(r = 0; r < 8; r++)
  {
    for (c = 0; c < 8; c++)
    {
      fscanf(fp, "\n%c", &maze[r][c]);
    }
  }

  x = 0;
  y = 1;

  find_path(maze, x, y);

  return 0;
}


void find_path(char maze[8][8], int x, int y){

   if(x == 7 && y == 7){
   	 printf("(%d,%d)\n", x, y);
     exit(1);
   }

   maze[x][y] = 'X';

   if(maze[x-1][y] == 'O'&& (x-1)<8 && (x-1)>=0){
     printf("(%d,%d)\n", x, y);
     find_path(maze, x-1, y);
   } // go up
   else if(maze[x][y+1] == 'O'&& (y+1)<8){
     printf("(%d,%d)\n", x, y);
     find_path(maze, x, y+1);
   }//go right
   else if(maze[x+1][y] == 'O'&& (x+1)<8){
     printf("(%d,%d)\n", x, y);
     find_path(maze, x+1, y);
   } // go down
   else if(maze[x][y-1] == 'O' && (y-1)<8 && (y-1)>=0){
     printf("(%d,%d)\n", x, y);
     find_path(maze, x, y-1);
   } //go left
   else{
     printf("No path was found.\n");
     exit(1);
   }

}
