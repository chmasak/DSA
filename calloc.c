#include <stdio.h>
#include <stdlib.h>
int main() {
  int n, i, *ptr, sum = 0;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  ptr = (int*) calloc(n , sizeof(int));
  if(ptr == NULL) {
    printf("Error! memory not allocated.");
    exit(0);
  }
  printf("Enter elements: ");
  for(i = 0; i < n; ++i) {
    scanf("%d", ptr + i);
  }
  printf("The elements are: ");
  for(i = 0; i < n; ++i) {
    printf("%d ", *(ptr + i));
  }
free(ptr);
return 0;
}
