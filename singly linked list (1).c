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

void insertfirst(node *head,int data)
{
node *newnode=createnode();
newnode->value=data;
newnode->link=head->link;
head->link=newnode;
printf("%d inserted\n",data);
}

void insertlast(node *head,int data)
{
node *current=head->link;
while(current->link!=NULL)
{
current=current->link;
}
node *newnode=createnode();
newnode->value=data;
newnode->link=NULL;
current->link=newnode;
printf("%d inserted\n",data);
}

void insertafter(node *head, int data, int key)
{
node *current=head;
int flag=0;
while(current!=NULL)
{
if(current->value == key)
{
flag=1;
break;
}
current=current->link;
}
if (flag==1)
{
node *newnode=createnode();
newnode->value=data;
newnode->link=current->link;
current->link=newnode;
printf("%d inserted\n",data);
}
else
{
printf("Element not found");
}
}


void insertbefore(node *head, int data, int key)
{
node *current=head;
node *prev=current;
int flag=0;
while(current!=NULL)
{
if(current->value == key)
{
flag=1;
break;
}
prev=current;
current=current->link;
}
if (flag==1)
{
node *newnode=createnode();
newnode->value=data;
newnode->link=prev->link;
prev->link=newnode;
printf("%d inserted\n",data);
}
else
{
printf("Element not found\n");
}
}

void deletefirst(node *head)
{
if(head->link ==NULL)
{
printf("Deletion not possible\n");
}
else
{
printf("%d deleted\n",(head->link)->value);
head->link=(head->link)->link;
}
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

void deleteafter(node *head, int key)
{
node *current=head;
int flag=0;
while(current!=NULL)
{
if(current->value == key)
{
flag=1;
break;
}
current=current->link;
}
if NULL
{
printf("Deletion not possible\n");
}
if (flag==1 )
{
printf("%d deleted\n",(current->link)->value);
current->link=(current->link)->link;
}
else
{
printf("Deletion not possible\n");
}
}

void deletebefore(node *head, int key)
{
if (head->link == NULL)
{
printf("List Empty");
}
else
{
node *current=(head->link)->link;
node *prev=head;
int flag=0;
while(current!=NULL)
{
if(current->value == key)
{
flag=1;
break;
}
prev=prev->link;
current=current->link;
}
if (flag==1)
{
printf("%d deleted\n",(prev->link)->value);
prev->link=current;
}
else
{
printf("Deletion not possible\n");
}
}
}

void search(node *head,int key)
{
int flag=0;
node *current=head;
while(current!=NULL)
{
if(current->value == key)
{
printf("Element found\n");
flag=1;
break;
}
current=current->link;
}
if (flag==0)
{
printf("Element not found\n");
}
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
printf("\n1. InsertFirst\n2. InsertLast\n3. InsertAfter\n4. InsertBefore\n5. DeleteFirst\n6. DeleteLast\n7. DeleteAfter\n8. DeleteBefore\n9. Searching\n10.Display\n");
printf("Enter the choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the value: ");
scanf("%d",&data);
insertfirst(head,data);
break;

case 2:
printf("Enter the value: ");
scanf("%d",&data);
insertlast(head,data);
break;

case 3:
printf("Enter the value: ");
scanf("%d",&data);
printf("Enter the element to be searched: ");
scanf("%d",&key);
insertafter(head,data,key);
break;

case 4:
printf("Enter the value: ");
scanf("%d",&data);
printf("Enter the element to be searched: ");
scanf("%d",&key);
insertbefore(head,data,key);
break;

case 5:
deletefirst(head);
break;

case 6:
deletelast(head);
break;

case 7:
printf("Enter the element to be searched: ");
scanf("%d",&key);
deleteafter(head,key);
break;

case 8:
printf("Enter the element to be searched: ");
scanf("%d",&key);
deletebefore(head,key);
break;

case 9:
printf("Enter the element to be searched: ");
scanf("%d",&key);
search(head,key);
break;

case 10:
display(head);
break;

default:
printf("Invalid choice");
exit(0);
}
}
}

