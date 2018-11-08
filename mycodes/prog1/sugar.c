// global variables
// 


#include <stdio.h>
#define ONE_PER_KILO 0.453592
#define SWEETENER_PER 0.001

int main(){

  double mouse_sugar, mouse_weight, dieter_sugar;  
  int dieter_weight; 

  printf("Amount of sweetener needed to kill the mouse (kg): "); 
  scanf("%lf", &mouse_sugar);
  printf("Weight of the mouse (kg): ");
  scanf("%lf", &mouse_weight);
  printf("Goal weight of the dieter(pound): ");
  scanf("%d", &dieter_weight);
  
  dieter_sugar = mouse_sugar * dieter_weight * ONE_PER_KILO / (mouse_weight * SWEETENER_PER);
  
  printf("For a goal weight of %d pounds, you may drink %0.1lf kg of soda.\n", dieter_weight, dieter_sugar); 
  

  return 0;

}
