#include <stdio.h>
int swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int selectionsort(int a[], int n)
{
    int i,j,max,pos,temp;
    for(i=0;i<n;i++)
    {
        max=a[i];
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]>max)
            {
                max=a[j];
                pos=j;
            }
        }
        swap(&a[i],&a[pos]);
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
    //selection sort
    selectionsort(a,n);
    //printing
    printf("\nSorted array: \t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}