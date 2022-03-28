// WAP to reverse a stack with using extra stack.

#define MAX2 100

int top66 = -1;
int item;
char stack_string[MAX2];

int isEmpty66()
{
    if (top66 == -1)
        return 1;
    else
        return 0;
}

void pushChar66(char item)
{
    if (isFull66())
    {
        printf("\nStack is FULL !!!\n");
        return;
    }
    top66 = top66 + 1;
    stack_string[top66] = item;
}

char popChar66()
{
    if (isEmpty66())
    {
        printf("\nStack is EMPTY!!!\n");
        return 0;
    }
    item = stack_string[top66];
    top66 = top66 - 1;
    return item;
}

int isFull66()
{
    if (top66 == MAX2 - 1)
        return 1;
    else
        return 0;
}

int STACKReverse()
{
    char str[MAX2];
    int i;

    printf("Input a string: ");
    scanf("%[^\n]s", str);

    for (i = 0; i < strlen(str); i++)
        pushChar66(str[i]);

    for (i = 0; i < strlen(str); i++)
        str[i] = popChar66();

    printf("Reversed String is: %s\n", str);

    return 0;
}