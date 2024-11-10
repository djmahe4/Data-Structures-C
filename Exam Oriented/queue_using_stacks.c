/*Given two stacks S1 and S2, implement a queue that supports the following operations:

• enqueue(x): Add an element x to the rear of the queue

• dequeue(): Remove an element from the front of the queue

You are allowed to perform only stack operations push() and pop(). Array or linked list

implementations can be used.*/
#include<stdio.h>
#include<stdlib.h>

int s1[100];
int s2[100];
int top1 = -1;
int top2 = -1;
int size = 100;

int isempty(int top)
{
    if (top == -1)
        return 1;
    else
        return 0;    
}

int isfull(int top)
{
    if (top == size - 1)
        return 1;
    else
        return 0;    
}

void push(int a[100], int *top, int value)
{
    if (isfull(*top))
        printf("Overflow\n");
    else
    {
        a[++(*top)] = value;
    }
}

int pop(int a[100], int *top)
{
    if (isempty(*top))
    {
        printf("Underflow\n");
        return -1;
    }
    else
        return a[(*top)--];
}

void enqueue(int x)
{
    push(s1, &top1, x);
}

int dequeue()
{
    if (isempty(top1) && isempty(top2))
    {
        printf("Empty Queue\n");
        return -1;
    }
    if (isempty(top2))
    {
        while (!isempty(top1))
        {
            push(s2, &top2, pop(s1, &top1));
        }
    }
    return pop(s2, &top2);
}

void display()
{
    if (!isempty(top2))
    {
        for (int i = top2; i >= 0; i--)
            printf("%d ", s2[i]);
    }
    if (!isempty(top1))
    {
        for (int i = 0; i <= top1; i++)
            printf("%d ", s1[i]);
    }
    printf("\n");
}

int main()
{
    int ch, x;
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &x);
                enqueue(x);
                printf("%d inserted\n", value);
                break;

            case 2:
                x = dequeue();
                if (x != -1)
                    printf("%d deleted\n", x);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
