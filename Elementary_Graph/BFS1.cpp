#include "graph.h"

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
		temp->next = head;
	}
}

void dequeue()
{
	front = front->next;
	head = head->next;
	rear->next = head;
}

int empty(){
    if(front == rear)
        return 1;
    return 0;
}


void BFS(Graph G)
{
    bool visit[n];
    for(int i = 0; i < n; i++)
        visit[i] = false;
    visit[0] = true;
    enqueue(0);
    while(!empty()){
        int x = dequeue();
        cout<<x<<" ";
        struct node* temp = N[x];
        int i;
        while(temp){
            i = temp->data;
            if(!visit[i]){
                visit[i] = true;
                push(i);
                temp = temp->next;
            }
        }
    }
}

