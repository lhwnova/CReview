// do-while and for loop 



#include <stdio.h>

int is_prime(int number);

int main(){
 
  int num1, num2;

  do{
  	printf("Please enter two integers greater than one, and in ascending order: ");
    scanf("%d %d", &num1, &num2);

    if(num1 <= 1 || num2 <= 1){
      printf("The numbers must both be greater than one.\n");
    }else{
      if(num1 > num2){
      	printf("The numbers must be in ascending order.\n");
      }else{
      	break;
      }
       
    }


    printf("Please try again\n");
  }while(1);

  for(int i = num1; i < (num2+1); i++){
  	if(is_prime(i))
  	 printf("%d ", i);
  }
  
  printf("\n");

  return 0;	
}


int is_prime(int number){
  
  for(int i = 2; i < number; i++){
  	if(number%i == 0)
  		return 0;
  }

  return 1;
}