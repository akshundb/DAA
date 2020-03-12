#include "graph.h"

struct node* front;
struct node* rear;
struct node* head = front = rear = NULL;

void enqueue(int x)
{
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
		temp->next = NULL;
	}
}

int dequeue()
{
    int x=front->data;
	front = front->next;
	head = head->next;
	rear->next = NULL;
    return x;
}

int empty(){
    if(front == rear)
        return 1;
    return 0;
}


void BFS(Graph G)
{
    bool visit[G.n];
    for(int i = 0; i < G.n; i++)
        visit[i] = false;
    visit[0] = true;
    enqueue(0);
    while(!empty()){
        int x = dequeue();
        cout<<x<<" ";
        struct node* temp = G.N[x];
        int i;
        while(temp){
            i = temp->data;
            if(!visit[i]){
                visit[i] = true;
                enqueue(i);
                temp = temp->next;
            }
        }
    }
}

