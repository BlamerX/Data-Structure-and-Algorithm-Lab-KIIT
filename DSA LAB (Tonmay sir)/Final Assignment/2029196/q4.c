// WAP to find out the transpose of a sparse matrix.

struct node94
{
    int row;
    int column;
    int val;
    struct node94 *next;
};

void create94(struct node94 **head)
{
    struct node94 *ptr, *current;
    *head = malloc(sizeof(struct node94));
    (*head)->next = NULL;
    printf("Enter the row,column and no of values of matrix: ");
    scanf("%d%d%d", &(*head)->row, &(*head)->column, &(*head)->val);
    ptr = *head;
    for (int i = 0; i < (*head)->val; i++)
    {
        current = malloc(sizeof(struct node94));
        current->next = NULL;
        printf("Enter row, column and value: ");
        scanf("%d%d%d", &current->row, &current->column, &current->val);
        ptr->next = current;
        ptr = current;
    }
}

void transpose(struct node94 **A)
{
    struct node94 *ptr;
    int temp;

    for (ptr = *A; ptr != NULL; ptr = ptr->next)
    {
        temp = ptr->row;
        ptr->row = ptr->column;
        ptr->column = temp;
    }
}

void display94(struct node94 *head)
{
    struct node94 *current = head;
    printf("Row Column Value\n");
    while (current != NULL)
    {
        printf("%d\t%d\t  %d", current->row, current->column, current->val);
        current = current->next;
        printf("\n");
    }
    free(current);
    printf("\n");
}

int q4()
{
    struct node94 *A;
    A = NULL;

    create94(&A);
    transpose(&A);
    display94(A);

    return 0;
}