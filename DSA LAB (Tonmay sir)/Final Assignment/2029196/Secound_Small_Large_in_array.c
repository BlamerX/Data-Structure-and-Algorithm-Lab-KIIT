// WAP to find out the second smallest and second largest element stored in an array.

int SecoundSmallestAndLargest()
{
    int n, temp = 0;
    printf("Enter the no of elements in Array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            if (arr[j] >= arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Secound smallest is: %d\nSecound largest is: %d", arr[1], arr[n - 2]);

    printf("\n");

    return 0;
}