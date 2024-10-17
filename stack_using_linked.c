#include<stdlib.h>
#include<stdio.h>

typedef struct node{
int value;
struct node *link;
}node;

node *createhead()
{
node *head;
head=malloc(sizeof(node));
head->link=NULL;
return head;
}

node *createnode()
{
node *newnode;
newnode=malloc(sizeof(node));
return newnode;
}

void insertlast(node *head,int data)
{
node *newnode=createnode();
newnode->value=data;
newnode->link=NULL;
if(head->link == NULL)
{
	head->link=newnode;
}
else
{
node *current=head->link;
while(current->link!=NULL)
{
current=current->link;
}
current->link=newnode;
}
printf("%d inserted\n",data);
}

void push(node *head,int data)
{
	insertlast(head,data);	
}

void deletelast(node *head)
{
if(head->link ==NULL)
{
printf("Deletion not possible\n");
}
else
{
node *current=head->link;
node *prev=current;
while(current->link!=NULL)
{ 
prev=current;
current=current->link;
}
printf("%d deleted\n",current->value);
prev->link=NULL;
}
}

void pop(node *head)
{
	deletelast(head);
}

void display(node *head)
{
node *current=head->link;
while(current!=NULL)
{
printf("%d->",current->value);
current=current->link;
}
}

int main()
{
node *head=createhead();
int data,ch,key;
while (1)
{
printf("\n1. Push\n2. Pop\n3. Display\n");
printf("Enter the choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the value: ");
scanf("%d",&data);
push(head,data);
break;

case 2:
pop(head);
break;

case 3:
display(head);
break;

default:
printf("Invalid choice");
exit(0);
}
}
}
