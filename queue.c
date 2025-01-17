#include <stdio.h>
#define size 5
void enqueue();
void dequeue();
void display();
int front=-1;
int rear=-1;
int q[size];
void enqueue()
{
    int elem;
    if (rear==size-1)
    {
        printf("Overflow!!\n");
    }
    else
    {
        if (front==-1)
        {
            front=0;
        }
        printf("Enter element to enter: ");
        scanf("%d",&elem);
        rear=rear+1;
        q[rear]=elem;
    }
}
void dequeue()
{
    if (front==-1 || front>rear)
    {
        printf("Underflow!!\n");
    }
    else
    {
        printf("%d is deleted from queue", q[front]);
        front=front+1;
    }
}
void display()
{
    int i;
    if (front==-1)
    {
        printf("Underflow!!\n");
    }
    else
    {
        printf("Queue: ");
        for(i=front; i<=rear; i++)
        {
           // printf("jhjhv");
            printf("%d  ",q[i]);
        }
    }
}
int main()
{
    int ch;
    int ans;
    do
    {
        printf("1.Enqueue \n 2.Dequeue \n 3.Display\nEnter a choice: ");
        scanf("%d",&ch);
        printf("\n");
        switch(ch)
        {
            case 1: { enqueue();
                    break; }
            case 2: { dequeue();
                    break; }
            case 3: { display();
                    break; }
            default: printf("Wrong input!!");
        }
        printf("\nWanna continue? (1 for yes/0 for no): ");
        scanf("%d",&ans);
        printf("\n");
        
    }
    while(ans==1);
}

