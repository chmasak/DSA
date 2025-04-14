#include <stdio.h>
#include<limits.h>
int insertionsort(int a[], int n)
{
    int i,j,pos,temp;
    a[0]=INT_MAX;
    for(i=1;i<=n;i++)
    {
        temp=a[i];
        //pos=i;
        j=i-1;
        while (temp>a[j])
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
    int a[n+1];
    printf("\nEnter elements of array: ");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array:\t");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
    //insertion sort
    insertionsort(a,n);
    //printing
    printf("\nSorted array: \t");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
}