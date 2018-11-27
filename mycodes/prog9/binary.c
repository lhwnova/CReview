#include <stdio.h>

void binary(char *bin, int pos);

int main(int argc, char const *argv[])
{
	
  char bin[80];

  printf("Binary number: ");
  scanf("%s", bin);
  binary(bin, 0);

  return 0;
}


void binary(char *bin, int pos){

  if(bin[pos] == '\0'){
  	printf("%s\n", bin);
  }else if(bin[pos] != 'x'){
  	binary(bin, pos+1);
  }else{
    bin[pos] = '0';
    binary(bin, pos+1);
    bin[pos] = '1';
    binary(bin, pos+1);
    bin[pos] = 'x'; //change it back after working with it.


  }

}