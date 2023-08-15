#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int data;
    struct node_s *nextptr;
} node_t;

node_t * push(node_t * top, int val);
node_t * pop(node_t * top);
int getTop(node_t * top);
int isEmpty(node_t * top);
void displayStack(node_t * top);
node_t * createNode(int data);
void removeNode(node_t * node);
void deleteAllNodes(node_t * top);

int main() {
    node_t * top = NULL;

    int choice = 0;
    int val;
    
    while(choice != 6) {
        printf("Selection Table: \n");
        printf("1: Push onto stack\n");
        printf("2: Pop from stack\n");
        printf("3: Retrieve the top from stack\n");
        printf("4: Check to see if stack is empty\n");
        printf("5: Display stack visual\n");
        printf("6: Terminate program\n");
        printf("\nPlease enter what you would like to do: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Push was selected...\n");
                printf("What would you like to push onto the stack: ");
                scanf("%d", &val);
                top = push(top, val);
                break;
                
            case 2:
                printf("Pop selected...\n");
                top = pop(top);
                break;
            
            case 3:
                printf("Top selected...\n");
                printf("top of stack is %d\n", getTop(top));
                break;
            
            case 4:
                printf("Checking stack...\n");
                if(isEmpty(top))
                    printf("Stack is empty!\n");
                else
                    printf("Stack is not empty!\n");
                break;
            
            case 5:
                displayStack(top);
                break;
            
            case 6:
                printf("Terminating program...\n\n");
                break;
            
            default:
                printf("Please enter a valid choice.\n");
        }
        printf("\n");
    }
    
    deleteAllNodes(top);
}

node_t * push(node_t * top, int val) {
    if(isEmpty(top)) {
        printf("Creating a new top of stack...\n");
        top = createNode(val);
        return top;
    }
  
    node_t * temp = createNode(val);
    temp->nextptr = top; // put new node on top
    
    return temp;
}

node_t * pop(node_t * top) {
    if(isEmpty(top)) {
        printf("Nothing to pop from stack...\n");
        
        return NULL;
    }
  
    node_t * temp = top;
    printf("Removing %d from stack.\n", temp->data);
    top = top->nextptr;
    removeNode(temp);
    
    return top;
}

int getTop(node_t *top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    
    return top->data;
}

int isEmpty(node_t * top) {
    return (top == NULL);
}

void displayStack(node_t * top) {
    if(!isEmpty(top)) {
        printf("-----\n");
        while(top != NULL) {
            printf("|%1d|\n", top->data);
            top = top->nextptr;
        }
        printf("-----\n");
    } else {
        printf("Stack is empty!\n");
    }
}

node_t * createNode(int data) {
    node_t * node = (node_t *) malloc(sizeof(node_t));
    if(node == NULL) {
        printf("malloc wasn't successful");
        return NULL;
    }
    node->data = data;
    node->nextptr = NULL;
    return node;
}

void removeNode(node_t * node) {
    free(node);
}

void deleteAllNodes(node_t * top) {
    while(!isEmpty(top)) {
        node_t * temp = top;
        top = top->nextptr;
        removeNode(temp);
    }
}
