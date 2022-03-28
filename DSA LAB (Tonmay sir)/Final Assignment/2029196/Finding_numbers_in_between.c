// Given an unsorted array of size n, WAP to find and display the number of elements between two elements a and b (both inclusive). E.g. Input: arr = [1, 2, 2, 7, 5, 4], a=2 and b=5, Output: 4 and the numbers are: 2, 2, 5, 4.

int BetweenSearchInArray()
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

    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == a)
        {
            a = i;
        }
        else if (arr[i] == b)
        {
            b = i;
        }
    }

    printf("%d\n", (b - a) + 1);

    for (int i = a; i <= b; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}