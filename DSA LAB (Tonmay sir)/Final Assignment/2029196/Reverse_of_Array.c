// WAP to reverse the contents of an array of n elements.

int ReverseArray()
{
    int n, temp = 0;
    printf("Enter the no of elements in Array: ");
    scanf("%d", &n);
    int arr[n], arr1[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr1[j];
        arr1[j] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }

    printf("\n");
    return 0;
}