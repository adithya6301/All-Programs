#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int key;
} element;

/* Global stack and top */
element stack[MAX_STACK_SIZE];
int top = -1;

/* Function prototypes */
int isFull();
int isEmpty();
void push(element item);
element pop();
void display();

int main() {
    int choice;
    element item;

    while (1) {
        printf("\n------ STACK MENU ------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Stack is FULL! Cannot push.\n");
                } else {
                    printf("Enter element to push: ");
                    scanf("%d", &item.key);
                    push(item);
                }
                break;

            case 2:
                if (isEmpty()) {
                    printf("Stack is EMPTY! Cannot pop.\n");
                } else {
                    item = pop();
                    printf("Popped element = %d\n", item.key);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

/* Check if stack is full */
int isFull() {
    return top >= MAX_STACK_SIZE - 1;
}

/* Check if stack is empty */
int isEmpty() {
    return top < 0;
}

/* Push operation */
void push(element item) {
    stack[++top] = item;
}

/* Pop operation */
element pop() {
    return stack[top--];
}

/* Display elements of stack */
void display() {
    if (isEmpty()) {
        printf("Stack is EMPTY!\n");
        return;
    }

    printf("Stack elements (top to bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i].key);
    }
}
