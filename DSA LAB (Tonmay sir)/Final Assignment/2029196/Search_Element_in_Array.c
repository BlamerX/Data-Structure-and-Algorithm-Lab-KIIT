// WAP to search an element in an array of n numbers.

int SearchArray()
{
    int n;
    printf("Enter the no of elements in Array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int k, present;
    printf("Enter the number to search: ");
    scanf("%d", &k);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            present = 1;
            n = i;
        }
    }

    if (present == 1)
    {
        printf("%d is present in the array at index = %d", k, n);
    }
    else
    {
        printf("Not present");
    }

    printf("\n");

    return 0;
}