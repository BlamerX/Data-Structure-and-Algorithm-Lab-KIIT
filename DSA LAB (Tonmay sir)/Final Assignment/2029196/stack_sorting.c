// WAP to sort the elements inside a STACK67 using only push and pop operation.Any number of additional STACK67s may be used.

struct node67
{
    int data;
    struct node67 *next;
};

typedef struct
{
    struct node67 *top67;
} STACK67;

void init67(STACK67 *s)
{
    s->top67 = NULL;
}

void push67(STACK67 *s, int val)
{
    struct node67 *current;
    current = malloc(sizeof(struct node67));
    if (current == NULL)
        printf("Overflow");
    current->data = val;
    current->next = s->top67;
    s->top67 = current;
}

void pop67(STACK67 *s, int *val)
{
    if (s->top67 == NULL)
        printf("Underflow");

    struct node67 *ptr;
    *val = s->top67->data;
    ptr = s->top67;
    s->top67 = ptr->next;
    free(ptr);
}

void insort67(STACK67 *s, int val)
{
    if (isempty67(*s))
        push67(s, val);
    else
    {
        int d;
        pop67(s, &d);
        if (d < val)
        {
            insort67(s, val);
            push67(s, d);
        }
        else
        {
            push67(s, d);
            push67(s, val);
        }
    }
}

int isempty67(STACK67 s)
{
    if (s.top67 == NULL)
        return 1;
    else
        return 0;
}

void sort67(STACK67 *s)
{
    if (isempty67(*s) == 0)
    {
        int d;
        pop67(s, &d);
        sort67(s);
        insort67(s, d);
    }
}

void display67(STACK67 s)
{
    if (s.top67 == NULL)
        printf("The list is empty\n");
    else
    {
        while (s.top67 != NULL)
        {
            printf("%d ", s.top67->data);
            s.top67 = s.top67->next;
        }
        printf("\n");
    }
}

int StackSorting67()
{
    STACK67 s1;
    init67(&s1);
    push67(&s1, 5);
    push67(&s1, 21);
    push67(&s1, 9);
    push67(&s1, 1);

    display67(s1);

    sort67(&s1);

    display67(s1);

    return 0;
}