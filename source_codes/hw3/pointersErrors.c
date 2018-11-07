// Author: Sean Davis

#include <stdio.h>

int check_address(int *ptr, int *num_ptr, int *num2_ptr, int *num3_ptr);
void operate(int *num, int *num2, int *num3);
int* read_address(int position);
char read_operator();
int read_operand();
void run_operation(int *ptr1, int *ptr2, int operand, char operator);

int main()
{
  int num, num2, num3;
  setvbuf(stdout, NULL, _IONBF, 0);
  printf("The addresses are num: %u, num2: %u, num3: %u\n", (unsigned) &num, (unsigned) &num2, (unsigned) &num3);
  operate(&num, &num2, &num3);
  operate(&num, &num2, &num3);
  operate(&num, &num2, &num3);  
  printf("Done\n");
  return 0;
} // main()


void operate(int *num, int *num2, int *num3)
{
  int *ptr1, *ptr2, operand;
  char operator;
  ptr1 = read_address(1);
  
  if(check_address(ptr1, num, num2, num3) && (ptr2 = read_address(2)) && 
    check_address(ptr2, num, num2, num3))
  {
    operand = read_operand();
    operator = read_operator();
    run_operation(ptr1, ptr2, operand, operator);
  } // if addresses valid
}  // operate()


void run_operation(int *ptr1, int *ptr2, int operand, char operator)
{
  switch(operator)
  {
    case '+' : *ptr2 = *ptr1 + operand + 1; break;
    case '*' : *ptr2 = *ptr1 * operand; break;
    case '=' : *ptr1 = *ptr2 = operand; break;
    case '%' : *ptr2 = operand % *ptr1; break;
    default:
      printf("%c is an invalid operator.\n", operator);
      return;
  }  // switch on operator
  
  printf("First int: %d, second int: %d.\n", *ptr1, *ptr2);
}  // run_operation()

int read_operand()
{
  int operand;
  printf("Please enter an integer: ");
  scanf("%d", &operand);
  return operand;
}  // read_operand()


int check_address(int *ptr, int *num_ptr, int *num2_ptr, int *num3_ptr)
{
  if(ptr == num_ptr || ptr == num2_ptr || ptr == num3_ptr)
  {
    printf("That is a valid address.\n");
    return 1;
  } // if valid address
  else // invalid address
  {
    printf("That is a invalid address.\n");
    return 0;
  }  // else invalid
}  // check_address()


char read_operator()
{
  char operator;
  printf("Please enter an operator: ");
  scanf("\n%c", &operator);
  return operator;
} // read_operator()


int* read_address(int position)
{
  int *ptr;
  printf("Please enter int address #%d: ", position);
  scanf("%u", (unsigned*) &ptr);
  
  if(ptr == 0)
    ptr = (int*) 1;
  
  return ptr;
}  // read_address()
