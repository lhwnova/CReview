#include <stdio.h>
#include <math.h>
#include <string.h>

void getColor(char *c1, char *c2, char *c3);
int search(const char *color [], int size, char *band);
void print_out(int band1, int band2, int band3, char *c1, char *c2, char *c3);

int main(int argc, char const *argv[])
{

  const char *color[10] = {"black", "brown", "red", "orange",
    "yellow", "green", "blue", "violet", "gray", "white"};
	
  char color1[80], color2[50], color3[50];
  int index1, index2, index3;

  printf("Enter the colors of the resistor's three bands, beginning"
     " with\nthe band nearest the end.  Type the colors in lower case"
     " letters\nonly, NO CAPS.\n");

  getColor(color1, color2, color3);
 
  index1 = search(color, 10, color1);
  index2 = search(color, 10, color2);
  index3 = search(color, 10, color3);



  print_out(index1, index2, index3, color1, color2, color3);

  return 0;
}


void print_out(int band1, int band2, int band3, char *c1, char *c2, char *c3){

  int resistence; 
  //printf("%d  %d  %d\n", band1, band2, band3);
 
  if(band1 == -1)
  	printf("Invalid colors: %s\n", c1);
  else if (band2 == -1)
  	printf("Invalid colors: %s\n", c2);
  else if (band3 == -1)
  	printf("Invalid colors: %s\n", c3);
  else{
    
    resistence = ((band1 * 10) + band2) * pow(10, band3);
    
    if(resistence/1000 == 0)
    	printf("Resistence value: %d ohmos\n", resistence);
	else{
		resistence = resistence / 1000;
		printf("Resistence value: %d kilo-ohmos\n", resistence);
	}        

  }
}


int search(const char *color [], int size, char *band){
   
  int i; 

  for(i = 0; i < size; i++){

  	// color and band is pointer; strcmp take in two string as parameter
  	// string is pass by reference like array
  	// so pass pointer as parameter in strcmp
    if(strcmp(color[i], band) == 0)
    	return i; 
  }

  return -1;
}



void getColor(char *c1, char *c2, char *c3){
  
  printf("Band 1 => ");
  scanf("%s", c1);

  printf("Band 2 => ");
  scanf("%s", c2);

  printf("Band 3 => ");
  scanf("%s", c3);

}
