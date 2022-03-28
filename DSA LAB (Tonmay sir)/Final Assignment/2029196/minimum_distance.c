// Given an unsorted array arr and two numbers x and y, find the minimum distance between x and y in arr.The array might also contain duplicates.You may assume that both x and y are different and present in arr.Input : arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, x = 3, y = 6 Output : Minimum distance between 3 and 6 is 4.
// 3 5 4 2 6 7 6 6 5 4 8 3

int MinimumDistance()
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

    int startat = a, endat = b;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == a)
        {
            startat = i;
        }
        if (arr[i] == b)
        {
            endat = i;
            break;
        }
    }

    int cout = 0;
    for (int i = startat; i < endat; i++)
    {
        cout++;
    }

    printf("Minimum distance between %d and %d is %d", a, b, (cout));
    printf("\n");
    return 0;
}