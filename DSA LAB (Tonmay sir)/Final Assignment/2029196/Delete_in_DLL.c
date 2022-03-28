// Write a menu driven program to perform the following operations in a double linked list by
// using suitable user defined functions for each case.
// a) Traverse the list forward
// b) Traverse the list backward
// c) Check if the list is empty
// d) Insert a node at the certain position (at beginning/end/any position)
// e) Delete a node at the certain position (at beginning/end/any position)
// f) Delete a node for the given key
// g) Count the total number of nodes
// h) search2625 for an element in the linked list
// Verify & validate each function from main method.

struct nodeDLL24
{
    int data;
    struct nodeDLL24 *next;
    struct nodeDLL24 *prev;
} *head24 = NULL;

void printListForwardDLL24();

void insertAtBegining24(int newData)
{
    struct nodeDLL24 *newNode = malloc(sizeof(struct nodeDLL24));

    newNode->data = newData;
    newNode->next = head24;
    newNode->prev = NULL;
    if (head24 != NULL)
        head24->prev = newNode;
    head24 = newNode;
}

void insertAtEnd24(int newData)
{

    struct nodeDLL24 *newNode = malloc(sizeof(struct nodeDLL24));
    struct nodeDLL24 *last = head24;

    newNode->data = newData;
    newNode->next = NULL;

    if (head24 == NULL)
    {
        newNode->prev = NULL;
        head24 = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    newNode->prev = last;
    return;
}

void insertAtIndex24(int newData)
{

    int position;
    printf("Enter the index: ");
    scanf("%d", &position);

    struct nodeDLL24 *newNode, *ptr;

    if (head24 == NULL)
        printf("Error, List is Empty\n");
    else
    {
        ptr = head24;
        int i = 1;
        while (i < position - 1 && ptr != NULL)
        {
            ptr = ptr->next;
            i++;
        }
        if (position == 1)
            insertAtBegining24(newData);
        else if (ptr != NULL)
        {
            newNode = malloc(sizeof(struct nodeDLL24));
            newNode->data = newData;
            newNode->next = ptr->next;
            newNode->prev = ptr;

            if (ptr->next != NULL)
                ptr->next->prev = newNode;
            ptr->next = newNode;
        }
        else
            insertAtEnd24(newData);
    }
}

void insertInDLL24()
{
    int ch, Data;
    printf("\n");
    printf("1. Insert a node at beginning\n");
    printf("2. Insert a node at any position\n");
    printf("3. Insert a node at end\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    printf("Enter the Data: ");
    scanf("%d", &Data);
    if (ch == 1)
        insertAtBegining24(Data);
    else if (ch == 2)
        insertAtIndex24(Data);
    else if (ch == 3)
        insertAtEnd(Data);
    else
        printf("Invalid argument");

    printListForwardDLL24();

    printf("\n");
}

void checkDLLForEmpty24()
{
    if (head24 == NULL)
        printf("The List is empty\n\n");
    else
        printf("The List is Not empty\n\n");
}

void deleteAtBegining24()
{
    struct nodeDLL24 *current;
    if (head24 == NULL)
        printf("List is empty ERROR Deleting");
    else
    {
        current = head24;
        head24 = head24->next;
        head24->prev == NULL;
        free(current);
    }
}

void deleteAtIndex24()
{
    int position;
    printf("Enter the index to delete: ");
    scanf("%d", &position);

    struct nodeDLL24 *temp = head24;

    for (int i = 0; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    else
        printf("\nInvalid position!\n");
}

void deleteAtEnd24()
{
    struct nodeDLL24 *current;
    if (head24 == NULL)
        printf("List is empty ERROR Deleting");
    else
    {
        current = head24;
        while (current->next != 0)
        {
            current->prev = current;
            current = current->next;
        }
        free(current);
        current->prev->next = 0;
    }
}

void deleteInDLL24()
{
    int ch;
    printf("\n");
    printf("1. Delete a node at beginning\n");
    printf("2. Delete a node at any position\n");
    printf("3. Delete a node at end\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    if (ch == 1)
        deleteAtBegining24();
    else if (ch == 2)
        deleteAtIndex24();
    else if (ch == 3)
        deleteAtEnd24();
    else
        printf("Invalid argument");

    printListForwardDLL24();

    printf("\n");
}

void printListForwardDLL24()
{
    struct nodeDLL24 *node = head24, *last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
}

void printListBackwardDLL24()
{
    struct nodeDLL24 *node = head24, *last;
    printf("\nTraversal in reverse direction \n");
    while (last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

void deleteByKeyInDLL24()
{
    int key;
    printf("Enter the key: ");
    scanf("%d", &key);

    struct nodeDLL24 *temp = head24;
    if (head24->data == key)
    {
        head24 = head24->next;
        head24->prev = NULL;
        temp->next = temp->prev = NULL;
        free(temp);
    }
    else
    {
        while (temp->next->data != key)
            temp = temp->next;
        struct nodeDLL24 *temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next->prev = temp;
    }

    printListForwardDLL24();
    printf("\n");
}

void countNodeInDLL()
{
    int count = 1;
    while (head24->next != NULL)
    {
        head24 = head24->next;
        count++;
    }
    printf("Total number of Nodes are %d\n", count);
}

bool search24(int n)
{
    struct nodeDLL24 *current = head24;
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

void searchListDLL()
{
    int num;
    printf("Enter the value you want to search: ");
    scanf("%d", &num);

    search24(num) ? printf("\nThe value is present\n") : printf("\nThe value is not present\n");
}

int DeleteOfDLL()
{
    int ch;
    while (1)
    {
        printf("\n---LINKED LIST PROGRAMS---\n");
        printf("1. Traverse the list forward\n");
        printf("2. Traverse the list backward\n");
        printf("3. Check if the list is empty\n");
        printf("4. Insert a node at the certain position (at beginning/end/any position)\n");
        printf("5. Delete a node at the certain position (at beginning/end/any position)\n");
        printf("6. Delete a node for the given key\n");
        printf("7. Count the total number of nodes\n");
        printf("8. Search for an element in the linked list\n");
        printf("9. EXIT\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printListForwardDLL24();
            break;
        case 2:
            printListBackwardDLL24();
            break;
        case 3:
            checkDLLForEmpty24();
            break;
        case 4:
            insertInDLL24();
            break;
        case 5:
            deleteInDLL24();
            break;
        case 6:
            deleteByKeyInDLL24();
            break;
        case 7:
            countNodeInDLL();
            break;
        case 8:
            searchListDLL();
            break;
        case 9:
            exit(1);
            break;
        default:
            printf("INVALID CHOICE!!");
            break;
        }
    }

    return 0;
}