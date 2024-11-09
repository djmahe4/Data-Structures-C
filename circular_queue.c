#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1;
int size;

int isFull()
{
    if(front==0 && rear==size-1)
        return 1;
    else if(front==(rear+1)%size)
        return 1;
    else
        return 0;    
}

int isEmpty()
{
    if(front==rear)
        return 1;
    else
        return 0;
}
void enqueue(int value, int *Q)
{
    if(isFull())
    {
        printf("Queue Overflow");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear=(rear+1)%size;
        Q[rear]=value;
        printf("%d inserted\n",value);
    }
}

int dequeue(int *Q)
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        int temp= Q[front];
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front=(front+1)%size;
        }
        return temp;
    }
}

void display(int *Q)
{
    for(int i=front; i<=rear;i++)
    {
        printf("%d\t",Q[i]);
    }
}

void main()
{
    int ch,value,key;
    printf("Enter the size of queue: ");
    scanf("%d",&size);
    int *Q=malloc(size *sizeof(int));
    while(1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d",&value);
            enqueue(value,&Q);
            break;
            
            case 2:
            key=dequeue(&Q);
            if(key==-1)
            {
                printf("Underflow");
            }
            else
            {
            printf("%d deleted",key);
            }
            break;
            
            case 3:
            display(&Q);
            break;
            
            default:
            printf("Invalid choice");
            exit(0);
        }
    }
}
