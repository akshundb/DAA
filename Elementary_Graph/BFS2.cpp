#include"graph.h"
#include<cstdlib>

void BFS(Graph G, int s)
{
  	bool visit[G.n];
  	queue Q;

  	for(int i = 0; i<G.n; i++)
  	{
        visit[i] = false;
  	}

  	visit[s] = true;

  	Q.enqueue(s);

  	struct node* temp;
  	int x;
  	int u;

  	while(Q.isEmpty() == 0)
  	{
    	x = Q.dequeue();

      	temp = G.N[x];

      	while(temp!=NULL)
      	{
        	u = temp->data;
          	if(visit[u] == 0)
          	{
            	visit[u] = 1;
              	cout<<u<<endl;

              	Q.enqueue(u);

              	temp = temp->next;
          	}
          	else
          	{
            	temp = temp->next;
          	}
      	}
    }
  	return d;
}
