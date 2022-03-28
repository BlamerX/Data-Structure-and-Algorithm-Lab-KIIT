// WAP to find out the smallest and largest element stored in an array of n integers.

int LargestAndSmallestElementInArray()
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

    int max = arr[0], min = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("min = %d,max = %d", min, max);

    printf("\n");

    return 0;
}