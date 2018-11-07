// Author: Sean Davis

#include <stdio.h>
#define PI 3.14159265

int main()
{
  double diameter;
  printf("please enter a diameter: ");
  scanf("%lf", &diameter);
  printf("The circumference of a circle with diameter %0.4lf is %0.2lf.\n", 
    diameter, PI * diameter);
  printf("The area of a circle with diameter %0.2lf is %0.3lf.\n",
    diameter, PI * (diameter / 2) * (diameter / 2));
  printf("The surface area of a sphere with diameter %0.5lf is %0.4lf.\n",
    diameter, 4 * PI * (diameter / 2) * (diameter / 2.5));
  printf("The volume of a sphere with diameter %0.4lf is %0.5lf.\n",
    diameter, 4 * PI * (diameter / 2) * (diameter / 2) * (diameter / 2) / 3);
  return 0;
} // main()

