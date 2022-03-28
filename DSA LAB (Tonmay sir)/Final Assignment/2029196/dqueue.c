// 2.	Write a menu driven program to implement queue operations such as Enqueue, Dequeue, Peek, Display of elements, IsEmpty, IsFull using static array.

#define MAX_SIZE 5

int deque_arr[MAX_SIZE];
int left72 = -1;
int right72 = -1;

void Insertright72()
{
    int added_item;
    if ((left72 == 0 && right72 == MAX_SIZE - 1) || (left72 == right72 + 1))
    {
        printf("Queue Overflow\n");
        return;
    }
    if (left72 == -1)
    {
        left72 = 0;
        right72 = 0;
    }
    else if (right72 == MAX_SIZE - 1)
        right72 = 0;
    else
        right72 = right72 + 1;
    printf("Input the element for adding in queue : ");
    scanf("%d", &added_item);
    deque_arr[right72] = added_item;
}

void Insertleft72()
{
    int added_item;
    if ((left72 == 0 && right72 == MAX_SIZE - 1) || (left72 == right72 + 1))
    {
        printf("Queue Overflow \n");
        return;
    }
    if (left72 == -1)
    {
        left72 = 0;
        right72 = 0;
    }
    else if (left72 == 0)
        left72 = MAX_SIZE - 1;
    else
        left72 = left72 - 1;
    printf("Input the element for adding in queue : ");
    scanf("%d", &added_item);
    deque_arr[left72] = added_item;
}

void Deleteleft72()
{
    if (left72 == -1)
    {
        printf("Queue Under-flow\n");
        return;
    }
    printf("Element has been deleted from queue is : %d\n", deque_arr[left72]);
    if (left72 == right72)
    {
        left72 = -1;
        right72 = -1;
    }
    else if (left72 == MAX_SIZE - 1)
        left72 = 0;
    else
        left72 = left72 + 1;
}

void Deleteright72()
{
    if (left72 == -1)
    {
        printf("Queue Under flow\n");
        return;
    }
    printf("Element has been deleted from queue is : %d\n", deque_arr[right72]);
    if (left72 == right72)
    {
        left72 = -1;
        right72 = -1;
    }
    else if (right72 == 0)
        right72 = MAX_SIZE - 1;
    else
        right72 = right72 - 1;
}

void Display72()
{
    int fpos = left72, rpos = right72;
    if (left72 == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if (fpos <= rpos)
    {
        while (fpos <= rpos)
        {
            printf("%d ", deque_arr[fpos]);
            fpos++;
        }
    }
    else
    {
        while (fpos <= MAX_SIZE - 1)
        {
            printf("%d ", deque_arr[fpos]);
            fpos++;
        }
        fpos = 0;
        while (fpos <= rpos)
        {
            printf("%d ", deque_arr[fpos]);
            fpos++;
        }
    }
    printf("\n");
}

void Input()
{
    int Option = 0;
    do // while(Option<0 || Option>5)
    {
        printf("1.Insert at right\n");
        printf("2.Delete from left\n");
        printf("3.Delete from right\n");
        printf("4.Display\n");
        printf("5.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &Option);
        switch (Option)
        {
        case 1:
            Insertright72();
            break;
        case 2:
            Deleteleft72();
            break;
        case 3:
            Deleteright72();
            break;
        case 4:
            Display72();
            break;
        case 5:
            break;
        default:
            printf("Wrong Option\n");
        }
    } while (Option != 5);
}

void Output()
{
    int Option = 0;
    do // while(Option<=0 || Option>5)
    {
        printf("1.Insert at right\n");
        printf("2.Insert at left\n");
        printf("3.Delete from left\n");
        printf("4.Display\n");
        printf("5.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &Option);
        switch (Option)
        {
        case 1:
            Insertright72();
            break;
        case 2:
            Insertleft72();
            break;
        case 3:
            Deleteleft72();
            break;
        case 4:
            Display72();
            break;
        case 5:
            break;
        default:
            printf("Wrong Option\n");
        }
    } while (Option != 5);
}

int Dqueue()
{
    int Option = 0;
    printf("1.Input restricted dequeue\n");
    printf("2.Output restricted dequeue\n");
    printf("Enter your choice : ");
    scanf("%d", &Option);
    while (1)
    {
        switch (Option)
        {
        case 1:
            Input();
            break;
        case 2:
            Output();
            break;
        default:
            printf("Wrong Option\n");
            break;
        }
    }

    return 0;
}