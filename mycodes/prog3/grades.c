// switch statement

#include <stdio.h>

int main(){

  int grade; 
  char letterGrade;

  printf("Please enter a test score: ");
  scanf("%d", &grade);

  switch(grade){
    case 90 ... 100:  
 	  letterGrade = 'A';
 	  break;
    case 80 ... 89:
 	  letterGrade = 'B';
 	  break;
    case 70 ... 79:
  	  letterGrade = 'C';
  	  break;
    case 60 ... 69:
      letterGrade = 'D';
      break;
    case 0 ... 59:
      letterGrade = 'F';


  }

  printf("letter grade: %c\n", letterGrade);

  return 0;	
}
