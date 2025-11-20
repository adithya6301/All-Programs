//QUEUES
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 10

int que[SIZE];

int front =-1, rear = -1;

int isFull(){
    return (rear==SIZE-1);
}

int isEmpty()
{
    return (rear == -1 || front>rear);
}

void enqueue(int data)
{
    if(isFull())
    {
        printf("\nQueue is Full.");
        return;
    }
    if(front==-1)
        front = 0;
    que[++rear] = data;
    printf("\n%d has successfully enqueued.",data);
    return;
}

void dequeue()
{
    if(isEmpty())
    {
        printf("\nQueue is empty.");
        return;
    }
    printf("\n%d has been successfully removed.",que[front++]);
}

void display()
{
    if(isEmpty())
    {
        printf("\nQueue is empty.");
        return;
    }
    printf("\nQueue Elements: ");
    for(int i=front;i<=rear;i++)
    {
        printf("\n%d",que[i]);
    }
    printf("\n");
}

void peek()
{
    if(isEmpty())
    {
        printf("\nQueue is empty.");
        return;
    }
    printf("\n%d",que[front]);
    return;
}

int main()
{
    int ch,data;
    while(1)
    {
        printf("\nMENU\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter data: ");
            scanf("%d",&data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("\nInvalid choice");
        }
    }
}
