// Write a menu driven program to implement queue operations such as Insert, Delete, Display, whether queue is empty etc by using array.

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct
{
    int data[MAX];
    int front;
    int rear;
} Queue;

void init(Queue *q)
{
    q->front = q->rear = -1;
}

void insert(Queue *q, int val)
{
    if (q->rear == MAX - 1)
        return;
    else if (q->rear == -1)
        q->front = q->rear = 0;
    else
        q->rear++;
    q->data[q->rear] = val;
}

void delete (Queue *q, int *val)
{
    if (q->front == -1)
        return;
    else if (q->front == q->rear)
    {
        *val = q->data[q->front];
        q->front = q->rear = -1;
    }
    else
    {
        *val = q->data[q->front];
        q->front++;
    }
    printf("The value deleted is: %d\n", *val);
}

void display(Queue *q)
{
    if (q->front == -1)
        printf("Queue is Empty");
    else
    {
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->data[q->front]);
        }
    }
    printf("\n");
}

int main()
{
    Queue q1;
    init(&q1);

    int opt, val;
    while (1)
    {
        printf("\n1 Insert");
        printf("\n2 Delete");
        printf("\n3 Display");
        printf("\n4 Check if Queue is Empty");
        printf("\n5 Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &val);
            insert(&q1, val);
            break;
        case 2:
            delete (&q1, &val);
            break;
        case 3:
            display(&q1);
            break;
        case 4:
            display(&q1);
            break;
        case 5:
            exit(0);
            break;
        }
    }

    return 0;
}