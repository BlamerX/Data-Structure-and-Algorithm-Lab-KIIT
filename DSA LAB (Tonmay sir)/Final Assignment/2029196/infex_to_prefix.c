// WAP to convert an infix expression into its equivalent prefix notation.

struct stack64
{
    int top;
    int maxSize;
    int *array;
};

struct stack64 *create(int max)
{
    struct stack64 *stack64 = (struct stack64 *)malloc(sizeof(struct stack64));
    stack64->maxSize = max;
    stack64->top = -1;
    stack64->array = (int *)malloc(stack64->maxSize * sizeof(int));
    return stack64;
}

int isFull(struct stack64 *stack64)
{
    if (stack64->top == stack64->maxSize - 1)
    {
        printf("Will not be able to push64 maxSize reached\n");
    }
    return stack64->top == stack64->maxSize - 1;
}

int isEmpty64(struct stack64 *stack64)
{
    return stack64->top == -1;
}

void push64(struct stack64 *stack64, int item)
{
    if (isFull(stack64))
        return;
    stack64->array[++stack64->top] = item;
}

int pop64(struct stack64 *stack64)
{
    if (isEmpty64(stack64))
        return INT_MIN;
    return stack64->array[stack64->top--];
}

int peek64(struct stack64 *stack64)
{
    if (isEmpty64(stack64))
        return;
    return stack64->array[stack64->top];
}

int checkIfOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

int getPostfix(char *expression)
{
    int i, j;
    struct stack64 *stack64 = create(strlen(expression));
    if (!stack64)
        return -1;

    for (i = 0, j = -1; expression[i]; ++i)
    {
        if (checkIfOperand(expression[i]))
            expression[++j] = expression[i];
        else if (expression[i] == '(')
            push64(stack64, expression[i]);
        else if (expression[i] == ')')
        {
            while (!isEmpty64(stack64) && peek64(stack64) != '(')
                expression[++j] = pop64(stack64);
            if (!isEmpty64(stack64) && peek64(stack64) != '(')
                return -1;
            else
                pop64(stack64);
        }
        else
        {
            while (!isEmpty64(stack64) && precedence(expression[i]) <= precedence(peek64(stack64)))
                expression[++j] = pop64(stack64);
            push64(stack64, expression[i]);
        }
    }
    while (!isEmpty64(stack64))
        expression[++j] = pop64(stack64);
    expression[++j] = '\0';
}

void reverse(char *exp)
{

    int size = strlen(exp);
    int j = size, i = 0;
    char temp[size];

    temp[j--] = '\0';
    while (exp[i] != '\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp, temp);
}
void brackets(char *exp)
{
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
        i++;
    }
}
void InfixtoPrefix(char *exp)
{
    int size = strlen(exp);
    reverse(exp);
    brackets(exp);
    getPostfix(exp);
    reverse(exp);
}

int InfixToPrefix()
{
    printf("The infix is: ");

    char expression[] = "A+B-C/D";
    printf("%s\n", expression);
    InfixtoPrefix(expression);

    printf("The prefix is: ");
    printf("%s\n", expression);

    return 0;
}