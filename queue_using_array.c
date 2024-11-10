#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int SIZE;
int front,rear=-1;
int *a;

void createqueue(int s)
{
	SIZE=s;
	a=malloc(sizeof(SIZE));
}

bool isEmpty()
{
	if (front==-1)
		return true;
	else
		return false;
}
bool isFull()
{
	if(rear==SIZE)
		return true;
	else
		return false;
		
}
void enqueue(int item)
{
	if(isFull())
		printf("queue overflow");
	else
	{
		a[++rear]=item;
		printf("%d is inserted\n",item);
	}
}

int dequeue()
{
	if(isEmpty())
		return 0;
	else
		return a[front++];
}

void display()
{
	int i;
	for(i=front;i<=rear;i++)
	{
		printf("%d \t",a[i]);
	}
}
	
void main()
{
int s;
printf("Enter size of queue: ");
scanf("%d",&s);
createqueue(s);

while(1)
{
	printf("\nMENU\n1.Enqueue\n2.Dequeue\n3.Is Empty?\n4.Is Full?\n5.Display\n");
	printf("enter your choice: ");
	int ch,item;
	bool k;
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		//enqueue
		printf("enter value to be inserted: ");
		scanf("%d",&item);
		enqueue(item);
		break;
	case 2:
		//dequeue
		item=dequeue();
		if(item==0)
			printf("queue underflow\n");
		else
			printf("%d deleted\n", item);
		break;
	case 3:
		//isEmpty
		k=isEmpty();
		if(k==true)
			printf("queue is empty");
		else
			printf("queue not empty");
		break;
	case 4:
		//isFull
		k=isFull();
		if(k==true)
			printf("queue overflow");
		else
			printf("queue not full");
		break;
	case 5:
		//Display
		display();
		break;
	default:
		printf("Invalid choice\n");
		exit(0);
	}
}
}
