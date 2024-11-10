/*Implement a split function SLL_Split (head, key) that splits a linked list L (pointed to by head) into 

two lists Ll and L2 such that,

• elements in Ll are less than a specified key

• elements in L2 are greater than or equal to the specified key

For example if L = {−5, 4, 3, 2, 9, 1, −47, 19} and key = 4, your aim is to create two lists as 

follows:

Ll = {−5, 3, 2, 1, −47}

L2 = {4, 9, 19}*/
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

void split(node *head1, node *head2, node *head3)
{
    node *current1=head1->link;
    printf("Enter the threshold value: ");
    int t;
    scanf("%d",&t);
    while(current1!=NULL)
    {
        if(current1->data < t)
        {
        insertlast(head2,current1->data);
        }
        else
        {
        insertlast(head3,current1->data);
        }
        current1=current1->link;
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
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    printf("\nEnter the value:");
    scanf("%d",&value);
    insertlast(head1,value);
    }
    split(head1,head2,head3);
    printf("\nSplit lists:\n");
    printf("\nL1= ");
    display(head2);
    printf("\nL2= ");
    display(head3);
}
