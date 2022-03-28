// WAP to create a double linked list of n nodes and display the linked list by using suitable user defined functions for create and display operations.

struct nodeDLL
{
    int data;
    struct nodeDLL *prev;
    struct nodeDLL *next;
} *head22 = NULL, *tail22 = NULL;

void createDLL(int n)
{
    int i, data;
    struct nodeDLL *newNode;

    if (n >= 1)
    {
        head22 = malloc(sizeof(struct nodeDLL));

        if (head22 != NULL)
        {
            printf("Enter data of 1 node: ");
            scanf("%d", &data);

            head22->data = data;
            head22->prev = NULL;
            head22->next = NULL;

            tail22 = head22;
            for (i = 2; i <= n; i++)
            {
                newNode = malloc(sizeof(struct nodeDLL));
                if (newNode != NULL)
                {
                    printf("Enter data of %d node: ", i);
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->prev = tail22;
                    newNode->next = NULL;

                    tail22->next = newNode;
                    tail22 = newNode;
                }
                else
                    break;
            }
        }
    }
}

void displayDLL()
{
    struct nodeDLL *temp;

    if (head22 == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head22;
        printf("\n\nDATA IN THE LIST:\n");

        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int DLL()
{
    int n;
    printf("Enter the no of nodes you want to create: ");
    scanf("%d", &n);
    createDLL(n);
    displayDLL();

    return 0;
}