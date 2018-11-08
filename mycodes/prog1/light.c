// using unsigned integer 


#include <stdio.h>
#define SPEED_OF_LIGHT 299792458


int main(){
  
  double travel_distance;

  unsigned int cpu_freq, travel_distance2;   


  printf("Frequency of the CPU (Hz): ");
  scanf("%d", &cpu_freq);

  travel_distance = 1000.0 * SPEED_OF_LIGHT / cpu_freq;

  printf("Electricity can travel %0.0lf millimeters in one cycle of a CPU that has a frequency of %d Hz.\n", travel_distance, cpu_freq);

  travel_distance2 = (SPEED_OF_LIGHT / (cpu_freq / 1000));
  printf("Using only integers, that is %u millimeters. \n", travel_distance2);

  return 0;
}
