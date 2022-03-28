#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "DATE_AND_TIME.c"

// LAB 1
#include "smallest_and_largest_in_array.c"
#include "Reverse_of_Array.c"
#include "Search_Element_in_Array.c"
#include "Sort_of_Array.c"
#include "Finding_numbers_in_between.c"
#include "Exchange.c"

// LAB 2
#include "Array_Sorting.c"
#include "minimum_distance.c"
#include "Secound_Small_Large_in_array.c"
#include "Array_Even_Odd.c"
#include "Previous_multiplication.c"
#include "Count_Largest_Number.c"
#include "Array_0s_and_1s.c"
#include "Number_of_elements.c"
#include "Kth_Max_min.c"

// LAB 3
#include "Employee.c"
#include "Distance_addition.c"
#include "SSL.c"

// LAB 4
#include "Insert_in_SSL.c"
#include "Deletion_in_SSL.c"
#include "Search_in_SSL.c"
#include "Palindrom_In_SSL.c"
#include "Reverse_SSL.c"
#include "Rotate_SSL.c"
#include "Duplicate_removal_in_SSL.c"

// LAB 5
#include "DLL.c"
#include "Reverse_DLL.c"
#include "Delete_in_DLL.c"
#include "SCLL.c"
#include "Duplicate_Removal_In_DLL.c"
#include "Single_To_Circular.c"
#include "DDL_by_SLL.c"
#include "Middle_of_DLL.c"

// LAB 6
#include "stack.c"
#include "Stack2.c"
#include "infix_to_postfox.c"
#include "infex_to_prefix.c"
#include "bracket_matching.c"
#include "stack_reverse.c"
#include "stack_sorting.c"

// LAB 7
#include "peek_in_stack.c"
#include "dqueue.c"
#include "reverse_queue.c"
#include "circular_queue.c"

// LAB 8
#include "LSA.c"
#include "BSA.c"
#include "hunt.c"
#include "maj.c"
#include "rec.c"
#include "recb.c"

// LAB 9
#include "polynomial.c"
#include "q2.c"
#include "q3.c"
#include "q4.c"
#include "q5.c"
#include "q6.c"
#include "q7.c"
#include "q8.c"

// MAIN FUNCTION
int main()
{
    printf("-------------------------------------------------------\n\t\tSTUDENT DETAILS\n-------------------------------------------------------\nNAME - Adarsh Kumar\nRoll No - 2029196\nDate and Time - ");
    TimeAndDate();
    printf("-------------------------------------------------------\n\n\n\n");

    int ch, ch1;
    while (1)
    {
    p:
        printf("-------------------------------------------------------\n\t\tMAIN MENU\n-------------------------------------------------------\n");
        printf("0. Exit\n1. Array, pointer with Dynamic Memory Allocation\n2. Structure\n3. Linked list\n4. Stack\n5. Queue\n6. Searching & Sorting\n7. Polynomial / Sparse Matrix Representation, Addition & Multipilcation\n");
        printf("-------------------------------------------------------\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 0:
            exit(0);
            break;
        case 1:
            // Start of Array, pointer with Dynamic Memory Allocation
            while (1)
            {
                printf("-------------------------------------------------------\n\tArray, pointer with Dynamic Memory Allocation\n-------------------------------------------------------\n");
                printf("0. Exit\n1. Program to Find Largest and Smallest element in array\n2. Reverse the contents of an array\n3. Search an element in an array\n4. Sort of Array\n5. WAP to find and display the number of elements between two elements a and b (both inclusive)\n6. Exchange the biggest and smallest element\n7. Sorting an array\n8. Minimum distance between x and y in array\n9. Second smallest and second largest element stored in an array\n10. Arrange the elements of an array such that all even numbers are followed by all odd numbers\n11. Replace every array element by multiplication of previous and next\n12. Find the largest number and counts the occurrence of the largest number\n13. You are given an array of 0s and 1s in random order.Segregate 0s on left side and 1s on right side of the array\n14. Find and display the number of elements between two elements a and b(both inclusive)\n15. Find out the kth smallest and kth largest element\n");
                printf("-------------------------------------------------------\n\n");
                printf("Enter your choice: ");
                scanf("%d", &ch1);
                printf("\n");
                switch (ch1)
                {
                case 0:
                    goto p;
                    break;
                case 1:
                    LargestAndSmallestElementInArray();
                    break;
                case 2:
                    ReverseArray();
                    break;
                case 3:
                    SearchArray();
                    break;
                case 4:
                    SortingOfArray();
                    break;
                case 5:
                    BetweenSearchInArray();
                    break;
                case 6:
                    exchange();
                    break;
                case 7:
                    SortingOfArray();
                    break;
                case 8:
                    MinimumDistance();
                    break;
                case 9:
                    SecoundSmallestAndLargest();
                    break;
                case 10:
                    ArrangeEvenOdd();
                    break;
                case 11:
                    PreviousMultiplication();
                    break;
                case 12:
                    CountLargentNumber();
                    break;
                case 13:
                    Array0sand1s();
                    break;
                case 14:
                    NumberOfElements();
                    break;
                case 15:
                    KthMaxMin();
                    break;
                default:
                    printf("Invalid Option\n");
                    break;
                }
            }
            // End of Array, pointer with Dynamic Memory Allocation
        case 2:
            // Start of Structure
            while (1)
            {
                printf("-------------------------------------------------------\n\t\tStructure\n-------------------------------------------------------\n");
                printf("0. Exit\n1. WAP to store n employees data such as employee name, gender, designation, department, basicpay etc using structures with dynamically memory allocation.Calculate the gross pay of each employee\n2. WAP to add two distances (in km-meter)\n");
                printf("-------------------------------------------------------\n\n");
                printf("Enter your choice: ");
                scanf("%d", &ch1);
                printf("\n");
                switch (ch1)
                {
                case 0:
                    goto p;
                    break;
                case 1:
                    SingleLinkedList();
                    break;
                case 2:
                    DistanceAddition();
                    break;
                default:
                    printf("Invalid Option\n");
                    break;
                }
            }
        // End of Structure
        case 3:
            // Start of Linked List
            while (1)
            {
                printf("-------------------------------------------------------\n\t\tLinked List\n-------------------------------------------------------\n");
                printf("0. Exit\n1. Single Linked List (Menu Driven Program)\n2. Insert in SSL (Begining,Middle,End)\n3. Deletion in SSL (Begining,Middle,End)\n4. Search an element in a simple linked list\n5. check whether a singly linked list is a palindrome or not\n6. Display the contents of a linked list in reverse order\n7. Rotate the linked list counter - clockwise by k nodes\n8. Remove duplicates from a linked list\n9. Create a double linked list of n nodes and display\n10. Reverse the sequence elements in a double linked list\n11. Delete in DLL (Begining,Middle,End)\n12. Single Circular Linked List\n13. Remove the duplicates in a sorted double linked list\n14. Convert a given singly linked list to a circular list\n15. Implement a doubly linked list by using singly linked\n16. Print the middle of a double linked list\n17. Rotate the linked list counter - clockwise by k nodes\n");
                printf("-------------------------------------------------------\n\n");
                printf("Enter your choice: ");
                scanf("%d", &ch1);
                printf("\n");
                switch (ch1)
                {
                case 0:
                    goto p;
                    break;
                case 1:
                    SingleLinkedList();
                    break;
                case 2:
                    SSLInsertion();
                    break;
                case 3:
                    DeletionInSSL();
                    break;
                case 4:
                    SearchInSSL();
                    break;
                case 5:
                    PalindromInSSL();
                    break;
                case 6:
                    ReverseContentInSSL();
                    break;
                case 7:
                    ClockwiseRotationInSSL();
                    break;
                case 8:
                    RemovalOfDuplicatesInSSL();
                    break;
                case 9:
                    DLL();
                    break;
                case 10:
                    ReverseDisplayOfDLL();
                    break;
                case 11:
                    DeleteOfDLL();
                    break;
                case 12:
                    SCLL();
                    break;
                case 13:
                    DuplicateRemovalInDLL();
                    break;
                case 14:
                    SingularToCircular();
                    break;
                case 15:
                    DLLbySLL();
                    break;
                case 16:
                    MiddleOfDLL();
                    break;
                case 17:
                    ClockwiseRotationInSSL();
                    break;
                default:
                    printf("Invalid Option\n");
                    break;
                }
            }
        // End of Linked List
        case 4:
            // Start of STACK
            while (1)
            {
                printf("-------------------------------------------------------\n\t\t\tSTACK\n-------------------------------------------------------\n");
                printf("0. Exit\n1. Stack (Push,Pop,Display) using Array\n2. Stack (Push,Pop,Display) using Linked List\n3. Infix To Postfix\n4. Infex to Prefix\n5. A matching pair of brackets Program\n6. Reverse of STACK\n7. Sorting of STACK\n8. STACK peek(Begining,middle,end)\n");
                printf("-------------------------------------------------------\n\n");
                printf("Enter your choice: ");
                scanf("%d", &ch1);
                printf("\n");
                switch (ch1)
                {
                case 0:
                    goto p;
                    break;
                case 1:
                    STACK1();
                    break;
                case 2:
                    STACK2();
                    break;
                case 3:
                    ITF();
                    break;
                case 4:
                    InfixToPrefix();
                    break;
                case 5:
                    MatchingBrackets();
                    break;
                case 6:
                    STACKReverse();
                    break;
                case 7:
                    StackSorting67();
                    break;
                case 8:
                    peekinSTACK();
                    break;
                default:
                    printf("Invalid Option\n");
                    break;
                }
            }
        // End of STACK
        case 5:
            // Start of Queue
            while (1)
            {
                printf("-------------------------------------------------------\n\t\t\tQueue\n-------------------------------------------------------\n");
                printf("0. Exit\n1. Queue(Enqueue, Dequeue, Peek, Display of elements, IsEmpty, IsFull) using Array\n2. Queue(Enqueue, Dequeue, Peek, Display of elements, IsEmpty, IsFull) using linked list\n3. Reverse Queue\n4. Circular Queue using Array\n5. Circular Queue using Linked list\n");
                printf("-------------------------------------------------------\n\n");
                printf("Enter your choice: ");
                scanf("%d", &ch1);
                printf("\n");
                switch (ch1)
                {
                case 0:
                    goto p;
                    break;
                case 1:
                    Dqueue();
                    break;
                case 2:
                    Dqueue();
                    break;
                case 3:
                    ReverseQueue();
                    break;
                case 4:
                    CircularQueue();
                    break;
                case 5:
                    CircularQueue();
                    break;
                default:
                    printf("Invalid Option\n");
                    break;
                }
            }
        // End of Queue
        case 6:
            // Start of Searching & Sorting
            while (1)
            {
                printf("-------------------------------------------------------\n\t\tSearching & Sorting\n-------------------------------------------------------\n");
                printf("0. Exit\n1. read an array of integers and search for an element using linear search\n2. read an array of integers and search for an element using binary search\n3.  Given an array container and integer hunt.WAP to find whether hunt is present in container or not\n4. find the number in array that appears more than or equal to n / 2 times\n5. recursion to search an element in a dynamic array of n integers using linear search\n6. recursion to search an element in a dynamic array of n integers using binary search\n");
                printf("-------------------------------------------------------\n\n");
                printf("Enter your choice: ");
                scanf("%d", &ch1);
                printf("\n");
                switch (ch1)
                {
                case 0:
                    goto p;
                    break;
                case 1:
                    LinearSearchArray();
                    break;
                case 2:
                    BinarySearchArray();
                    break;
                case 3:
                    hunt();
                    break;
                case 4:
                    nBy2Times();
                    break;
                case 5:
                    rec();
                    break;
                case 6:
                    recb();
                    break;
                default:
                    printf("Invalid Option\n");
                    break;
                }
            }
        // End of Searching & Sorting
        case 7:
            // Start of Searching & Sorting
            while (1)
            {
                printf("-------------------------------------------------------\n  Polynomial / Sparse Matrix Representation, Addition & Multipilcation\n-------------------------------------------------------\n");
                printf("0. Exit\n1. create a linked list that represents a polynomial expression with single variable (i.e.5x7-3x5+x2+9) and display the polynomial\n2. add two polynomials with single variable\n3.  Sparse Matrix\n4. Transpose of sparse matrix\n5. determine whether the given matrix is a sparse matrix or not\n6.  determine whether the given matrix is a lower triangular or upper triangular or tri-diagonal matrix\n7. add two sparse matrixes\n8. multiply two sparse matrixes\n");
                printf("-------------------------------------------------------\n\n");
                printf("Enter your choice: ");
                scanf("%d", &ch1);
                printf("\n");
                switch (ch1)
                {
                case 0:
                    goto p;
                    break;
                case 1:
                    Polynomial();
                    break;
                case 2:
                    Addition();
                    break;
                case 3:
                    q3();
                    break;
                case 4:
                    q4();
                    break;
                case 5:
                    q5();
                    break;
                case 6:
                    q6();
                    break;
                case 7:
                    q7();
                    break;
                case 8:
                    q8();
                    break;
                default:
                    printf("Invalid Option\n");
                    break;
                }
            }
        // End of Searching & Sorting
        default:
            printf("Invalid Option\n");
            break;
        }
    }

    return 0;
}