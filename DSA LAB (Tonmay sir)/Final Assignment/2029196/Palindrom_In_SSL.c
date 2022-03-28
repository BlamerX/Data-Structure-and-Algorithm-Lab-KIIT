// WAP to check whether a singly linked list is a palindrome or not .

struct node14
{
    char data;
    struct node14 *next;
};

bool isPalindrome(struct node14 *head14, int count)
{
    struct node14 *front, *rear;
    int i = 0;

    while (i != count / 2)
    {
        front = rear = head14;
        for (int j = 0; j < i; j++)
            front = front->next;
        for (int j = 0; j < count - (i + 1); j++)
            rear = rear->next;
        if (front->data != rear->data)
            return false;
        else
            i++;
    }
    return true;
}

void getData14(struct node14 **head14_ref, char new_data)
{
    struct node14 *new_node14 = (struct node14 *)malloc(sizeof(struct node14));

    new_node14->data = new_data;
    new_node14->next = (*head14_ref);
    (*head14_ref) = new_node14;
}

int PalindromInSSL()
{
    struct node14 *head14 = NULL;
    char str[] = "kanak";
    int count = (sizeof(str) / sizeof(str[0])) - 1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        getData14(&head14, str[i]);
    }
    isPalindrome(head14, count) ? printf("Is Palindrome\n") : printf("Not Palindrome\n");

    return 0;
}