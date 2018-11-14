#include <stdio.h>
#include <ctype.h>
#define DONE 0
#define READ 1
#define WRITE 2

int get_choice();
void read();
void write();
void decode(const char morseCode [], int len);

const char *codes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", 
  "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...",
  "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};


int main(int argc, char const *argv[])
{
  
  int choice = 1;

   
  while(choice){
    choice = get_choice();

    if(choice == 1)
      read();
    
    if(choice == 2) 
      write();

  }


  return 0;
}

void read(){
  
  char c, input[80]; 
  int index;

  printf("Morse code: ");
  scanf("%c", &c);        // read in the '\n' from the previous input
  scanf("%c", &c);
  
  //printf("<<%c>>\n", c);
  // while not end of line
  while(c != '\n'){
    
    // morse for each letter
    index = 0;
    while(c != ' ' && c != '\n'){      
      input[index] = c;
      index = index + 1;
      scanf("%c", &c);
      //printf("here\n");
    }
    
    input[index] = '\0';
    //printf("here\n");
    decode(input, index);
    
    // print space between word
    if(c == ' '){
      scanf("%c", &c);
      if(c == ' '){
      	printf(" ");
        scanf("%c", &c);      	
      }
    }

  } 

  printf("\n\n");
}


//
// comparing letter 
void decode(const char morseCode[], int len){
  
  int i, k;
  //printf("here\n");   
  for(i = 0; i < 26; i++){
    for(k = 0; codes[i][k] == morseCode[k] && codes[i][k] != '\0'; k++){

    }
    
    if(codes[i][k] == '\0' && k == len){
      printf("%c", (i + 65));
      return;
    }
        
  }

  printf("?");
}


void write(){
  
  char inchar;
   
  printf("English message: ");
  //
  // there is '\n' from the previous input. So scanf that
  scanf("%c", &inchar);
  scanf("%c", &inchar);
  
  while(inchar != '\n'){
 
    inchar = toupper(inchar);
    
    if(isalpha(inchar)){
     
      for(int i = 0; codes[inchar % 65][i] != '\0'; i++){
        printf("%c", codes[inchar % 65][i]);   
      }
      
      printf(" ");

    }else if(inchar == ' '){
      printf(" ");	
    }else{
      printf("? ");
    }

    scanf("%c", &inchar);
  }

  printf("\n");
}


int get_choice(){

  int status = 1;
  int choice;

  do{
  	//menu
  	//
    printf("Morse Menus\n0. Done\n1. Read Morse Code.\n2. Write Morse Code.\n");
    printf("\nYour choice: ");
    scanf("%d", &choice);

    if(choice == DONE || choice == READ || choice == WRITE){
    	status = 0;
    }else{ 
      printf("Your choice: %d \n", choice);
      printf("This is not between 0 and 2.\nPlease try again.\n\n");
    }

  }while(status);
 
  return choice;
}