#include <stdio.h>
int sort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if (a[i]>a[i+1])
            {
            int temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            }
        }
    }
}
int main() {
    int i, x, n, flag = 0;
    int low, mid, high;
    
    //entering elements of array
    printf("Enter the no. of elements in the array: ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter elements of array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    //binary search
    printf("\nEnter element to be searched: ");
    scanf("%d", &x);
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (x == a[mid]) {
            printf("\nElement %d found at index %d.\n", x, mid+1);
            flag = 1;
            break;
        } else if (x > a[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (flag == 0) {
        printf("\nElement %d not found.\n", x);
    }
    return 0;
}
