// Author: Sean Davis

#include <stdio.h>

void tens(int number);
void ones(int number);
void teens(int number);

int main()
{
  int number;
  printf("Please enter a number between 0 and 99: ");
  scanf("%d", &number);
  printf("In English, that is ");
  tens(number);
  
  if(number > 19 && number % 10 != 0)
    printf("-");
  
  if(number < 10 || number > 20)
    ones(number);
  
  if(number == 0)
    printf("zero");
      
  printf(".\n");
  return 0;
} // main()


void tens(int number)
{
  switch(number / 10)
  {
    case 9 : printf("ninety"); break;
    case 8 : printf("eighty"); break;
    case 7 : printf("seventy"); break;
    case 6 : printf ("sixty"); break;
    case 5 : printf("fifty"); break;
    case 4 : printf("forty"); break;
    case 3 : printf ("thirty"); break; 
    case 2 : printf("twenty"); break;
    case 1 : teens(number); break;
  } // switch on tens digit
}  // tens()


void teens(int number)
{
  switch(number % 10)
  {
    case 9: printf("nineteen"); break;
    case 8: printf("eighteen"); break;
    case 7: printf("seventeen"); break;
    case 6: printf("sixteen"); break;
    case 5: printf("fifteen"); break;
    case 4: printf("fourteen"); break;
    case 3: printf("thirteen"); break;
    case 2: printf("twelve"); break;
    case 1: printf("eleven"); break;
    case 0: printf("ten"); break;
  } // switch on ones
} // teens()


void ones(int number)
{
  switch(number % 10)
  { 
    case 9: printf("nine"); break;
    case 8: printf("eight"); break;
    case 7: printf("seven"); break;
    case 6: printf("six"); break;
    case 5: printf("five"); break;
    case 4: printf("four"); break;
    case 3: printf("three"); break;
    case 2: printf("two"); break;
    case 1: printf("one"); break;
  } // switch on ones digit  
} // ones()
