#include <stdio.h>
#include <stdlib.h>
//#include <alloc.h>
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
//void del(struct node*,struct node*,struct node*);

int main()
{
    int c=1, chmain, chopt,ch=0;
    int  pos, data, ans=1;
    struct node *head,*temp,*newnode;
    head=NULL;

    while(ch!=4)
    {ch=init();
    //printf("%d",ch);
     switch(ch)
	{
	    case 1:
	    insert();
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
    {while (ptr)
    {
	printf("\n%d\n",ptr->val);
	ptr=ptr->next;

    } }
    else
	printf("EMPTY LIST\n");
    printf("Total Node(s): %d",c);
    }
void insert()
{  struct node *newnode,*ptr=head;
   int chopt;
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("\n\nEnter  value to be inserted: ");
   scanf("%d",&newnode->val);
   newnode->next=NULL;
   if (head==NULL)
   {    head=newnode;
        printf("\nFirst Node has been inserted: ");
        c++;
   }
   else
   {
        printf("\n1.At beginning\n2.At any random position\n3.At the end\nEnter another choice: ");
	    scanf("%d",&chopt);
	    switch(chopt)
	     {
		  case 1: //insertion at beginning code
		     {
		      
		      newnode->next=head;
		      head=newnode;
		      c++;
		      break;
		      }
		  
		   case 2: //insertion at any random position code
		     {
		      int i, pos;
		      ptr=head;
		      printf("\n\nEnter  position: ");
              scanf("%d",&pos);
              if (pos>c)
                printf("\nInvalid position!!");
              else 
                {for (int i=1;i<=pos-2;i++)// go to node prev to pos
                  ptr=ptr->next;
                    newnode->next=ptr->next;
                    ptr->next=newnode;
                    c++;
                    printf("Inserted at position %d successfully!!",pos);
                  }
                  
                   break;
		  }  
		 case 3: //insertion at end code
		   {
		        while(ptr->next!=NULL) 
		        {
		            ptr=ptr->next;
		        }
		        ptr->next=newnode;
		        
		        printf("\n Node has been inserted at last!!");
		        c++;
		        break;
		   }
		 default: printf("Wrong input!!");
	   } 
   }
   
}
void del()//struct node,struct node*,struct node*)
{
    struct node *newnode,*ptr,*preptr,*temp;
    int chopt,item;
    if (head==NULL)
    {
        printf("Whoops!! nothing to delete!!");
    }
    
    else if(c==1)
    {temp=head;
    head=NULL;
    free(temp);
    c--;
    printf("Single node has been deleted");
    }
    else
    {
        ptr=head;
        printf("\n1.The beginning\n2.Any random position\n3.The end\nEnter the position from where you wanna delete: ");
        scanf("%d",&chopt);
        switch(chopt)
        {
            case 1://beginning
                {
                    temp=head;
                    head=ptr->next;
                    free(temp);
                    printf("Deleted from begining");
                    c--;
                    break;
                }
            case 2://random
                {
                    int i, pos;
		            ptr=head;
		            printf("\n\nEnter  position: ");
                    scanf("%d",&pos);
                    if (pos<=c)
                    {for(i=1;i<=pos-2;i++)
                    {
                        ptr=ptr->next;
                     }
                    temp=ptr->next;
                    ptr->next=temp->next;
                    free(temp);
                     c--;
                    printf("Deleted from the given position");
                    }
                   else 
                    {
                        printf("\nInvalid position!!");
                    }
                    break;
                }
            case 3://end
                {
                    ptr=head;
                    for(int i=1;i<=c-2;i++)
                    {
                        ptr=ptr->next;
                    }
                    temp=ptr;
                    temp=ptr->next;
                    ptr->next=NULL;
                    free(temp);
                    printf("Deleted from last\n",item);
                    c--;
                    break;
                }
            default: 
                {
                    printf("Wrong input!!");
                }
        }
    }
}