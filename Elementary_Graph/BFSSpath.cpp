#include<cstdlib>
#include<vector>
#include"graph.h"
#include<queue>

using namespace std;

vector<int> BFS_SPATH(Graph G, int s, bool flag)
{
	bool visit[G.n];
	vector<int> d;
	queue<int> Q;
	int w;

	for(int i = 0; i<G.n; i++)
	{
        visit[i] = false;
        d.push_back(0);
  	}

  	visit[s] = true;

	Q.push(s);

	struct node* temp;

  	int x;
  	int u;

  	while(Q.empty() == 0)
  	{
    	x = Q.front();
    	Q.pop();
    	temp = G.N[x];

    	while(temp!=NULL)
      	{
        	u = temp->data;
          	w = temp->weight;
          	if(visit[u] == 0)
          	{
            	visit[u] = true;
            	d[u] = d[x]+1;

              	Q.push(u);
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
