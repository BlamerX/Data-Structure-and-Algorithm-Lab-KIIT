// WAP to replace every array element by multiplication of previous and next of an n element.

int PreviousMultiplication()
{
    int n;
    printf("Enter the no of elements in Array: ");
    scanf("%d", &n);

    int arr[n], mul[n], multi = 1;
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        multi *= arr[i];
        mul[i] = multi;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", mul[i]);
    }

    printf("\n");

    return 0;
}