#include <stdio.h>
#include <stdlib.h>

void get_time(int *hour, int *minute, int counter);
void show_difference(int hour1, int hour2, int min1, int min2);


int main(){
  
  int hour1, min1, hour2, min2;

  get_time(&hour1, &min1, 1);
  get_time(&hour2, &min2, 2);
  
  show_difference(hour1, hour2, min1, min2);

  return 0;
}


void get_time(int *hour, int *minute, int counter){
  
  printf("Please enter time #%d in clock format: ", counter);
  scanf("%d:%d", hour, minute);

}

void show_difference(int hour1, int hour2, int min1, int min2){

  int min_diff = abs(min1 - min2);
  int hour_diff = hour1 - hour2; 

  printf("The difference is: %d:%02d.\n", hour_diff, min_diff);
}