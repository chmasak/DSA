#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node* next;
}*head;

int c = 0;
int init();
void display();
void insert();
void del();

int main()
{
    int ch = 0;
    head = NULL;

    while (ch != 4)
    {
        ch = init();
        switch (ch)
        {
            case 1: insert();
                break;
            case 2: del();
                break;
            case 3: display();
                break;
            case 4: printf("\n\nABORTING PROGRAM!!!\n");
                break;
            default: printf("Invalid choice. Try again!\n");
        }
    }
    return 0;
}

int init()
{
    int ch = 0;
    while (ch < 1 || ch > 4)
    {
        printf("\n\nCIRCULAR LINKED LIST OPTIONS!!\n");
        printf("1: INSERT\n");
        printf("2: DELETE\n");
        printf("3: DISPLAY\n");
        printf("4: EXIT\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &ch);
    }
    return ch;
}

void display()
{
    struct node *ptr = head;
    if (!ptr)
    {
        printf("EMPTY LIST\n");
    }
    else
    {
        printf("\nList elements:\n");
        do
        {
            printf("%d\n", ptr->val);
            ptr = ptr->next;
        } while (ptr != head);
    }
    printf("Total Node(s): %d\n", c);
}

void insert()
{
    struct node *temp = head, *newnode;
    int chopt;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\n\nEnter value to be inserted: ");
    scanf("%d", &newnode->val);

    if (!head)
    {
        head = newnode;
        newnode->next = head;
        printf("\nFirst Node has been inserted.\n");
        c++;
    }
    else
    {
        printf("\n1. At beginning\n2. At any random position\n3. At the end\nEnter your choice: ");
        scanf("%d", &chopt);

        switch (chopt)
        {
            case 1:
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                newnode->next = head;
                head = newnode;
                temp->next = head;
                printf("Inserted at the beginning.\n");
                c++;
                break;

            case 2:
            {
                int i, pos;
                printf("\nEnter position: ");
                scanf("%d", &pos);

                if (pos > c + 1 || pos < 1)
                {
                    printf("Invalid position!\n");
                    free(newnode);
                }
                else
                {
                    struct node *ptr = head;
                    for (i = 1; i < pos - 1; i++)
                    {
                        ptr = ptr->next;
                    }
                    newnode->next = ptr->next;
                    ptr->next = newnode;
                    printf("Inserted at position %d successfully.\n", pos);
                    c++;
                }
                break;
            }

            case 3:
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                newnode->next = head;
                temp->next = newnode;
                printf("Inserted at the end.\n");
                c++;
                break;

            default:
                printf("Wrong input!\n");
                free(newnode);
        }
    }
}

void del()
{
    struct node *ptr, *temp;
    int chopt, pos, i;

    if (!head)
    {
        printf("Whoops!! Nothing to delete!!\n");
        return;
    }

    if (c == 1)
    {
        free(head);
        head = NULL;
        c--;
        printf("Single node has been deleted.\n");
        return;
    }

    printf("\n1. The beginning\n2. Any random position\n3. The end\nEnter your choice: ");
    scanf("%d", &chopt);

    switch (chopt)
    {
        case 1:
            temp = head;
            ptr = head;
            while (ptr->next != head)
            {
                ptr = ptr->next;
            }
            head = temp->next;
            ptr->next = head;
            free(temp);
            printf("Deleted from the beginning.\n");
            c--;
            break;

        case 2:
            printf("\nEnter position: ");
            scanf("%d", &pos);

            if (pos > c || pos < 1)
            {
                printf("Invalid position!\n");
            }
            else
            {
                ptr = head;
                for (i = 1; i < pos - 1; i++)
                {
                    ptr = ptr->next;
                }
                temp = ptr->next;
                ptr->next = temp->next;
                free(temp);
                printf("Deleted from position %d.\n", pos);
                c--;
            }
            break;

        case 3:
            ptr = head;
            while (ptr->next->next != head)
            {
                ptr = ptr->next;
            }
            temp = ptr->next;
            ptr->next = head;
            free(temp);
            printf("Deleted from the end.\n");
            c--;
            break;

        default:
            printf("Wrong input!\n");
    }
}
