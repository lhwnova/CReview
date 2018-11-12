#include <stdio.h>
#include <math.h>



FILE* read_file();
void get_line_stat(FILE *fp, int lineSize, int firstNum);
void get_average(FILE *fp, double *average);
void get_sd(FILE * fp, double average, double *sd);

int main(){

  double sd, average; 
   
  FILE * filePtr = read_file();
  
  rewind(filePtr);
  get_average(filePtr, &average); 

  printf("Average: %0.2lf\n", average);

  rewind(filePtr);
  get_sd(filePtr, average, &sd);  
  printf("Standard deviation: %0.2lf\n", sd);
  
  fclose(filePtr);

  return 0;
}


void get_sd(FILE * fp, double average, double *sd){
  
  int num;
  int lineSize, totalNum = 0; 

  fscanf(fp, "%d", &lineSize); 
 
  while(fscanf(fp, "%d", &num) != EOF){
    totalNum = totalNum + 1;
    
    *sd = *sd + (num - average)*(num - average);
  }
 

  *sd = sqrt(*sd / (totalNum - 1));

}


void get_average(FILE *fp, double *average){
  
  int num, sum = 0;
  int lineSize, totalNum = 0; 

  fscanf(fp, "%d", &lineSize); 
 
  while(fscanf(fp, "%d", &num) != EOF){
    totalNum = totalNum + 1;
    sum = sum + num;
  }
 
 
  *average = (double)sum / totalNum; 

}


FILE* read_file(){

  FILE *fp = fopen("stats_data.txt", "r");
  int firstNum;
  int lineSize; 

  fscanf(fp, "%d", &lineSize); 
 
  while(fscanf(fp, "%d", &firstNum) != EOF){

    get_line_stat(fp, lineSize, firstNum);
  }
 
 
  return fp; 
}


void get_line_stat(FILE *fp, int lineSize, int firstNum){
  
  int sum = firstNum;
  int max = firstNum;
  int min = firstNum;
  int num;
  double avg;

  for(int i = 1; i < lineSize; i++){
    fscanf(fp, "%d", &num);
    
    if(num < min)
      min = num;

    if(num > max)
      max = num;

    sum = sum + num;   
  }

  avg = (double)sum / lineSize;

  printf("min: %d mac: %d avg: %0.2lf \n", min, max, avg);
 
}

