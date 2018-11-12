#include <stdio.h>

int main(){
  
  int num; 

  printf("Please enter a number between 0 and 99: ");
  scanf("%d", &num);
  printf("In English, that is ");
  


  if(num >= 10 && num <= 19){
    switch(num){
      case 10: printf("ten."); break;
      case 11: printf("eleven."); break;
      case 12: printf("twelve."); break;
      case 13: printf("thirteen."); break;
      case 14: printf("fourteen."); break;
      case 15: printf("fifteen."); break;
      case 16: printf("sixteen."); break;
      case 17: printf("seventheen."); break;
      case 18: printf("eighteen."); break;
      case 19: printf("ninteen."); break;
    }
  }else{
    switch(num/10){
      case 9: printf("ninty-"); break;
      case 8: printf("eighty-"); break;
      case 7: printf("seventy-"); break;
      case 6: printf("sixty-"); break;
      case 5: printf("fifty-"); break;
      case 4: printf("forty-"); break;
      case 3: printf("thirty-"); break;
      case 2: printf("twenty-"); break;
    }

    num = num - (num/10 * 10);

    switch(num){
      case 0: printf("zero."); break;
      case 1: printf("one."); break;
      case 2: printf("two."); break;
      case 3: printf("three."); break;
      case 4: printf("four."); break;
      case 5: printf("five."); break;
      case 6: printf("six."); break;
      case 7: printf("seven."); break;
      case 8: printf("eight."); break;
      case 9: printf("nine."); break;
    }
  }

  printf("\n");

  return 0;
}