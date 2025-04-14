#include <stdio.h>
int swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int bubblesort(int a[], int n)
{
    int i,j,temp;
    //sorting
    for( i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]<a[j+1])
            {
                swap(&a[j],&a[j+1]); //call by ref
            }
        }
    }
    //printing
    printf("\nSorted array: \t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
int main()
{
    int i, x, flag = 0;
    const int n=5;

    //entering elements of array
  
    int a[n];
    printf("\nEnter elements of array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array:\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    //bubble sort
    bubblesort(a,n);
}