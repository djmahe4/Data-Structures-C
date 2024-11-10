/*Implement a reversal function DLL_Reverse (head) that reverses a doubly linked list L (pointed to

by head). Print the reversed list.*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;

node* createhead()
{
    node *head;
    head=malloc(sizeof(node));
    head->prev= NULL;
    head->next= NULL;
    return head;
}

node* createnode()
{
    node *newnode;
    newnode=malloc(sizeof(node));
    return newnode;
}
void insertlast(node *head, int value)
{
    node *newnode=createnode();
    newnode->data=value;
    newnode->next=NULL;
    if(head->next==NULL)
    {
        newnode->prev=head;
        head->next=newnode;
    }
    else
    {
    node *current=head->next;
    while(current->next != NULL)
    {
        current=current->next;
    }
    newnode->prev=current;
    current->next=newnode;
    }
}

void DLL_Reverse(node *head)
{
    
    node *current=head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    while(current->prev!=NULL)
    {
        printf("%d\t",current->data);
        current=current->prev;
    }
}

void main()
{
    struct node *head=createnode();
    int ch, value;
    while(1)
    {
    printf("\n1. Insert\n2. Reverse\n");
    printf("Enter the choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("Enter the value: ");
        scanf("%d",&value);
        insertlast(head,value);
        break;
        
        case 2:
        DLL_Reverse(head);
        exit(0);
        break;
        
        default:
        printf("Invalid");
        break;
    }
    }
}
