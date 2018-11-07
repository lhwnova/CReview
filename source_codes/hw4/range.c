// Author: Sean Davis

#include <stdio.h>
#include <float.h>
double get_double(double n_min, double n_max);

int main()
{
  double min, max, num;
  min = get_double(-DBL_MAX, DBL_MAX);
  max = get_double(min, DBL_MAX);
  num = get_double(min, max);
  printf("min: %.8g, max: %.4g, input: %.4g are all OK.\n", min, max, num);
  return 0;
} // main()


// Returns the first integer between n_min and n_max entered as data.

double get_double(double n_min, double n_max)
{
  double in_val;  // input  - number entered by user
  char skip_ch;    // character used for skipping balance of line
  int error;    // error flag for bad input
  
  do 
  {
    error = 0; // No errors yet
    printf("Enter a double in the range from %.8g ", n_min);
    printf("to %.8g inclusive> ", n_max);
    scanf("%lf", &in_val);
    scanf("%c", &skip_ch);

    if(skip_ch != '\n') // in_val didn't get a number
    {
      error = 1;
      printf("Invalid character >>%c>>. ", skip_ch);
      printf("Skipping rest of line.\n");
    }  // if scanf() failed to read anything
    else
      if(in_val < n_min)
      {
        error = 1;
        printf("Number %.8g is too small.\n", in_val);
      }
      else
        if(in_val > n_max)
       {
          error = 1;
          printf("Number %.8g is too large.\n", in_val);
        } // if number out of range
    
    while(skip_ch != '\n')  // skip rest of line
      scanf("%c", & skip_ch);
  
  } while(error);
  
  return in_val;
} // get_int()
