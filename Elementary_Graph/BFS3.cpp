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
    int x = front->data;
	front = front->next;
	head = head->next;
	rear->next = NULL;
	return x;
}

int empty()
{
    if(front == rear)
        return 1;
    return 0;
}

bool BFS(Graph G, int s, int t)
{
    bool visit[G.n];
    for(int i = 0; i < G.n; i++)
        visit[i] = false;
    visit[s] = true;
    enqueue(s);
    while(!empty())
    {
        int x = dequeue();
        struct node* temp = G.N[x];
        int i;
        while(temp)
        {
            i = temp->data;
            if(!visit[i])
            {
                if(t == i)
                     return 1;
                visit[i] = true;
                enqueue(i);
                temp = temp->next;
            }
        }
    }
    return 0;
}
