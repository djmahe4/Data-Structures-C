#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
 int value;
 struct node *left;
 struct node *right;
}node;

node* createhead()
{
 node *head;
 head=malloc(sizeof(node));
 head->left=head->right=NULL;
 return head;
}

node* createnode()
{
        node *newnode;
 	newnode=malloc(sizeof(node));
 	return newnode;
}



void insertfirst(node *head,int data)
{
 node *newnode=createnode();
 newnode->value=data;
 if(head->right==NULL)
  {
  head->right=newnode;
  newnode->right=NULL;
  }
 else
  {
  newnode->right=head->right;
  head->right=newnode;

  }

}

void insertlast(node *head,int data)
{
node *current=head->right;
while(current->right!=NULL)
{
current=current->right;
}
node *newnode=createnode();
newnode->value=data;
newnode->right=NULL;
newnode->left=current;
current->right=newnode;
printf("%d inserted\n",data);
}

void deletelast(node *head)
{
	if(head->right ==NULL)
	{
	printf("Deletion not possible\n");
	}
	else
	{
	node *current=head->right;
	node *prev=current;
	while(current->right!=NULL)
	{ 
	prev=current;
	current=current->right;
	}
	printf("%d deleted\n",current->value);
	prev->right=NULL;
}
}
void deletefirst(node *head)
{
if(head->right ==NULL)
{
printf("Deletion not possible\n");
}
else
{
printf("%d deleted\n",(head->right)->value);
head->right=(head->right)->right;
}
}

void display(node *head)
{
node *current=head->right;
while(current!=NULL)
{
printf("%d",current->value);
current=current->right;
if(current!=NULL)
{
printf("->");
}
}
}

int main()
{
node *head=createhead();
int data,ch,key;
while (1)
{
printf("\n1. InsertFirst\n2. InsertLast\n3. DeleteFirst\n4. DeleteLast\n5. Display\n6. Exit\n");
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
deletefirst(head);
break;

case 4:
deletelast(head);
break;

case 5:
display(head);
break;

case 6:
exit(0);
break;

default:
printf("Invalid choice");
exit(0);
}
}
}
