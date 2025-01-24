#include<stdio.h>
#define size 5
void enqueue();
void dequeue();
void display();
int rear=-1, front=-1;
int cq[size];
void enqueue()
{
    int elem;
    printf("Enter the element: ");
    scanf("%d",&elem);
    if (front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        cq[rear]=elem;
    }
    else if((rear+1)%size == front)
    {
        printf("Overflow!!");
    }
    else
    {
        rear=(rear+1)%size;
        cq[rear]=elem;
    }
}
void dequeue()
{
    if (front==-1 && rear==-1)
    {
        printf("Underflow!!");
    }
    else if(front==rear)
    {
        printf("Deleted item: %d",cq[front]);
        front=front-1;
        rear=rear-1;
    }
    else
    {
        printf("Deleted item: %d",cq[front]);
        front=(front+1)%size;
    }
}
void display()
{
    int i=front;
    if (front==-1 && rear==-1)
    {
        printf("Underflow!!");
    }
    else
    {
        printf("Elements are: \n");
        while(i<=rear)
        {
            printf("%d  ",cq[i]);
            i=(i+1)%size;
        }
    }
}
int main()
{
    int ch,ans=1;
    do
    {
        printf(" 1.enqueue\n 2.dequeue\n 3.display\n Enter a choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: {enqueue();
                    break;}
            case 2: {dequeue();
                    break;}
            case 3: {display();
                    break;}
            default: {printf("Wrong input!!");}
        }
        printf("\nWanna continue? (1/0): ");
        scanf("%d",&ans);
    } while (ans==1); 
    printf("\nAborting program!!");
}