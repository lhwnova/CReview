#include <stdio.h>

int binary_search(int darrary [], int size, int num);
void insertion_sort(int darrary [], int size);
void readFile(int darrary [], int *size);

int main(int argc, char const *argv[])
{

  int num, index, ar[80], size = 0;
  
  readFile(ar, &size);
	insertion_sort(ar, size);
  

  printf("Please enter a value (-1 = done)> ");
  scanf("%d", &num);
  while(num != -1){

    index = binary_search(ar, size, num);
    
    if(index == -1)
      printf("%d is not found.\n", num);
    else
    printf("%d is at position %d in the arrary.\n", num, index);

    printf("Please enter a value (-1 = done)> ");
    scanf("%d", &num);
  }
  

  return 0;
}

int binary_search(int darrary [], int size, int num){

  int min, max, mid; 

  min = 0;
  max = size - 1;
  
  while(min <= max){

    mid = (min + max)/2;

    if(darrary[mid] == num)
      return mid;
    else if(num > darrary[mid])
      min = mid + 1;
    else if(num < darrary[mid])
       max = mid - 1;

  }

  return -1;
}

void insertion_sort(int darrary [], int size){

  
  int k, j, temp;

  for(k = 1; k < size; k++){
    
    temp = darrary[k]; 
    
    for (j = k - 1; j >= 0 && temp < darrary[j]; j--)
    {
      darrary[j + 1] = darrary[j]; 
      
    }

    darrary[j + 1] = temp;

    printf("Pass %d: ", k);
    for(int i = 0; i < size; i++)
      printf("%d ", darrary[i]);
     
    printf("\n");
  }
}



void readFile(int darrary [], int *size){

  FILE *fp = fopen("data.txt", "r");
  int num;

  
  while(fscanf(fp, "%d", &num) == 1){
    darrary[*size] = num;
    *size = *size + 1;
  }

  fclose(fp);
}