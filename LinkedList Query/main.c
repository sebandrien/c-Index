#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s *nextptr;
} node_t;

node_t *push(node_t *top, int val);
node_t *pop(node_t *top);
int getTop(node_t *top);
int isEmpty(node_t *top);
void displayStack(node_t *top);
node_t *createNode(int data);
void removeNode(node_t *top);
void deleteAllNodes(node_t *top);

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getIntInput(const char *prompt) {
    int input;
    int status;
    do {
        printf("%s", prompt);
        status = scanf("%d", &input);
        if (status != 1) {
            printf("Invalid input. Please enter a valid integer.\n");
            clearInputBuffer();
        }
    } while (status != 1);
    clearInputBuffer();
    return input;
}

int main() {
    node_t *top = NULL;
    int choice = 0;
    int val;

    while (choice != 6) {
        printf("****************************\n");
        printf("1: Push onto the Stack\n");
        printf("2: Pop from the Stack\n");
        printf("3: Retrieve Top from the Stack\n");
        printf("4: Check to see if stack is empty\n");
        printf("5: Display stack visual\n");
        printf("6: Terminate Program\n");
        choice = getIntInput("Enter what you would like to do: ");

        switch (choice) {
            case 1:
                printf("Push was selected...\n");
                val = getIntInput("What would you like to push onto the stack: ");
                top = push(top, val);
                break;

            case 2:
                printf("Pop was selected...\n");
                top = pop(top);
                break;

            case 3:
                printf("Top was selected...\n");
                if (!isEmpty(top))
                    printf("Top of stack is %d\n", getTop(top));
                else
                    printf("Stack is empty.\n");
                break;

            case 4:
                printf("isEmpty selected...\n");
                if (isEmpty(top))
                    printf("Stack is EMPTY!\n");
                else
                    printf("Stack is NOT empty!\n");
                break;

            case 5:
                displayStack(top);
                break;

            case 6:
                printf("Terminating Program...\n");
                break;

            default:
                printf("Not a valid choice.\n");
        }

        printf("****************************\n");
    }

    deleteAllNodes(top);

    return 0;
}

node_t *push(node_t *top, int val) {

    node_t *temp = createNode(val);

    if (temp == NULL) {
        printf("Failed to push value onto the stack.\n");
        return top;
    }

    temp->nextptr = top;
  
    return temp;
}

node_t *pop(node_t *top) {
    if (isEmpty(top)) {
        printf("Nothing to pop from stack...\n");
        return NULL;
    } else {
        node_t *temp = top;
        printf("Removing %d from stack.\n", temp->data);
        top = top->nextptr;
        removeNode(temp);
        return top;
    }
}

int getTop(node_t *top) {
    return top->data;
}

int isEmpty(node_t *top) {
    return (top == NULL);
}

void displayStack(node_t *top) {
    if (!isEmpty(top)) {
        printf("-----\n");
        while (top != NULL) {
            printf("|%3d|\n", top->data);
            top = top->nextptr;
        }
        printf("-----\n");
    } else {
        printf("Stack is Empty\n");
    }
}

node_t *createNode(int data) {
    node_t *node = (node_t *)malloc(sizeof(node_t));

    if (node == NULL) {
        printf("malloc wasn't successful");
        return NULL;
    }

    node->data = data;
    node->nextptr = NULL;
  
    return node;
}

void removeNode(node_t *top) {
    free(top);
}

void deleteAllNodes(node_t *top) {
    while (!isEmpty(top)) {
        node_t *temp = top;
        top = top->nextptr;
        removeNode(temp);
    }
}
