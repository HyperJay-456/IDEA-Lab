#include <stdio.h>
#include <stdlib.h>
#define N 5

int stack[N];
int top = -1;

void push() {
    int x;
    printf ("Enter Data: \n");
    scanf ("%d",&x);
    if (top == N - 1) {
        printf ("Overflow. \n");
    } else {
        top++;
        stack[top] = x; 
    }
}

void pop() {
    if (top == -1) {
        printf ("Underflow. \n");
    } else {
        int item = stack[top];
        printf ("The poped element was %d", item);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf ("The stack is empty. \n");
    } else {
        printf ("The element at the top is %d", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf ("The stack is empty. \n");
    } else {
        for (int i=top; i>0; i--) {
            printf ("%d ", stack[i]);
        }
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            
            case 1:
            push();
            break;

            case 2:
            pop();
            break;

            case 3:
            peek();
            break;

            case 4:
            display();
            break;

            case 5:
            printf ("Exiting....");
            exit(0);
            
            default: 
            printf ("Invalid Choice. \n");
        }
    }
    return 0;
}