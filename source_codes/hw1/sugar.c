// Author: Sean Davis

#include <stdio.h>

#define SWEETENER_PERCENTAGE 0.001
#define KILOGRAMS_PER_POUND 0.453592
int main()
{
  double mouse_sweetener, mouse_weight, dieter_sweetener;
  int goal_weight;
  printf("Amount of sweetener needed to kill the mouse (kg): ");
  scanf("%lf", &mouse_sweetener);
  printf("Weight of the mouse (kg): ");
  scanf("%lf", &mouse_weight);
  printf("Goal weight of the dieter (pounds): ");
  scanf("%d", &goal_weight);
  dieter_sweetener = mouse_sweetener * goal_weight * KILOGRAMS_PER_POUND 
    / (mouse_weight * SWEETENER_PERCENTAGE);
  printf("For a goal weight of %d pounds, you may drink %0.1lf kg of soda.\n", 
    goal_weight, dieter_sweetener);
  return 0;
} // main()

