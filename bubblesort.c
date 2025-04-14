#include <stdio.h>
int bubblesort(int a[], int n)
{
    int i,j,temp;
    //sorting
    for( i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
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
    int i, x, n, flag = 0;
    //entering elements of array
    printf("Enter the no. of elements in the array: ");
    scanf("%d",&n);
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