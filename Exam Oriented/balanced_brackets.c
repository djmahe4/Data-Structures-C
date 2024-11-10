/*A string of parentheses is said to be balanced if each opening parenthesis has a corresponding

closing parenthesis and the pairs of parentheses are properly nested. (()()()()) and (((()))) are
examples of balanced strings of parentheses whereas ())) and (()()(() are not balanced. Implement a

parenthesis checker using stack to check whether a given input string of parentheses is balanced or

not.*/
#include <stdio.h>
#include <stdlib.h>

char s1[100];
char s2[100];
int top1 = -1;
int top2 = -1;
int size = 100;

int isempty(int top) {
    return (top == -1);
}

int isfull(int top) {
    return (top == size - 1);
}

void push(char a[100], int *top, char value) {
    if (isfull(*top)) {
        printf("Overflow\n");
    } else {
        a[++(*top)] = value;
    }
}

char pop(char a[100], int *top) {
    if (isempty(*top)) {
        printf("Underflow\n");
        return -1;
    } else {
        return a[(*top)--];
    }
}

int check(char a[100], int *top) {
    for (int i = 0; i <= *top; i++) {
        if (a[i] == '(') {
            push(s2, &top2, a[i]);
        } else if (a[i] == ')') {
            if (isempty(top2)) {
                return -1;
            } else {
                pop(s2, &top2);
            }
        }
    }
    if (!isempty(top2)) {
        return -1;
    } else {
        return 1;
    }
}

void display() {
    if (!isempty(top1)) {
        for (int i = 0; i <= top1; i++)
            printf("%c ", s1[i]);
        printf("\n");
    } else {
        printf("Stack is empty\n");
    }
}

int main() {
    int ch,c;
    char x;
    while (1) {
        printf("\n1. Insert\n2. Check\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter bracket: ");
                scanf(" %c", &x);  // Use &x and add a space before %c to read single character input
                push(s1, &top1, x);
                printf("%c inserted\n", x);
                break;

            case 2:
                c =check(s1, &top1);
                if(c==1)
                    printf("Balanced\n");
                else
                    printf("Unbalanced\n");     
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
