// loop an condition

// scanf()
//    -scanf by value type, whitespace. 
//    -return null or 0 if scanf is not exeexuted.
//

#include <stdio.h>
#include <float.h>


int get_int(int n_min, int n_max);
double get_double(double n_min, double n_max);

int main(int argc, char const *argv[])
{
  
  double min, max, num; 

  min = get_double(-DBL_MIN, DBL_MAX);
  max = get_double(min, DBL_MAX);
  num = get_double(min, max);

  printf("Min: %0.8lf Max: %0.8lf input: %0.8lf \n", min, max, num);
  
  return 0;
}


double get_double(double n_min, double n_max){
  
  double inputval; // input - number entered by user
  //double status;   // status value returned by scanf
  char skip_ch;    // character used for skipping balance of line
  int error;       // error flag for bad input

  do{
    
    error = 0; // No errors yet
    printf("Enter a double in the range from %0.8g to %0.8g inclusive> ", n_min, n_max);

    scanf("%lf", &inputval);
    scanf("%c", &skip_ch);

    if(skip_ch != '\n') // inputval didn't get a number
    {
      error = 1;
      printf("Invalid character >>%c>>. ", skip_ch);
      printf("Skipping rest of line.\n");
    } // if scanf() failed to read anything
    else{

      if(inputval < n_min)
      {
        error = 1;
        printf("Number %lf is too small.\n", inputval);
      } // if number out of range
      else if(inputval > n_max)
      {
        error = 1;
        printf("Number %lf is too large.\n", inputval);   
      }

    }

    //
    //
    // clear the line in the input stream, 
    // so it does not get the '\n' at the end for the other printf later
    //
    while(skip_ch != '\n')
    	scanf("%c", &skip_ch);
T

  }while(error);
  

  return inputval;
}

//
// int example
int get_int(int n_min, int n_max)
{
  int inputval, // input - number entered by user
  status;
  // status value returned by scanf
  char skip_ch;
  // character used for skipping balance of line
  int error;
  // error flag for bad input
  do
  {
    error = 0; // No errors yet
    printf("Enter an integer in the range from %d ", n_min);
    printf("to %d inclusive> ", n_max);
    status = scanf("%d", &inputval);
    if(status != 1) // inputval didn't get a number
    {
      error = 1;
      scanf("%c", &skip_ch);
      printf("Invalid character >>%c>>. ", skip_ch);
      printf("Skipping rest of line.\n");
    } // if scanf() failed to read anything
    else if(inputval < n_min || inputval > n_max)
    {
      error = 1;
      printf("Number %d is not in range.\n", inputval);
    } // if number out of range
    
    do
      // skip rest of line
      scanf("%c", & skip_ch);
    while(skip_ch != '\n');


  } while(error);
  return inputval;
} // get_int()



