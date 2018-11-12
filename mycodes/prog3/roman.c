#include <stdio.h>

int main(){

  int num;

  printf("Please enter a number between 1 and 3999: ");
  scanf("%d", &num);

  printf("In roman numerals that is ");

  switch(num / 1000){
    case 1: printf("M"); break;
    case 2: printf("MM"); break;
    case 3: printf("MMM"); break;
  }

  num = num - (num/1000 * 1000);

  switch(num /100){
    case 9: printf("CM"); break;
    case 8: printf("DCCC"); break;
    case 7: printf("DCC"); break;
    case 6: printf("DC"); break;
    case 5: printf("D"); break;
    case 4: printf("CD"); break;
    case 3: printf("CCC"); break;
    case 2: printf("CC"); break;
    case 1: printf("C"); break;
  }

  num = num - (num/100 * 100);

  switch(num/10){
    case 9: printf("XC"); break;
    case 8: printf("LXXX"); break;
    case 7: printf("LXX"); break;
    case 6: printf("LX"); break;
    case 5: printf("L"); break;
    case 4: printf("XL"); break;
    case 3: printf("XXX"); break;
    case 2: printf("XX"); break;
    case 1: printf("X"); break;
  }

  num = num - (num/10 * 10);

  switch(num){
    case 9: printf("IX"); break;
    case 8: printf("VIII"); break;
    case 7: printf("VII"); break;
    case 6: printf("VI"); break;
    case 5: printf("V"); break;
    case 4: printf("IV"); break;
    case 3: printf("III"); break;
    case 2: printf("II"); break;
    case 1: printf("I"); break;

  }

  printf("\n");

  return 0;	
}