#include"graph.h"

bool isBipartite(Graph G, int s){
    int colorArr[G.n];
    for (int i = 0; i < G.n; ++i)
        colorArr[i] = -1;
    
    colorArr[s] = 1;
    queue <int> q;
    q.push(s);
    
    while (!q.empty()){
        int u = q.front();
        q.pop();
		struct node* temp = G.N[u];
		while(temp!=NULL){
			int v = temp->data;
			if(colorArr[v] == -1){
				colorArr[v] = 1 - colorArr[u];
                q.push(v);
			}
			else if(colorArr[v] == colorArr[u])
				return false;
			temp = temp->next;
		}
	}
	return true;
}
