/*Create a data structure to represent a memory block, which should include:

• Size of the block

• Status (allocated or free)

• Pointer to the next block

Implement functions to simulate memory allocation using best-fit strategy on the following process 

requests:

Testcase 1: Memory blocks: 200 KB, 400 KB, 600 KB, 500 KB, 300 KB, 250 KB

Process requests: 357 KB, 210 KB, 468 KB, 491 KB

After performing allocation, print the memory blocks along with their allocation status*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int size;
    int status; // 0: free, 1: allocated
    struct node *link;
} node;

node* createhead() {
    node *head = (node*)malloc(sizeof(node));
    head->link = NULL;
    return head;
}

node* createnode() {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->status = 0; // initially free
    newnode->link = NULL;
    return newnode;
}

void insertlast(node *head, int value) {
    node *newnode = createnode();
    newnode->size = value;
    newnode->link = NULL;
    if (head->link == NULL) {
        head->link = newnode;
    } else {
        node *current = head->link;
        while (current->link != NULL) {
            current = current->link;
        }
        current->link = newnode;
    }
}

void allocate(node *head, int s) {
    node *current = head->link;
    node *best = NULL;

    // Find the best fit block
    while (current != NULL) {
        if (!current->status && current->size >= s) { // free and large enough
            if (best == NULL || current->size < best->size) {
                best = current;
            }
        }
        current = current->link;
    }

    if (best == NULL) {
        printf("No appropriate memory block available for %d KB\n", s);
    } else {
        best->status = 1; // allocate the best-fit block
        printf("%d KB allocated\n", s);
    }
}

void display(node *head) {
    node *current = head->link;
    while (current != NULL) {
        printf("%d KB -> %s\n", current->size, current->status ? "Allocated" : "Free");
        current = current->link;
    }
}

int main() {
    node *head = createhead();
    int ch, size, value;

    while (1) {
        printf("\n1. Insert Memory Block\n2. Allocate Memory\n3. Display Memory Blocks\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("Enter the size: ");
                scanf("%d", &value);
                insertlast(head, value);
                printf("%d KB block inserted\n", value);
                break;
            
            case 2:
                printf("Enter the size: ");
                scanf("%d", &size);
                allocate(head, size);
                break;
            
            case 3:
                display(head);
                break;
            
            case 4:
                exit(0);
            
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
