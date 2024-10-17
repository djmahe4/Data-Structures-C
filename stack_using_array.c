#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int SIZE;
int top=-1;
int *a;

void createstack(int s)
{
	SIZE=s;
	a=malloc(sizeof(SIZE));
}

bool isEmpty()
{
	if (top==-1)
		return true;
	else
		return false;
}
bool isFull()
{
	if(top==SIZE)
		return true;
	else
		return false;
		
}
void push(int item)
{
	if(isFull())
		printf("Stack Overflow");
	else
	{
		a[++top]=item;
		printf("%d is inserted\n",item);
	}
}

int pop()
{
	if(isEmpty())
		return 0;
	else
		return a[top--];
}

int peek()
{
	if (isEmpty())
		return 0;
	else
		return a[top];
}

void display()
{
	int i;
	for(i=0;i<=top;i++)
	{
		printf("%d \t",a[i]);
	}
}
	
void main()
{
int s;
printf("Enter size of stack: ");
scanf("%d",&s);
createstack(s);

while(1)
{
	printf("\nMENU\n1.Push\n2.Pop\n3.Peek\n4.Is Empty?\n5.Is Full?\n6.Display\n");
	printf("enter your choice: ");
	int ch,item;
	bool k;
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		//push
		printf("enter value to be inserted: ");
		scanf("%d",&item);
		push(item);
		break;
	case 2:
		//pop
		item=pop();
		if(item==0)
			printf("Stack Overflow\n");
		else
			printf("%d deleted\n", item);
		break;
	case 3:
		//peek
		item=peek();
		if(item==0)
			printf("Stack Overflow\n");
		else
			printf("%d is peek value",item);
		break;
	case 4:
		//isEmpty
		k=isEmpty();
		if(k==true)
			printf("Stack is empty");
		else
			printf("Stack not empty");
		break;
	case 5:
		//isFull
		k=isFull();
		if(k==true)
			printf("Stack Overflow");
		else
			printf("Stack not full");
		break;
	case 6:
		//Display
		display();
		break;
	default:
		printf("Invalid choice\n");
		exit(0);
	}
}
}
