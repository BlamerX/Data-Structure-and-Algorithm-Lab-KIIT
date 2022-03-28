#include <stdio.h>

struct employee
{
    char name[100];
};

int main()
{
    struct employee *emp;
    printf("Enter your name: ");
    fgets(emp->name, 100, stdin);
    printf("Your Name is: %s", emp->name);
    return 0;
}