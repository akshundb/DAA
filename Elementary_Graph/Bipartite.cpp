#include"graph.h"
#include<queue>

bool bipartite(Graph G, int s){
    int color[G.n];
    for (int i = 0; i < G.n; ++i)
        color[i] = -1;
    
    color[s] = 1;
    queue <int> q;
    q.push(s);
    
    while (!q.empty()){
        int u = q.front();
        q.pop();
		struct node* temp = G.N[u];
		while(temp!=NULL){
			int v = temp->data;
			if(color[v] == -1){
				color[v] = 1 - color[u];
                q.push(v);
			}
			else if(color[v] == color[u])
				return false;
			temp = temp->next;
		}
	}
	return true;
}
