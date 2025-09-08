#include <stdio.h>
#include <stdlib.h> // required for malloc() and exit()

// defines the structure for the stack
struct Stack {
        int top;            // index of the top element
        int capacity        // maximum capacity of the stack
        float *elements     // pointer to the array of elements
};

// initializes a stack with a given capacity
void createStack(struct Stack *s, int c) {
        s->top = -1; // the stack starts empty
        s->capacity = c;
        s->elements = (float*) malloc(c *sizeof(float));
        // it's good practice to check if malloc was succesful
        if (s->elements == NULL) {
            printf("\nError allocating memory!\n");
            exit(1);
        }
}

// returns 1 (true) if the stack is empty, 0 (false) otherwise
int isEmpty(struct Stack *s) {
        return (s->top == -1);
}

// returns 1 (true) if the stack is full, 0 (false) otherwise
int isFull(struct Stack *s) {
        return (s->top == s->capacity - 1);
}

// adds an element (value v) to the top of the stack
void push(struct Stack *s, float v) {
        s->top++;
        s->elements[s->top] = v;
}

// removes and returns the element from the top of the stack
float pop(struct Stack *s) {
        float aux = s->elements[s->top];
        s->top--;
        return aux;
}

// returns the element at the top of the stack without removing it
float peek(struct Stack *s) {
        return s->elements[s->top];
}

int main() {
        struct Stack myStack;
        int capacity, option;
        float value;

        printf("Enter the stack capacity: ");
        scanf("%", &capacity);

        createStack(&myStack, capacity);

        while(1) {  // infinite loop for the menu
                printf("\n--- MENU ---\n");
                printf("1- Push\n");
                printf("2- Pop\n");
                printf("3- Peeek\n");
                printf("4- Exit\n");
                printf("\nEnter your option: ");
                scanf("%d", &option);  // corrected the format specifier

                switch (option) {
                  case 1: // push
                          if (isFull(&myStack)) {
                                  printf("\nSTACK IS FULL!\n");
                          } else {
                                  printf("\nEnter the value to push: ");
                                  scanf("%f", &value);
                                  push(&myStack, value);
                                  printf("\nValue %.1f popped from the stack!\n", value);
                          }
                          break;

                  case 2: // pop
                          if (isEmpty(&myStack)) {
                                  printf("\nSTACK IS EMPTY!\n");
                          } else {
                                  value = pop (&myStack);
                                  printf("\nValue %.1f popped from the stack!\n", value);
                          }
                          break;
                  
                  case 3: // peek
                          if (isEmpty(&myStack)) {
                                  printf("\nSTACK IS EMPTY!\n");
                          } else {
                                  value = peek(&myStack);
                                  printf("\nTOP OF STACK: %.1f\n", value);
                          }
                          break;

                  case 4: // exit
                      // it's good practice to free allocated memory before exiting
                      free(myStack.elements);
                          printf("\nExiting...\n");
                          exit(0);

                  default:
                          printf("\nINVALID OPTION!\n");
                }
        }

        return 0; // although unreachable due to while(1) and exit(0)
}
