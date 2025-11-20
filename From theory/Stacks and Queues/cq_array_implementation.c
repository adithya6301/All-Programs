#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int cq[SIZE];
int front =-1,rear=-1;

int isFull()
{
    return ((front==0&&rear==SIZE-1)||(front==rear+1));
}

int isEmpty()
{
    return (front==-1);
}
void enqueue(int data)
{
    if(isFull())
    {
        printf("\nQueue is full");
        return;
    }
    if(front==-1)
        front=0;
    rear=(rear+1)%SIZE;
    cq[rear]=data;
    printf("\n%d enqueued",data);
    return;
}

void dequeue()
{
    if(isEmpty())
    {
        printf("\nQueue is empty");
        return;
    }
    int data = cq[front];
    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%SIZE;
    }
    printf("\n%d dequeued",data);
    return;
}

void display() {
    if (isEmpty()) {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nQueue elements: ");
    int i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\nFront = %d, Rear = %d\n", front, rear);
}

void peek() {
    if (isEmpty()) {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nFront element is: %d\n", cq[front]);
}

int main()
{
    return;
}
