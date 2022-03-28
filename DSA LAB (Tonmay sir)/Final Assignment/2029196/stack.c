// WAP Write a menu driven program to perform the following operations of a stack using array by using suitable user defined functions for each case.
// a) Check if the stack is empty
// b) Display the contents of stack
// c) Push
// d) Pop

int data[20], top = -1;

void push311(int val)
{
    if (top == 20 - 1)
        printf("\nOverflow\n");
    else
    {
        top++;
        data[top] = val;
    }
}

void pop311()
{
    if (top == -1)
        printf("\nUnderflow\n");
    else
        top--;
}

void display311()
{
    if (top == -1)
        printf("stack is empty");
    else
    {
        for (int i = top; i >= 0; i--)
            printf("%d ", data[i]);
    }
    printf("\n");
}

void check311()
{
    if (top == -1)
        printf("The stack is empty\n");
    else
        printf("The stack is not empty\n");
}

int STACK1()
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
            check311();
            break;
        case 2:
            display311();
            break;
        case 3:
            printf("\nEnter Element to push: ");
            scanf("%d", &n);
            push311(n);
            break;
        case 4:
            pop311();
            break;
        case 5:
            exit(0);
            break;
        }
    }

    return 0;
}