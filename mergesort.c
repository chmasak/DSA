#include <stdio.h>
int* mergesort( int a[], int b[], int l1, int l2)
{
    int i=0,j=0,k=0;
    int l=l1+l2;
    int c[l];
    while(i<l1 && j<l2)
    {
        if (a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=b[j++];
        }
        if (i>=l1)
        {
            while (j<l2)
            {
                c[k++]=b[j++];
            }
        }
        if (j>=l2)
        {
            while (i<l1)
            {
                c[k++]=a[i++];
            }
        }
    }
     printf("\nSORTED ARRAY:  ");
    for(i=0;i<l;i++)
    {
        printf("%d\t", c[i]);
    }
}
int main()
{
    int i,l1,l2;
    printf("Enter the no. of elements of array 1: ");
    scanf("%d",&l1);
    int a[l1];
    printf("\nEnter elements of array: ");
    for(i=0;i<l1;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the no. of elements of array 2: ");
    scanf("%d",&l2);
    int b[l2];
    printf("\nEnter elements of array: ");
    for(i=0;i<l2;i++)
    {
        scanf("%d",&b[i]);
    }
    printf("\nARRAY 1:  ");
    for(i=0;i<l1;i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\nARRAY 2:  ");
    for(i=0;i<l2;i++)
    {
        printf("%d\t", b[i]);
    }
    mergesort(a,b,l1,l2);
    
}