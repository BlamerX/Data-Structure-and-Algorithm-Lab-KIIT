// Write a menu driven program to perform the following operations in a single cicular linked
// list by using suitable user defined functions for each case.
// a) Traverse the list
// b) Check if the list is empty
// c) Insert a node at the certain position
// d) Delete a node at the certain position
// e) Delete a node for the given key
// f) Count the total number of nodes
// g) Search for an element in the linked list
// Verify & validate each function from main method.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void displaySCLL()
{
}

void checkSCLLForEmpty()
{
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n---LINKED LIST PROGRAMS---\n");
        printf("1. Traverse the list\n");
        printf("2. Check if the list is empty\n");
        printf("3. Insert a node at the certain position (at beginning/end/any position)\n");
        printf("4. Delete a node at the certain position (at beginning/end/any position)\n");
        printf("5. Delete a node for the given key\n");
        printf("6. Count the total number of nodes\n");
        printf("7. Search for an element in the linked list\n");
        printf("8. EXIT\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            displaySCLL();
            break;
        case 2:
            checkSCLLForEmpty();
            break;
        case 3:
            checkDLLForEmpty();
            break;
        case 4:
            insertInDLL();
            break;
        case 5:
            deleteInDLL();
            break;
        case 6:
            deleteByKeyInDLL();
            break;
        case 7:
            countNodeInDLL();
        case 8:
            searchListDLL();
            break;
        case 9:
            exit(1);
            break;
        default:
            printf("INVALID CHOICE!!");
            break;
        }
    }

    return 0;
}