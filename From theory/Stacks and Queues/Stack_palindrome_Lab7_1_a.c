#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    char items[MAX_SIZE];
    int top;
};

// Initialize stack
void initialize(struct Stack* s) {
    s->top = -1;
}

// Check if stack is full
bool isFull(struct Stack* s) {
    return s->top == MAX_SIZE - 1;
}

// Check if stack is empty
bool isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Push operation
void push(struct Stack* s, char value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
    } else {
        s->items[++s->top] = value;
    }
}

// Pop operation
char pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return s->items[s->top--];
    }
}

int main() {
    char inputString[MAX_SIZE];
    printf("Enter a string to check if it's a palindrome: ");
    scanf("%s", inputString);

    struct Stack charStack;
    initialize(&charStack);

    // 1. Push all characters of the string onto the stack
    for (int i = 0; i < strlen(inputString); i++) {
        push(&charStack, inputString[i]);
    }

    char reversedString[MAX_SIZE];
    int i = 0;

    // 2. Pop all characters from the stack to create the reversed string
    while (!isEmpty(&charStack)) {
        reversedString[i++] = pop(&charStack);
    }
    reversedString[i] = '\0'; // Null-terminate the reversed string

    // 3. Compare the original with the reversed string
    if (strcmp(inputString, reversedString) == 0) {
        printf("'%s' is a palindrome.\n", inputString);
    } else {
        printf("'%s' is not a palindrome.\n", inputString);
    }

    return 0;
}
