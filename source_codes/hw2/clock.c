// Author: Sean Davis

#include <stdio.h>
#include <stdlib.h>

void get_time(int *hour, int *minute, int time_num);
void show_time(int hour1, int minute1, int hour2, int minute2);

int main()
{
  int hour1, minute1, hour2, minute2;
  get_time(&hour1, &minute1, 1);
  get_time(&hour2, &minute2, 2);
  show_time(hour1, minute1, hour2, minute2);
  return 0;
} // main()

void get_time(int *hour, int *minute, int time_num)
{
  printf("Please enter time #%d in clock format: ", time_num);
  scanf("%d:%d", hour, minute);
} // get_time()

void show_time(int hour1, int minute1, int hour2, int minute2)
{
  int difference = hour1 * 60 + minute1 - hour2 * 60 - minute2;
  double hour_difference = difference;
  hour_difference = (hour_difference - (difference % 60) / 2.0) / 60;
  printf("The difference is %.0lf:%02d.\n", hour_difference, 
    abs(difference % 60));
} // show_time()
