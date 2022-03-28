// WAP to exchange the biggest and smallest element into the array of n intergers.

int exchange()
{

    int n, temp;
    printf("Enter the no of elements in Array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int min = arr[0], max = arr[0], minat, maxat;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxat = i;
        }
        if (arr[i] < min)
        {
            min = arr[i];
            minat = i;
        }
    }

    temp = arr[minat];
    arr[minat] = arr[maxat];
    arr[maxat] = temp;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}