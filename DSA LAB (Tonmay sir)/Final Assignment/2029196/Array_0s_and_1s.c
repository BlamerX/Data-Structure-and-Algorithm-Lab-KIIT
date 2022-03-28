// You are given an array of 0s and 1s in random order.Segregate 0s on left side and 1s on right side of the array.Traverse array only once.

int Array0sand1s()
{
    int n;
    printf("Enter the no of elements in Array: ");
    scanf("%d", &n);

    int arr[n], count = 0;
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count++;
    }

    for (int i = 0; i < n; i++)
    {
        if (i < count)
            arr[i] = 0;
        else
            arr[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}