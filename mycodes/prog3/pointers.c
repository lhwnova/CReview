#include <stdio.h>

void operate(int *num1, int *num2, int *num3);
int* get_address(int time);
int check_address(int *num1, int *num2, int *num3, int *num_prt);
int get_integer();
char get_operator();
void operation(int *prt1, int *prt2, int myInteger, char operator);

int main(){

  int num1, num2, num3; 
  setvbuf(stdout, NULL, _IONBF, 0);
  printf("The addresses are num: %p, num2: %p, num3: %p\n", (void*)&num1, (void*)&num2, (void*)&num3);
  
  printf("num1: %d num2: %d num3: %d\n", num1, num2, num3);
  //printf("original num1: %d\n", num1);
  operate(&num1, &num2, &num3);

  //operate(&num1, &num2, &num3);
  //operate(&num1, &num2, &num3); 

  printf("Done\n");

  return 0;	
}

// parameter pointers point to the address of the int in main
void operate(int *num1, int *num2, int *num3){

  int *num_prt1, *num_prt2; 
  int myInteger;
  char operator;

  //printf("num1: %d\n", *num1);
  num_prt1 = get_address(1);
  //printf("num_prt1: %p\n", (void*) &num_prt1);

  //printf("num_prt1: %d\n", *num_prt1);
  //printf("%u\n", (unsigned) num_prt1);
  
  if(check_address(num1, num2, num3, num_prt1)){
    
    num_prt2 = get_address(2);
    if(check_address(num1, num2, num3, num_prt2)){
      myInteger = get_integer();
      operator = get_operator();
      //printf(">>>>> %c <<<<<<<\n", operator);
      operation(num_prt1, num_prt2, myInteger, operator);
        
    }   
  }
    
}


// not the right way to get address. 
// need 
int* get_address(int time){
  
  int *num_prt;

  printf("Please enter int address #%d: ", time);
  scanf("%p", (void **) &num_prt); 

  //printf("get addr: %p\n", (void*) &num_prt);

  return num_prt;
}


// parameter pointers num1, num2, and num3 point to the address of the int in main
int check_address(int *num1, int *num2, int *num3, int *num_prt){

  //printf("%u\n", (unsigned) num1);
  //printf("%u\n", (unsigned) num_prt);
  if(num1 == num_prt || num2 == num_prt || num3 == num_prt){
    printf("This is a valid address.\n");
    return 1;
  }

  printf("This is an invalid address.\n");
  return 0;
}


int get_integer(){
  int getNum;

  printf("Please enter an integer: ");
  scanf("%d", &getNum);


  return getNum;
}


// the \n in scanf make sure the new line is ignored. 
// can use getchar()and other alternative
//
char get_operator(){
  
  char operator;

  printf("Please enter an operator: ");
  scanf("\n%c", &operator);

  return operator;
}


void operation(int *prt1, int *prt2, int myInteger, char operator){

  switch(operator){
    case '+':
      //printf("I am here.\n");
      //printf("%u\n", (unsigned) prt1);
      *prt2 = *prt1 + myInteger; 
      break;
    case '*':
      *prt2 = *prt1 * myInteger; 
      break;
    case '=':
      *prt1 = myInteger;
      *prt2 = myInteger;
      break;
    case '%': 

      printf("First int: %d, second int: %d.\n", *prt1, *prt2);
      *prt2 = *prt1 % myInteger;
      break;
  	  
  }

  printf("First int: %d, second int: %d.\n", *prt1, *prt2);

  
}