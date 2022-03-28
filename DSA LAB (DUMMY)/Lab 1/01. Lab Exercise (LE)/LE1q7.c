// WAP to swap three numbers in cyclic order using Call by Reference. In other words, WAP that takes three variable(a, b, c) in as separate parameters and rotates the values stored so that value a goes to be, b, to c and c to a.

#include <stdio.h>

void cyclicSwap(int *a, int *b, int *c)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = *c;
    *c = temp;
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    cyclicSwap(&a, &b, &c); //Call by refrence

    printf("Value after swapping:\n");
    printf("a = %d\nb = %d\nc = %d", a, b, c);

    return 0;
}