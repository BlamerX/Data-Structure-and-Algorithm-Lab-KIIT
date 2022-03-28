// WAP to read an array of integers and search for an element using linear search.

int LinearSearchArray()
{
    int array[100], search, c, n, count = 0;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    printf("Enter %d numbers: ", n);

    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);

    printf("Enter a number to search: ");
    scanf("%d", &search);

    for (c = 0; c < n; c++)
    {
        if (array[c] == search)
        {
            printf("%d is present at location %d.\n", search, c + 1);
            count++;
        }
    }
    if (count == 0)
        printf("%d isn't present in the array.\n", search);
    else
        printf("%d is present %d times in the array.\n", search, count);

    return 0;
}