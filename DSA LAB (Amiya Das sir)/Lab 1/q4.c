// WAP to input n elements to an array and display that array using dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *ptr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }

    free(ptr);

    return 0;
}