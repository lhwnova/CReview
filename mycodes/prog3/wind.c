#include <stdio.h>


int main(){

  int windVelocity;

  printf("Please enter the wind velocity in knots: ");
  scanf("%d", &windVelocity);

  if(windVelocity < 1){
  	printf("The air is calm.\n");
  }

  if(windVelocity >= 1 && windVelocity <= 3){
  	printf("The air is light air.\n");
  }

  if(windVelocity >= 4 && windVelocity <=27){
  	printf("The air is breeze.\n");
  }

  if(windVelocity >= 28 && windVelocity <=47){
  	printf("The air is a gale.\n");
  }

  if(windVelocity >= 48 && windVelocity <=63){
  	printf("The air is \n");
  }

  if(windVelocity > 63){
  	printf("The air is hurricane.\n");
  }

  return 0;
}