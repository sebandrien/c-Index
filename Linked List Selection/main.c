#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
	int data;
	struct node_s * nextptr;
}node_t;

node_t * push(node_t * top, int val); //function prototypes
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
	
  while(choice != 6) 	//menu driven component
  {
    printf("Selection Table: \n");
	printf("1: Push onto stack\n");
	printf("2: Pop from stack\n");
	printf("3: Retreive the top from stack\n");
	printf("4: Check to see if stack is empty\n");
	printf("5: Display stack visual\n");
	printf("6: Terminate program\n");
	printf("\n");
		
	printf("Please enter what you would like to do: ");
	scanf("%d", &choice);
		
	switch(choice)
	{
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
				printf("Terminating program...\n");
				printf("\n");
				break;
			
			default:
				printf("Please enter an integer.\n");
		}
		printf("\n");
	}
	
 deleteAllNodes(top);
}

node_t * push(node_t * top, int val)
{
    
  if(isEmpty(top))
  {
     printf("Creating a new top of stack...\n");
   
     top = createNode(val);
   
    return top;
   }
  
  node_t * temp = createNode(val);

  temp->nextptr = top; 	//put new node on top
	
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

int getTop(node_t *top)
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return -1; // Returns -1 or any sentinel value indicating that the stack is empty
    }
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
			printf("%1d|\n", top->data);
			top = top->nextptr;
		}
		printf("-----\n");
	}
	else
		printf("Stack is empty!\n");
}

node_t * createNode(int data)
{
  node_t * node = (node_t *) malloc(sizeof(node_t));
	
  if(node == NULL)
  {
	printf("malloc wasn't successful");
	
   return NULL;
  }

	node->data = data; 	 //populate
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
