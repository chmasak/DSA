#include <stdio.h>
int* mergesort( int a[], int b[], int l1, int l2)
{
    int i=0,j=l2-1,k=0;
    int l=l1+l2;
    int c[l];
    while(i<l1 && j>=0)
    {
        if (a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=b[j--];
        }
        if (i>=l1)
        {
            while (j>=0)
            {
                c[k++]=b[j--];
            }
        }
        if (j<=0)
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
    int i;
    int a[]={3,4,7,9,13};
    int b[]={18,14,11,10,8,5,2,1};
    int l1=sizeof(a)/sizeof(a[0]);
    int l2=sizeof(b)/sizeof(b[0]);
    int l=l1+l2;
    int c[l];
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