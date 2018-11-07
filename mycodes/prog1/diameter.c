#include <stdio.h>


double PI = 3.14159265;

int main(){

  double radius = 0, diameter = 0;
  double circumference, area, surface_area, volume;
	
  printf("Please enter a diameter: ");
  scanf("%lf", &diameter);

  radius = diameter/2.0;

  circumference = diameter * PI;
  area = PI * radius * radius;
  surface_area = 4 * PI * radius * radius;
  volume = 4 * PI * radius * radius *radius / 3;

  printf("The circumference of a circle with diameter %0.3lf is %0.2lf\n", diameter, circumference);
  printf("The area of a circle with diameter %0.2lf is %0.3lf\n", diameter, area);
  printf("The surface area of a circle with diameter %0.5lf is %0.4lf\n", diameter, surface_area);
  printf("The volume of a circle with diameter %0.4lf is %0.5lf\n", diameter, volume);


  return 0;
}
