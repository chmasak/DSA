#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node* next;
}*head;
int c=0;
int init();
void display();
void insert();
void del();
int main()
{
    int c=1, chmain, chopt,ch=0;
    int pos, data, ans=1;
    struct node *head,*temp,*newnode;
    head=NULL;
    while(ch!=4)
    {
        ch=init();
        switch(ch)
	    {
	        case 1: insert();
	            break;
	        case 2: del();
		        break;
	        case 3: display();
		        break;
	        case 4: printf("\n\nABORTING PROGRAM!!!");
		        break;
	    }
	}
}
int init()
{
    int ch=0;
    while (ch<1 || ch>4)
    { 
      printf("\n\n");
      printf("SINGULAR LINKED LIST OPTIONS!!\nBut first, enter the elements: \n\n");
      printf("\n\t\t\t1:INSERT");
      printf("\n\t\t\t2:DELETE");
      printf("\n\t\t\t3:DISPLAY");
      printf("\n\t\t\t4:EXIT");
      printf("\nEnter your choice (1-4):");
      scanf("%d",&ch);
    }
    return(ch);
}
void  display()
{
    struct node *ptr;
    ptr=head;
    if (ptr)
    {
        while (ptr)
        {
	        printf("\n%d\n",ptr->val);
        	ptr=ptr->next;
        } 
    }
    else
	printf("EMPTY LIST\n");
    printf("Total Node(s): %d",c);
}
void insert()
{  
   struct node *newnode,*ptr=head;
   int chopt;
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("\n\nEnter  value to be inserted: ");
   scanf("%d",&newnode->val);
   newnode->next=NULL;
   if (head==NULL)
   {   
        head=newnode;
        printf("\nFirst Node has been inserted: ");
        c++;
   }
   else
   {
		        while(ptr->next!=NULL) 
		        {
		            ptr=ptr->next;
		        }
		        ptr->next=newnode;
                newnode->next=NULL;		        
		        printf("\n Node has been inserted at last!!");
		        c++;
    }   
}
void del()
{
    struct node *newnode,*ptr,*preptr,*temp;
    int chopt,item;
    if (head==NULL) 
    {
        printf("Whoops!! nothing to delete!!");
    }    
    else if(c==1)
    {
        temp=head;
        head=NULL;
        free(temp);
        c--;
        printf("Single node has been deleted");
    }
    else
    {
        ptr=head;
        temp=head;
                    head=ptr->next;
                    free(temp);
                    printf("Deleted from begining");
                    c--;
}
}