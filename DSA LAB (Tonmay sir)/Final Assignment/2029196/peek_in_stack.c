/*Q1. WAP to implement a STACK71 which will support three additional operations in
addition to push71 and pop71:
a) peekLowestElement71 - return the lowest element in the STACK71 without
removing it from the STACK71
b) peekHighestElement71 - return the highest element in the STACK71 without
removing it from the STACK71
c) peekMiddleElement71 - return the (size/2+1) th lowest element in the STACK71
without removing it from the STACK71.
*/

#define MAX1 15

typedef struct
{
    int data[MAX1];
    int top;
} STACK71;

void push71(STACK71 *s, int value);
void pop71(STACK71 *s, int *temp);
void display71(STACK71 *s);
int empty71(STACK71 *s);
void peek71(STACK71 *s);
int input71();
void peekLowestElement71(STACK71 *s);
void peekHighestElement71(STACK71 *s);
void peekMiddleElement71(STACK71 *s);

void init71(STACK71 *s)
{
    s->top = -1; // init71ially we take top to be -1
}

int peekinSTACK()
{
    int cont = 1, value, b;
    STACK71 s1;
    init71(&s1);
    do
    {
        printf("\n1.push71\n2.pop71\n3.CHECK IF EMPTY\n4.peek71\n5.display71 STACK71:\n");
        int choice = input71();
        switch (choice)
        {
        case 1:
        {
            printf("\nEnter element in stack: ");
            scanf("%d", &value);
            push71(&s1, value);
            break;
        }

        case 2:
        {
            printf("\npop71ping an item: ");
            pop71(&s1, &b);
            break;
        }

        case 3:
        {
            printf("\nChecking if the stack is empty: ");
            int resp = empty71(&s1);
            if (resp != 1)
            {
                printf("NOT EMPTY\n");
            }
            break;
        }
        case 4:
        {
            printf("\nSelect peek71 option:n\n1.peekLowestElement71\n2. peekHighestElement71\n3. peekMiddleElement71: ");
            int select = input71();
            switch (select)
            {
            case 1:
            {
                peekLowestElement71(&s1);
                break;
            }
            case 2:
            {
                peekHighestElement71(&s1);
                break;
            }
            default:
            {
                peekMiddleElement71(&s1);
                break;
            }
            }
            break;
        }
        default:
        {
            printf("\nstack entered: top-> ");
            display71(&s1);
            break;
        }
        }
        printf("\nDo you wish to continue?\n1.YES\n2.No: ");
        int r;
        scanf("%d", &r);
        if (r != 1)
        {
            cont++;
        }
    } while (cont == 1);

    printf("\nDo you wish to go again?\n1.YES\n2.No: ");
    int r;
    scanf("%d", &r);
    if (r != 1)
    {
        cont == 1;
    }
}

void push71(STACK71 *s, int val)
{
    if (s->top == MAX1 - 1)
    {
        printf("\nOVERFLOW. stack IS ALREADY FULL.");
        return;
    }
    else
    {
        s->top++;
        s->data[s->top] = val;
        return;
    }
}

void pop71(STACK71 *s, int *temp)
{
    if (s->top == -1)
    {
        printf("\nUNDERFLOW");
        return;
    }
    else
    {
        *temp = s->data[s->top];
        printf("\npop71ped item: %d\n", *temp);
        s->top--;
        return;
    }
}

int empty71(STACK71 *s)
{
    if (s->top == -1)
    {
        printf("\nstack is empty");
        return 1;
    }
    else
    {
        return 0;
    }
}

void display71(STACK71 *s)
{
    if (s->top == -1)
    {
        printf("\nstack is empty");
        return;
    }
    else
    {
        int i;
        for (i = s->top; i >= 0; i--)
        {
            printf("\t%d\t", s->data[i]);
        }
    }
}
int input71()
{
    int num;
    scanf("%d", &num);
    return num;
}
void peek71(STACK71 *s)
{
    if (s->top == -1)
    {
        printf("\nstack is empty");
        return;
    }
    else
    {
        printf("\ntop-> %d", s->data[s->top]);
    }
}

void peekLowestElement71(STACK71 *s)
{
    int min;
    if (s->top == -1)
    {
        printf("\nstack is empty");
        return;
    }

    else
    {
        min = s->data[s->top];
        int i;
        for (i = s->top; i >= 0; i--)
        {
            if (s->data[i] < min)
            {
                min = s->data[i];
            }
        }

        printf("\nLowest element of stack: %d", min);
    }
}

void peekMiddleElement71(STACK71 *s)
{
    if (s->top == -1)
    {
        printf("\nstack is empty");
        return;
    }

    else
    {
        int size = s->top + 1, pos = ((size / 2)), value, i;
        for (i = s->top; i >= 0; i--)
        {
            if (i == pos)
            {
                value = s->data[i];
            }
        }
        printf("\nRequired middle element: %d", value);
    }
}

void peekHighestElement71(STACK71 *s)
{
    int max;
    if (s->top == -1)
    {
        printf("\nstack is empty");
        return;
    }

    else
    {
        max = 0;
        int i;
        for (i = s->top; i >= 0; i--)
        {
            if (s->data[i] > max)
            {
                max = s->data[i];
            }
        }

        printf("\nHighest element of stack: %d", max);
    }
}