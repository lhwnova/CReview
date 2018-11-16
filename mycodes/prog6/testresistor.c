// Author: Huan Wei Li 
 
#include<stdio.h>
#include<math.h>
#include<string.h>

int search(const char *color[], int len, char *key);
void get_color(char *key1, char *key2, char *key3); 
void print_out(int ind1, int ind2, int ind3, char *c1, char *c2, 
  char *c3);


int main()
{
  const char *color[10] = {"black", "brown", "red", "orange",
    "yellow", "green", "blue", "violet", "gray", "white"};
  char c1[50], c2[50], c3[50], input; 
  int index1, index2, index3, error = 1; 
 
  while(error) 
  {
    printf("Enter the colors of the resistor's three bands, beginning"
    " with the band nearest the end. Type the colors in the lower case"
    " letters only, NO CAPS.\n");
    
    get_color(c1, c2, c3);   

    index1 = search(color, 10, c1);
    index2 = search(color, 10, c2);
    index3 = search(color, 10, c3);

    print_out(index1, index2, index3, c1, c2, c3); 

    printf("Do you want to decode another resistor?\n=> ");
    scanf("\n%c", &input);

    if(input == 'n') error = 0; 
  }
  
  return(0); 
} // main()


void get_color(char *key1, char *key2, char *key3)
{
  printf("Band 1 => "); 
  scanf("%s", key1); 

  printf("Band 2 => "); 
  scanf("%s", key2); 

  printf("Band 3 => "); 
  scanf("%s", key3); 
}


int search(const char *color[], int len, char *key)
{
  int i; 
 
  for(i = 0; i < len; i++)
    if(strcmp(key, color[i]) == 0)
      return i; 
 
  return(-1);
}  // search()


void print_out(int ind1, int ind2, int ind3, char *c1, char *c2, char *c3)
{
  int resistence; 

  if(ind1 == -1) printf("Invalid color: %s\n", c1);
  else
    if(ind2 == -1) printf("Invalid color: %s\n", c2);
    else
      if(ind3 == -1) printf("Invalid color: %s\n", c3); 
      else
      {
        resistence = ((ind1 * 10) + ind2) * pow(10, ind3); 
        if((resistence / 1000) > 0) 
	{
          resistence = resistence / 1000;
          printf("Resistence value: %4d kilo-ohms\n", resistence);
        }
        else
          printf("Resistence value: %4d ohmos\n", resistence);
      }
}  // print_out()

