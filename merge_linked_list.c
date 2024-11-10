/*Input two linked lists Ll and L2 pointed to by head1 and head2 respectively from the user. Merge 

these lists into a third linked list such that in the merged list, all even numbers occur first followed 

by odd numbers. A sample set of input and output is given below:

Testcase 1: 

input list 1: 12 47 878 2 0 3

input list 2: 5 45 20 81 100 1008 87 25

The merged list is

12 878 2 0 20 100 1008 47 3 5 45 81 87 25
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}node;

node* createhead()
{
    node *head;
    head=malloc(sizeof(node));
    head->link=NULL;
    return head;
}

node* createnode()
{
    node *newnode;
    newnode=malloc(sizeof(node));
    return newnode;
}

void insertlast(node *head,int value)
{
    node *newnode=createnode();
    newnode->data=value;
    newnode->link=NULL;
    if(head->link ==NULL)
    {
        head->link=newnode;
    }
    else
    {
        node *current=head->link;
        while(current->link != NULL)
        {
            current=current->link;
        }
        current->link=newnode;
    }
}

void merge(node *head1, node *head2, node *head3)
{
    node *current1=head1->link;
    node *current2=head2->link;
    while(current1!=NULL)
    {
        if(current1->data % 2 == 0)
        {
        insertlast(head3,current1->data);
        }
        current1=current1->link;
    }
    while(current2!=NULL)
    {    
        if(current2->data %2 ==0)
        {
            insertlast(head3,current2->data);
        }
        current2=current2->link;
    }
    current1=head1->link;
    current2=head2->link;
    while(current1!=NULL)
    {    
        if(current1->data %2 !=0)
        {
            insertlast(head3,current1->data);
        }
        current1=current1->link;
    }
   while(current2!=NULL)
    {    
        if(current2->data %2 !=0)
        {
            insertlast(head3,current2->data);
        }
        current2=current2->link;
    }
    
}

void display(node *head)
{
    node *current=head->link;
    while(current!=NULL)
    {
    printf("%d\t",current->data);
    current=current->link;
    }
}

void main()
{
    struct node *head1=createhead();
    struct node *head2=createhead();
    struct node *head3=createhead();
    int n,i,value;
    printf("\n1. LinkedList 1\n");
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    printf("\nEnter the value:");
    scanf("%d",&value);
    insertlast(head1,value);
    }
    printf("\nLinkedList 2\n");
    printf("\nEnter the number of terms: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    printf("\nEnter the value:");
    scanf("%d",&value);
    insertlast(head2,value);
    }
    merge(head1,head2,head3);
    printf("\nMerged list:\n");
    display(head3);
}
