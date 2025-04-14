#include <stdio.h>
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
// partition position
int partition(int array[], int low, int high)
{
  int pivot = array[high];
  int i = (low - 1);
  // traversing each element and compare them with pivot
  for (int j = low; j < high; j++)
  {
    if (array[j] >= pivot) 
    {
      i++;
      // swapping element at i with element at j
      swap(&array[i], &array[j]);
    }
  }
  // placing pivot at correct position
  swap(&array[i + 1], &array[high]);
  // return the partition point
  return (i + 1);
}
void quickSort(int array[], int low, int high) {
  if (low < high)
  {
    int pi = partition(array, low, high);
    // left recursion
    quickSort(array, low, pi - 1);
    // right recursion
    quickSort(array, pi + 1, high);
  }
}
// array print function
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
// main function
int main()
{
  const int n=5;
    //entering elements of array
  int arr[n],i;
  printf("\nEnter elements of array: ");
  for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }    
  printf("Unsorted Array\n");
  printArray(arr, n);
  // quicksort 
  quickSort(arr, 0, n - 1);
  printf("Sorted array in ascending order: \n");
  printArray(arr, n);
}