#include<stdio.h>
#include <stdlib.h>

typedef struct node_s{ 
  int data;
  struct node_s * nextptr;
}node_t;

node_t * createNode();
int empty(node_t * front);
node_t * enqueue(node_t * front);
void display(node_t * front);
void front(node_t * front);
node_t * dequeue(node_t * front);

int main()
{
	node_t * front = NULL;
	
	if(empty(front))
		printf("No one is in line.\n");
  
	front = enqueue(front);
	front = enqueue(front);
	front = enqueue(front);
	front = enqueue(front);
	front = enqueue(front);
	
	display(front);
	
	front = dequeue(front);
	
	display(front);
	
	front = dequeue(front);
	front = dequeue(front);
	
	display(front);
	
	front = dequeue(front);
	front = dequeue(front);
	display(front);
	front = dequeue(front);
	front = dequeue(front);
	
	return 0;
}

node_t * createNode()
{
	node_t * node = (node_t *) malloc(sizeof(node_t));
	
	if(node == NULL)
	{
		printf("malloc not successful\n");
		return NULL;
	}
	
	printf("Enter a number: ");
	scanf("%d", &node->data);
	
	node->nextptr = NULL;
	
	return node;
}

int empty(node_t * front)
{
	return (front == NULL);
}

node_t * enqueue(node_t * front)
{
	if(empty(front))
	{
		printf("A new node will become the front...\n");
		front = createNode();
		front->nextptr = front;
		return front;
	}
	
	node_t * temp = front;
	
	while(temp->nextptr != front)
		temp = temp->nextptr;
	
	temp->nextptr = createNode();
	temp->nextptr->nextptr = front;
	
	return front;
}

node_t * dequeue(node_t * front)
{
	if(empty(front))
	{
		printf("Queue is empty and there is nothing to remove...\n");
		return NULL;
	}
	else if(front->nextptr == front)
	{
		free(front);
		return NULL;
	}
	else
	{
		node_t * temp = front;
		
		front = front->nextptr;
		
		node_t * temp2 = front;
		
		while(temp2->nextptr != temp)
			temp2 = temp2->nextptr;
		
		temp2->nextptr = front;
		
		free(temp);
		
		return front;
	}
}

void display(node_t * front)
{
	if(!(empty(front)))
	{
		node_t * first = front;
		
		while(front->nextptr != first)
		{
			printf("%d\t", front->data);
			front = front->nextptr;
		}
		
		printf("%d\n", front->data);
	}
	else
	{
		printf("Nothing to display... Queue is empty\n");
	}
}

void front(node_t * front)
{
	printf("%d is in the front of line.\n", front->data);
}
