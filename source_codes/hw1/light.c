// Author: Sean Davis

#include <stdio.h>
#define SPEED_OF_LIGHT 299792458

int main()
{
  unsigned frequency, distance2;
  double distance;
  printf("Frequency of the CPU (Hz): ");
  scanf("%u", &frequency);
  distance = 1000.0 * SPEED_OF_LIGHT / frequency;
  printf("Electricity can travel %0.0lf millimeters in one cycle of a CPU that",
    distance);
  printf(" has\n");
  printf("a frequency of %u Hz.\n", frequency);
  distance2 = (SPEED_OF_LIGHT / (frequency / 1000));
  printf("Using only integers, that is %u millimeters.\n", distance2);
  return 0;
} // main()

