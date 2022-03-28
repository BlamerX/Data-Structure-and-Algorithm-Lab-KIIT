// Write a menu driven program to implement circular queue operations such as Enqueue, Dequeue, Peek, Display of elements, IsEmpty, IsFull using static array.

#define MAX 5

int cqueue_arr[MAX];
int front75 = -1;
int rear75 = -1;
void Enqueue75(int item)
{
    if ((front75 == 0 && rear75 == MAX - 1) || (front75 == rear75 + 1))
    {
        printf("Queue Overflow \n");
        return;
    }
    if (front75 == -1) /*If queue is empty */
    {
        front75 = 0;
        rear75 = 0;
    }
    else
    {
        if (rear75 == MAX - 1) /*rear75 is at last position of queue */
            rear75 = 0;
        else
            rear75 = rear75 + 1;
    }
    cqueue_arr[rear75] = item;
}

void dequeue75()
{
    if (front75 == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is : %d\n", cqueue_arr[front75]);
    if (front75 == rear75) /* queue has only one element */
    {
        front75 = -1;
        rear75 = -1;
    }
    else
    {
        if (front75 == MAX - 1)
            front75 = 0;
        else
            front75 = front75 + 1;
    }
}

void display75()
{
    int front75_pos = front75, rear75_pos = rear75;
    if (front75 == -1)
        return;
    printf("Queue elements :\n");
    if (front75_pos <= rear75_pos)
        while (front75_pos <= rear75_pos)
        {
            printf("%d ", cqueue_arr[front75_pos]);
            front75_pos++;
        }
    else
    {
        while (front75_pos <= MAX - 1)
        {
            printf("%d ", cqueue_arr[front75_pos]);
            front75_pos++;
        }
        front75_pos = 0;
        while (front75_pos <= rear75_pos)
        {
            printf("%d ", cqueue_arr[front75_pos]);
            front75_pos++;
        }
    }
    printf("\n");
}

int CircularQueue()
{
    int choice, item;
    do
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Input the element: ");
            scanf("%d", &item);
            Enqueue75(item);
            break;
        case 2:
            dequeue75();
            break;
        case 3:
            display75();
            break;
        case 4:
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (choice != 4);

    return 0;
}