// Given a sorted array of length n, WAP to find the number in array that appears more than or equal to n / 2 times.It can be assumed that such element always exists.
// Input : 2 3 3 4 Output : 3
// Input : 3 4 5 5 5 Output : 5

int findMajority(int arr[], int n)
{
    return arr[n / 2];
}

int nBy2Times()
{
    int arr[] = {3, 4, 5, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", findMajority(arr, n));
    return 0;
}