// 3.	Write a menu driven program to implement queue operations such as Enqueue, Dequeue, Peek, Display of elements, IsEmpty using linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * front, *back;

void initialize()
{
    front = back = NULL;
}

int getQueueSize()
{
    struct node *temp = front;
    int count = 0;

    if (front == NULL && back == NULL)
        return 0;

    while (temp != back)
    {
        count++;
        temp = temp->next;
    }
    if (temp == back)
        count++;

    return count;
}

int getFrontElement()
{
    return front->data;
}

int getBackElement()
{
    return back->data;
}

void isEmpty()
{
    if (front == NULL && back == NULL)
        printf("Empty Queue\n");
    else
        printf("Queue is not Empty\n");
}

void enqueue(int num)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;

    if (back == NULL)
    {
        front = back = temp;
    }
    else
    {
        back->next = temp;
        back = temp;
    }
}

void dequeue()
{
    struct node *temp;
    if (front == NULL)
    {
        printf("\nQueue is Empty \n");
        return;
    }
    else
    {
        temp = front;
        front = front->next;
        if (front == NULL)
        {
            back = NULL;
        }
        printf("Removed Element : %d\n", temp->data);
        free(temp);
    }
}

void printQueue()
{
    struct node *temp = front;

    if ((front == NULL) && (back == NULL))
    {
        printf("Queue is Empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != NULL)
            printf("-->");
    }
}

int main()
{
    initialize();

    enqueue(2);
    enqueue(0);
    enqueue(2);
    enqueue(9);
    enqueue(1);
    enqueue(9);
    enqueue(6);

    printQueue();

    printf("\nSize of Queue : %d\n", getQueueSize());

    printf("Front Element : %d\n", getFrontElement());
    printf("Rear Element : %d\n", getBackElement());

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    return 0;
}