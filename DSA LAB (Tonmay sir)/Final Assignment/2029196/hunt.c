// Given an array container and integer hunt.WAP to find whether hunt is present in container or not .If present,then triple the value of hunt and search again.Repeat these steps until hunt is not found.Finally return the value of hunt.

// Input : container = {1, 2, 3} and hunt = 1 then Output : 9

// Explanation : Start with hunt = 1. Since it is present in array, it becomes 3. Now 3 is present in array and hence hunt becomes 9. Since 9 is a not present,program return 9.

int hunt()
{
    int Container[] = {1, 2, 3};
    int hunt = 1, i, j, l, n, Flag = 1;

    l = sizeof(Container) / sizeof(Container[0]);

    printf("Initial Hunt Value = %d\n", hunt);
    while (Flag == 1)
    {
        Flag = 0;
        for (i = 0; i < l; i++)
        {
            if (hunt == Container[i])
            {
                printf("%d is in the hunt\n", hunt);
                Flag = 1;
                hunt = hunt * 3;
                printf("The current Hunt value is: %d\n", hunt);
            }
        }
    }
    printf("\nFinal Hunt Value = %d", hunt);
    return 0;
}