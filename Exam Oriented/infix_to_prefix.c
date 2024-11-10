//INFIX TO PREFIX
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top=-1;
int top1=-1;
int size;
int *a;
char output[100];

void createstack(int s)
{
    size=s;
    a=malloc(size * sizeof(char));
}

bool isempty()
{
if(top==-1)
    return true;
else
    return false;
}

bool isfull()
{
if(top==size-1)
    return true;
else
    return false;
}

void push(char item)
{
    if(isfull())
        printf("stack overflow");
    else
        a[++top]=item;
}

char pop()
{
if(isempty())
    return '0';
else
    return a[top--];
}

char peek()
{
    if(isempty())
        return '0';
    else
        return a[top];

}

int precedence (char p)
{
if(p=='+'||p=='-')
return 1;
else if(p=='*'||p=='/')
return 2;
else if(p=='^')
return 3;
else if(p=='(')
return 0;
}

void reverseString(char *str) {
    int i, j, len = strlen(str);
    char temp;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infix_prefix(char *a)
{
    int len=strlen(a);
    reverseString(a);
    for(int i=0;i<len;i++)
    {
        if(a[i] == ')' )
        {
            a[i]='(';
        }
        else if(a[i] == '(')
        {
            a[i]=')';
        }
    }
    int i=0,j=0;
    createstack(len);
    while(a[i]!='\0')
    {
        char t=a[i];
        if(t=='(')
            push(a[i]);
        else if((t=='+')||(t=='-')||(t=='*')||(t=='/')||(t=='^'))
        {
            if(!isempty())
            {
            while(precedence(t)<=precedence(peek()))
                {
                output[j]=pop();
                j++;
                if(isempty())
                  break;
                }
            }
            push(t);
        }
        else if(t==')')
        {
        while(!isempty())
            {
            char temp=pop();
            if(temp!='(')
                {
                output[j]=temp;
                j++;
                }
            else
            break;
            }
        }
        else
        {
            output[j]=t;
            j++;

        }
    i++;
    }
    while(!isempty())
    {
        output[j]=pop();
        j++;
    }
    output[j]='\0';
    reverseString(output);
    printf("%s",output);
}


void main()
{
char infix[100];
int i=0;
printf("Enter the Infix Expression: ");
scanf("%s",infix);
printf("\nPrefix Expression: ");
infix_prefix(infix);
}
