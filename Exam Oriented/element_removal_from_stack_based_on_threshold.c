/*Create a stack of integers. Input a value called threshold and remove all stack items that are greater

than threshold. The rest of the elements should be in the stack. You are permitted to perform only

stack operations. You may use a second stack if required. Two sample sets of input and output are

given below:

Testcase 1: 34 -1 9 5 6 -567 55 2 94

threshold 10

Output: stack after deleting elements -1 9 5 6 -567 2

Testcase 2: 44 3 -7 1 5 27

threshold 50

Output: Sorry, no elements greater than threshold! stack after deleting elements 44 3 -7 1 5 27*/
#include <stdio.h>
#include <stdlib.h>

int s1[100];
int s2[100];
int top1 = -1;
int top2 = -1;
int size = 100;

int isempty(int top)
{
    return top == -1;
}

int isfull(int top)
{
    return top == size - 1;
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

void display()
{
    if (isempty(top1))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = 0; i <= top1; i++)
            printf("%d ", s1[i]);
        printf("\n");
    }
}

void removal()
{
    int t;
    printf("Enter the threshold value: ");
    scanf("%d", &t);
    
    int hasRemoved = 0;
    for (int i = 0; i <= top1; i++)
    {
        if (s1[i] > t)
        {
            pop(s1,&top1);
            hasRemoved = 1;
        }
    }
    
    if (!hasRemoved)
    {
        printf("Sorry, no elements greater than threshold!\n");
        display();
    }
    else
    {
        display();
    }
}

int main()
{
    int ch, x;
    while (1)
    {
        printf("\n1. Push\n2. Display\n3. Perform Operation\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &x);
                push(s1, &top1, x);
                printf("%d inserted\n", x);
                break;

            case 2:
                display();
                break;

            case 3:
                removal();
                break;
            
            case 4:
                exit(0);
                break;
                
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
