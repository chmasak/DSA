#include <stdio.h>
#define size 5
int top=-1, s[size];
void push();
void pop();
void peep();
void change();
void display();
void stop();
int main()
{
int ch;
do
{
    printf("\nStack operations!!\n");
    printf("1.Push \n 2.Pop \n 3.Peep \n 4.Change \n 5.display \n 6.Stop \nEnter a choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            peep();
            break;
        }
        case 4:
        {
            change();
            break;
        }
        case 5:
        {
            display();
            break;
        }
        case 6:
        {
            stop();
            break;
        }
        default:
        {
            printf("Invalid choice!!!");
        }
    }
}

while (ch<6);
}
void push()
{
    int x;
    if (top==size-1)
    {
        printf("Overflow!!\n\n");
    }
    else
    { 
        printf("Enter element to be pushed: ");
        scanf("%d",&x);
        top+=1;
        s[top]=x;
        printf("Pushed element is %d\n\n",s[top]);
    }
}
void pop()
{
    if (top==-1)
    {
        printf("Underflow!!!\n\n");
    }
    else
    {
        printf("Popped element is %d\n\n",s[top]);
        top-=1;
    }
}
void peep()
{
    int in;
    printf("Enter the position");
    scanf("%d",&in);
    printf("Element at %d is %d",in, s[(in-1)]);
}
void change()
{
    int elem,pos;
    printf("Enter the position: ");
    scanf("%d",&pos);
    printf("Enter the element to change: ");
    scanf("%d",&elem);
    s[pos]=elem;
    printf("Element changed!! ");
}
void display()
{
    int i;
    if (top==-1)
    {
        printf("Underflow!!!");
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("%d  \n",s[i]);
        }
        
    }
}

void stop()
{
    printf("Aborting the program!!");
    
}

