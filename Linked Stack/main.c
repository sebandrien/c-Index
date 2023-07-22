#include<stdio.h>
#include<stdlib.h>

typedef struct node_s{
	
	int data;
	struct node_s * nextptr;
	
}node_t;

//function prototypes
node_t * push(node_t * top, int val);
node_t * pop(node_t * top);
int getTop(node_t * top);
int isEmpty(node_t * top);
void displayStack(node_t * top);
node_t * createNode(int data);
void removeNode(node_t * top);
void deleteAllNodes(node_t * top);

int main()
{
	node_t * top = NULL; //get top pointer setup
	
	int choice = 0;
	int val;
	
	//menu driven component
	while(choice != 6)
	{
		printf("****************************\n");
		printf("1: Push onto the Stack\n");
		printf("2: Pop from the Stack\n");
		printf("3: Retreive Top from the Stack\n");
		printf("4: Check to see if stack is full\n");
		printf("5: Display stack visual\n");
		printf("6: Terminate Program\n");
		printf("Enter what you would like to do: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("push was selected...\n");
				printf("What would you like to push onto the stack: ");
				scanf("%d", &val);
				top = push(top, val);
				break;
				
			case 2:
				printf("pop was selected...\n");
				top = pop(top);
				break;
			
			case 3:
				printf("top was selected...\n");
				printf("top of stack is %d\n", getTop(top));
				break;
			
			case 4:
				printf("isEmpty selected...\n");
				if(isEmpty(top))
					printf("Stack is EMPTY!\n");
				else
					printf("Stack is NOT Empty!\n");
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
}

node_t * push(node_t * top, int val)
{
	if(isEmpty(top))
	{
		printf("Creating new top of stack...\n");
		top = createNode(val);
		return top;
	}
	
	node_t * temp = createNode(val);
	
	//put new node on top
	temp->nextptr = top;
	
	return temp; //temp is new top
}

node_t * pop(node_t * top)
{
	if(isEmpty(top)) //check if empty
	{
		printf("Nothing to pop from stack...\n");
		return NULL;
	}
	else
	{
		node_t * temp = top;
		printf("Removing %d from stack.\n", temp->data);
		top = top->nextptr;
		removeNode(temp);
		return top;
	}	
}

int getTop(node_t * top)
{
	return top->data;
}

int isEmpty(node_t * top)
{
	return (top == NULL);
}

void displayStack(node_t * top)
{
	if(!(isEmpty(top)))
	{
		printf("-----\n");
		while(top != NULL)
		{
			printf("|");
			printf("%3d|\n", top->data);
			top = top->nextptr;
		}
		printf("-----\n");
	}
	else
		printf("Stack is Empty\n");
}

node_t * createNode(int data)
{
	node_t * node = (node_t *) malloc(sizeof(node_t));
	
	if(node == NULL)
	{
		printf("malloc wasn't successful");
		return NULL;
	}
	 //populate
	node->data = data;
	node->nextptr = NULL;
	
	return node;
}

void removeNode(node_t * top)
{
	free(top);
}

void deleteAllNodes(node_t * top)
{
	while(!isEmpty(top))
	{
		node_t * temp = top;
		top = top->nextptr;
		removeNode(temp);
	}
}
