// WAP to search an element in a simple linked list, if found delete that node13 node13 and insert13 that node13 at beginning.Otherwise display an appropriate message.

struct node13
{
    int data;
    struct node13 *next;
};

struct node13 *head13 = NULL, *tail13 = NULL;

void insert13(int newData)
{
    struct node13 *newnode13 = malloc(sizeof(struct node13));

    newnode13->data = newData;
    newnode13->next = head13;
    head13 = newnode13;
}

bool search(int n)
{
    struct node13 *current = head13;
    while (current != NULL)
    {
        if (current->data == n)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

void deletionAtKey(int key)
{
    struct node13 *current = head13, *previous;

    if (current != NULL && current->data == key)
    {
        head13 = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != key)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
        return;

    previous->next = current->next;
    free(current);
    insertAtBegining13(key);
}

void insertAtBegining13(int newData)
{
    struct node13 *newnode13 = malloc(sizeof(struct node13));

    newnode13->data = newData;
    newnode13->next = head13;
    head13 = newnode13;
}
void operationOnList()
{
    int num;
    printf("Enter the value you want to search: ");
    scanf("%d", &num);

    search(num) ? deletionAtKey(num) : printf("The value is not present\n\n");

    insertAtBegining13(num);
}

void displayList13()
{
    printf("\nThe node13 is:\n");
    while (head13 != NULL)
    {
        printf("%d ", head13->data);
        head13 = head13->next;
    }
    free(head13);
    printf("\n\n");
}

int SearchInSSL()
{
    insert13(2);
    insert13(0);
    insert13(2);
    insert13(9);
    insert13(1);
    insert13(9);
    insert13(6);

    displayList13();
    operationOnList();
    displayList13();

    return 0;
}