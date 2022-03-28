// WAP Write a menu driven program to perform the following operations of a stack using linked list by using suitable user defined functions for each case.
// a) Check if the stack is empty
// b) Display the contents of stack
// c) Push
// d) Pop

struct node312
{
    int data;
    struct node312 *next;
};

typedef struct
{
    struct node312 *top;
} STACK;

void init(STACK *s)
{
    s->top = NULL;
}

void push312(STACK *s, int val)
{
    struct node312 *current = malloc(sizeof(struct node312));
    if (current == NULL)
        printf("Overflow");
    current->data = val;
    current->next = s->top;
    s->top = current;
}

void pop312(STACK *s, int *val)
{
    if (s->top == NULL)
        printf("Underflow");

    struct node312 *ptr;
    *val = s->top->data;
    ptr = s->top;
    s->top = ptr->next;
    free(ptr);
}

void display312(STACK s)
{
    if (s.top == NULL)
        printf("The list is empty\n");
    else
    {
        while (s.top != NULL)
        {
            printf("%d ", s.top->data);
            s.top = s.top->next;
        }
        printf("\n");
    }
}

void check312(STACK *s)
{
    if (s->top == NULL)
        printf("The list is empty\n");
    else
    {
        printf("The list is not empty: ");
        display(*s);
    }
}

int STACK2()
{
    STACK s1;
    init(&s1);

    int opt, n, p;
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
            check312(&s1);
            break;
        case 2:
            display312(s1);
            break;
        case 3:
            printf("\nEnter Element to push: ");
            scanf("%d", &n);
            push312(&s1, n);
            break;
        case 4:
            pop312(&s1, &p);
            printf("The value %d is deleted\n", p);
            break;
        case 5:
            exit(0);
            break;
        }
    }

    return 0;
}