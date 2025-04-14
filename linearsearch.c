#include <stdio.h>
int main()
{
    int x,i,n, flag=0;
    printf("Enter the no. of elements in the array: ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter elements of array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter element to be searched: ");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        if (a[i]==x)
        {
            printf("\nElement %d found at position %d. ",x,i+1);
            flag=1;
            break;
        }
    }
    if (flag==0)
        {
            printf("\nElement %d not found.");
        }  
}