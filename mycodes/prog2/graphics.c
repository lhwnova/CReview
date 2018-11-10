#include <stdio.h>

//preprocessor 


void rectangle();
void head();
void triangle();
void lines();
void blank_lines();



int main(){
  
  head();
  triangle();
  lines();
  blank_lines();
  
  head();
  rectangle();
  lines();
  blank_lines();

  triangle();
  rectangle();
  rectangle();
  lines();
  
  return 0;
}


void head(){
  printf(" /---\\\n""");
  printf("| 0 0 |\n");
  printf(" \\_-_/\n");

}                                                                                       

void lines(){
  printf("  /\\\n");
  printf(" /  \\\n");
  printf("/    \\\n");
}                                                                                            

void rectangle(){
  printf("|----|\n");
  printf("|    |\n");
  printf("|----|\n");
}                                                                                       

void triangle(){
 printf("  /\\\n");
 printf(" /  \\\n");
 printf("/____\\\n");

}                                                                                        


void blank_lines(){
  printf("\n\n");


}

