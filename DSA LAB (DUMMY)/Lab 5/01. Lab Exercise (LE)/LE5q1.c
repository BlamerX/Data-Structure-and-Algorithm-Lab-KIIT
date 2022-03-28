// Write a menu driven program to perform the following operations in a stack using array by using suitable user defined functions for each case.
// a) Check if the stack is empty
// b) Display the contents of stack
// c) Push
// d) Pop
// Verify & validate each function from main method.

#include <stdio.h>
#include <stdlib.h>

int data[20], top = -1;

void push(int val)
{
    if (top == 20 - 1)
        printf("\nOverflow\n");
    else
    {
        top++;
        data[top] = val;
    }
}

void pop()
{
    if (top == -1)
        printf("\nUnderflow\n");
    else
        top--;
}

void display()
{
    int i;
    if (top == -1)
        printf("stack is empty");
    else
    {
        for (i = top; i >= 0; i--)
            printf("%d ", data[i]);
    }
    printf("\n");
}

void check()
{
    if (top == -1)
        printf("The stack is empty\n");
    else
        printf("The stack is not empty\n");
}

int main()
{
    int opt, n;
    while (1)
    {
        printf("\n1 Check if the stack is empty");
        printf("\n2 Display the contents of stack");
        printf("\n3 Push");
        printf("\n4 Pop");
        printf("\n5 Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            check();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("\nEnter any element to push: ");
            scanf("%d", &n);
            push(n);
            break;
        case 4:
            pop();
            break;
        case 5:
            exit(0);
            break;
        }
    }

    return 0;
}