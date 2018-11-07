#include <stdio.h>


int PI = 3.14159265;

int main(){

  float radius = 0, diameter = 0;
	
  printf("Please enter a diameter: ");
  scanf("%f", &diameter);

  radius = diameter/2;

  printf("The circumference of a circle with diameter %f is ", diameter);


  printf("Diameter: %f\n", diameter);


  return 0;
}
