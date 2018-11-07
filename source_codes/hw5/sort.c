// Author: Sean Davis

#include <stdio.h>

int binary_srch(int value, int array[], int size);
void read_array(int array[], int *size);
void insertion_sort(int array[], int size);

int main()
{
  int array[20], size, value, position;

  read_array(array, &size);
  insertion_sort(array, size);
  printf("\nPlease enter a value (-1 = done)> ");
  scanf("%d", &value);

  while(value != -1)
  {
    position = binary_srch(value, array, size);
    if(position == -1)
      printf("%d is not in the array.\n", value);
    else
      printf("%d is located at position %d in the array.\n", value, position);
    printf("\nPlease enter a value (-1 = done)> ");
    scanf("%d", &value);

  } // while value not -1

  return 0;
} // main()


int binary_srch(int value, int array[], int size)
{
  int bottom = 0, top = size - 1, found = 0, middle;

  while(bottom <= top && !found)
  {
    middle = (bottom + top) / 2;
    if(array[middle] == value)
      return middle;
    if(array[middle] > value)
      top = middle - 1;
    else
      bottom = middle + 1;
  } // while

  return -1;
} // binary_srch()

void read_array(int array[], int *size)
{
  int num;
  FILE *fp = fopen("data.txt", "r");
  *size = 0;
  while(fscanf(fp, "%d", &num) == 1)
    array[(*size)++] = num;

} // read_array()


void insertion_sort(int array[], int size)
{
  int i, j, temp;

  for(i = 1; i < size; i++)
  {
    temp = array[i];

    for(j = i - 1; j >= 0 && array[j] > temp; j--)
      array[j + 1] = array[j];

    array[j + 1] = temp;
    printf("Pass %2d: ", i);

    for(j = 0; j < size; j++)
      printf("%3d ", array[j]);

    printf("\n");
  } // for i
}
