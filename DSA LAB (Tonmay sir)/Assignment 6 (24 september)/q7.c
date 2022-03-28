// WAP to sort the elements inside a stack using only push and pop operation.Any number of additional stacks may be used.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct
{
    struct node *top;
} STACK;

void init(STACK *s)
{
    s->top = NULL;
}

void push(STACK *s, int val)
{
    struct node *current;
    current = malloc(sizeof(struct node));
    if (current == NULL)
        printf("Overflow");
    current->data = val;
    current->next = s->top;
    s->top = current;
}

void pop(STACK *s, int *val)
{
    if (s->top == NULL)
        printf("Underflow");

    struct node *ptr;
    *val = s->top->data;
    ptr = s->top;
    s->top = ptr->next;
    free(ptr);
}

void insort(STACK *s, int val)
{
    if (isempty(*s))
        push(s, val);
    else
    {
        int d;
        pop(s, &d);
        if (d < val)
        {
            insort(s, val);
            push(s, d);
        }
        else
        {
            push(s, d);
            push(s, val);
        }
    }
}

int isempty(STACK s)
{
    if (s.top == NULL)
        return 1;
    else
        return 0;
}

void sort(STACK *s)
{
    if (isempty(*s) == 0)
    {
        int d;
        pop(s, &d);
        sort(s);
        insort(s, d);
    }
}

void display(STACK s)
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

int main()
{
    STACK s1;
    init(&s1);
    push(&s1, 5);
    push(&s1, 21);
    push(&s1, 9);
    push(&s1, 1);

    display(s1);

    sort(&s1);

    display(s1);

    return 0;
}