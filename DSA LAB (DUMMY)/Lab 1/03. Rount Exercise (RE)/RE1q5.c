// WAP to print all permutations of a given string using pointers

#include <stdio.h>
#include <string.h>

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int start, int end)
{
    if (start == end)
        printf("%s ", a);
    else
    {
        for (int i = start; i <= end; i++)
        {
            swap((a + start), (a + i));
            permute(a, start + 1, end);
            swap((a + start), (a + i));
        }
    }
}

int main()
{
    char str[20];
    scanf("%s", str);

    int n;
    n = strlen(str);

    permute(str, 0, n - 1);

    return 0;
}