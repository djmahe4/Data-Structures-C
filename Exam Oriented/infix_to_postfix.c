#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack definition
char stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(char item) {
    stack[++top] = item;
}

// Function to pop an element from the stack
char pop() {
    return stack[top--];
}

// Function to check precedence of operators
int precedence(char symbol) {
    if (symbol == '+' || symbol == '-') return 1;
    if (symbol == '*' || symbol == '/') return 2;
    if (symbol == '^') return 3;
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char item;
    while ((item = infix[i++]) != '\0') {
        if (isalnum(item)) {
            postfix[j++] = item; // If the character is an operand, add it to postfix
        } else if (item == '(') {
            push(item); // Push '(' to stack
        } else if (item == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop(); // Pop until '(' is found
            }
            pop(); // Remove '(' from stack
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(item)) {
                postfix[j++] = pop(); // Pop operators with higher or equal precedence
            }
            push(item); // Push the current operator to stack
        }
    }
    while (top != -1) {
        postfix[j++] = pop(); // Pop remaining operators from stack
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    gets(infix); // Read the infix expression
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix); // Print the postfix expression
    return 0;
}
