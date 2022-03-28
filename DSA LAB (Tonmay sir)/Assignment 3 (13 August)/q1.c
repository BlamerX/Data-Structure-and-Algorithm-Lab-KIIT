// WAP to store n employees data such as employee name, gender, designation, department, basicpay etc using structures with dynamically memory allocation.Calculate the gross pay of each
//    employees as follows : Gross pay = basic pay + HR + DA
// HR = 25 % of basic, DA = 75 % of basic

#include <stdio.h>
#include <stdlib.h>

struct employee
{
    char name[20];
    char gender[8];
    char designation[20];
    char department[20];
    float basicpay, grosspay, HR, DA;
};

void getData(struct employee **emp, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Name of employee %d: ", i + 1);
        scanf("%s", (*emp + i)->name);
        printf("Enter the Gender of employee %d: ", i + 1);
        scanf("%s", (*emp + i)->gender);
        printf("Enter the Designation of employee %d: ", i + 1);
        scanf("%s", (*emp + i)->designation);
        printf("Enter the Department of employee %d: ", i + 1);
        scanf("%s", (*emp + i)->department);
        printf("Enter the Basicpay of employee %d: ", i + 1);
        scanf("%f", &(*emp + i)->basicpay);
    }
}

void calculate(struct employee **emp, int n)
{
    for (int i = 0; i < n; i++)
    {
        (*emp + i)->DA = ((*emp + i)->basicpay * 25) / 100;
        (*emp + i)->HR = ((*emp + i)->basicpay * 75) / 100;
        (*emp + i)->grosspay = ((*emp + i)->basicpay + (*emp + i)->DA + (*emp + i)->HR);
    }
}

void displayData(struct employee **emp, int n)
{
    printf("\nNAME\tGENDER\tDESIGNATION\tDEPARTMENT\tGROSS PAY\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t%s\t%s\t%s\t%0.3f\n", (*emp + i)->name, (*emp + i)->gender, (*emp + i)->designation, (*emp + i)->department, (*emp + i)->grosspay);
    }
}

int main()
{
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Memory allocation
    struct employee *e;

    e = malloc(n * sizeof(struct employee));

    getData(&e, n);
    calculate(&e, n);
    displayData(&e, n);

    free(e);

    return 0;
}