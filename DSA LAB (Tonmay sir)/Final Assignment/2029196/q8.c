// WAP to multiply two sparse matrix.

struct next9898
{
    int row98;
    int column98;
    int val98;
    struct next9898 *next98;
};

void create98(struct next9898 **head)
{
    struct next9898 *ptr, *current;
    *head = malloc(sizeof(struct next9898));
    (*head)->next98 = NULL;
    printf("Enter the row98,column98 and no of val98ues of matrix: ");
    scanf("%d%d%d", &(*head)->row98, &(*head)->column98, &(*head)->val98);
    ptr = *head;
    for (int i = 0; i < (*head)->val98; i++)
    {
        current = malloc(sizeof(struct next9898));
        current->next98 = NULL;
        printf("Enter row98, column98 and val98ue: ");
        scanf("%d%d%d", &current->row98, &current->column98, &current->val98);
        ptr->next98 = current;
        ptr = current;
    }
}

void multiplication98(struct next9898 *A, struct next9898 *B, struct next9898 **C)
{
    struct next9898 *ptr, *ptr1, *current, *prev;
    if (A->column98 != B->row98)
        return;
    *C = malloc(sizeof(struct next9898));
    (*C)->row98 = A->row98;
    (*C)->column98 = A->column98;
    (*C)->val98 = 0;
    (*C)->next98 = NULL;
    ptr = *C;
    for (ptr = A->next98; ptr != NULL; ptr = ptr->next98)
    {
        for (ptr1 = B->next98; ptr1 != NULL; ptr1 = ptr1->next98)
        {
            if (ptr->column98 == ptr1->row98)
            {
                current = malloc(sizeof(struct next9898));
                current->row98 = ptr->row98;
                current->column98 = ptr1->column98;
                current->val98 = ptr->val98 * ptr1->val98;
                current->next98 = NULL;
                ptr->next98 = current;
                ptr = current;
                (*C)->val98++;
            }
        }
    }
    for (ptr = (*C)->next98->next98; ptr != NULL; ptr = ptr->next98)
    {
        prev = ptr;
        ptr1 = ptr->next98;
        while (ptr1 != NULL)
        {
            if (ptr->row98 == ptr1->row98 && ptr->column98 == ptr1->column98)
            {
                ptr->val98 = ptr->val98 + ptr1->val98;
                prev->next98 = ptr1->next98;
                free(ptr);
                ptr1 = prev;
                (*C)->val98--;
            }
            prev = ptr1;
            ptr1 = ptr1->next98;
        }
    }
}

void display98(struct next9898 *head)
{
    struct next9898 *current = head;
    printf("row98 column98 val98ue\n");
    while (current != NULL)
    {
        printf("%d\t%d\t  %d", current->row98, current->column98, current->val98);
        current = current->next98;
        printf("\n");
    }
    free(current);
    printf("\n");
}

int q8()
{
    struct next9898 *A, *B, *C;
    A = B = C = NULL;

    create98(&A);
    create98(&B);

    multiplication98(A, B, &C);
    display98(C);

    return 0;
}