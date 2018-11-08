#include <stdio.h>

int main(){
  
  int num;
  char c1, c2;
  
  printf("Please enter two characters and an integer: ");
  scanf("%c%c%d", &c1, &c2, &num);

  printf("c1 + c2 = %c (char), %d (int).\n", c1+c2, c1+c2);
  printf("c1 - c2 = %c (char), %d (int).\n", c1-c2, c1-c2); 
  printf("c1 + num = %c (char), %d (int).\n", c1+num, c1+num); 
  
  return 0; 
}
