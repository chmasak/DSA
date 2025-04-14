#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
} *head = NULL;  // Initialize head as NULL globally

int c = 0;  // Count of nodes

int init();
void display();
void insert();
void del();

int main() {
    int ch = 0;
    while (ch != 4) {
        ch = init();
        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\nABORTING PROGRAM!!!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}

int init() {
    int ch = 0;
    while (ch < 1 || ch > 4) {
        printf("\n\nSINGLY LINKED LIST USING STACK OPTIONS!!\n");
        printf("\t1: INSERT\n");
        printf("\t2: DELETE\n");
        printf("\t3: DISPLAY\n");
        printf("\t4: EXIT\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &ch);
    }
    return ch;
}

void display() {
    struct node *ptr = head;
    if (ptr == NULL) {
        printf("EMPTY LIST\n");
    } else {
        printf("\nLinked List Elements:\n");
        while (ptr) {
            printf("%d", ptr->val);
            if (ptr->next != NULL) {  // Avoid printing '->' after the last node
                printf("\t");
            }
            ptr = ptr->next;
        }
        printf("\n");
    }
    printf("Total Node(s): %d\n", c);
}

void insert() {  
    struct node *newnode, *ptr = head;
    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\nEnter value to be inserted: ");
    scanf("%d", &newnode->val);
    newnode->next = NULL;

    if (head == NULL) {   
        head = newnode;
        printf("\nFirst Node has been inserted.\n");
    } else {
        while (ptr->next != NULL) { 
            ptr = ptr->next;
        }
        ptr->next = newnode;
        printf("\nNode has been inserted at the end!\n");
    }
    c++;  // Increase node count
}

void del() {
    if (head == NULL) { 
        printf("Whoops! Nothing to delete!\n");
        return;
    }

    struct node *ptr = head, *temp;

    if (head->next == NULL) { // If only one node exists
        free(head);
        head = NULL;
        printf("Deleted the last remaining node.\n");
    } else {
        while (ptr->next->next != NULL) { 
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = NULL;
        free(temp);
        printf("Deleted last node successfully.\n");
    }
    c--;  // Decrease node count
}
