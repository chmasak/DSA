#include <stdio.h>
int insertionsort(int a[], int n)
{
    int i,j,pos,temp;
    for(i=0;i<n;i++)
    {
        temp=a[i];
        //pos=i;
        j=i-1;
        while (temp<a[j] && j>=0)
        {
            a[j+1]=a[j];
            j--;
           
        }
        pos=j+1;
        a[pos]=temp;
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
    //insertion sort
    insertionsort(a,n);
    //printing
    printf("\nSorted array: \t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}