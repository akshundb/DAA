#include "graph.h"

struct node* head = front = rear = NULL;

void enqueue(int x){
	struct node* temp = (struct node*) malloc (sizeof(struct node));
	temp->data = x;
	if(head == NULL){
		front = temp;
		rear = temp;
		temp->next = temp;
		head = temp;
	}
	else{
		rear->next = temp;
		rear = temp;
		temp->next = head;
	}
}

void dequeue(){
	front = front->next;
	head = head->next;
	rear->next = head;
}

int empty(){
    if(front == rear)
        return 1;
    return 0;
}
