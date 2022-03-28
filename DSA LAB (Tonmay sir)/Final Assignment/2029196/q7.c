// WAP to add two sparse matrix.

struct node97
{
    int row97;
    int column97;
    int val97;
    struct node97 *next97;
};

void create97(struct node97 **head)
{
    struct node97 *ptr, *current;
    *head = malloc(sizeof(struct node97));
    (*head)->next97 = NULL;
    printf("Enter the row97,column97 and no of val97ues of matrix: ");
    scanf("%d%d%d", &(*head)->row97, &(*head)->column97, &(*head)->val97);
    ptr = *head;
    for (int i = 0; i < (*head)->val97; i++)
    {
        current = malloc(sizeof(struct node97));
        current->next97 = NULL;
        printf("Enter row97, column97 and val97ue: ");
        scanf("%d%d%d", &current->row97, &current->column97, &current->val97);
        ptr->next97 = current;
        ptr = current;
    }
}

void addition97(struct node97 *A, struct node97 *B, struct node97 **C)
{
    struct node97 *ptr, *ptr1, *current, *prev;
    if (A->row97 != B->row97 || A->column97 != B->column97)
        return;
    *C = malloc(sizeof(struct node97));
    (*C)->row97 = A->row97;
    (*C)->column97 = A->column97;
    (*C)->val97 = A->val97 + B->val97;
    (*C)->next97 = NULL;
    ptr = *C;

    for (ptr1 = A->next97; ptr1 != NULL; ptr1 = ptr1->next97)
    {
        current = malloc(sizeof(struct node97));
        current->row97 = ptr1->row97;
        current->column97 = ptr1->column97;
        current->val97 = ptr1->val97;
        current->next97 = NULL;
        ptr->next97 = current;
        ptr = current;
    }

    for (ptr1 = B->next97; ptr1 != NULL; ptr1 = ptr1->next97)
    {
        current = malloc(sizeof(struct node97));
        current->row97 = ptr1->row97;
        current->column97 = ptr1->column97;
        current->val97 = ptr1->val97;
        current->next97 = NULL;
        ptr->next97 = current;
        ptr = current;
    }

    for (ptr = (*C)->next97; ptr != NULL; ptr = ptr->next97)
    {
        prev = ptr;
        ptr1 = ptr->next97;
        while (ptr1 != NULL)
        {
            if (ptr->row97 == ptr1->row97 && ptr->column97 == ptr1->column97)
            {
                ptr->val97 += ptr1->val97;
                prev->next97 = ptr1->next97;
                free(ptr1);
                ptr1 = prev;
                (*C)->val97--;
            }
            prev = ptr1;
            ptr1 = ptr1->next97;
        }
    }
}

void display97(struct node97 *head)
{
    struct node97 *current = head;
    printf("row97 column97 val97ue\n");
    while (current != NULL)
    {
        printf("%d\t%d\t  %d", current->row97, current->column97, current->val97);
        current = current->next97;
        printf("\n");
    }
    free(current);
    printf("\n");
}

int q7()
{
    struct node97 *A, *B, *C;
    A = B = C = NULL;

    create97(&A);
    create97(&B);

    addition97(A, B, &C);
    display97(C);

    return 0;
}