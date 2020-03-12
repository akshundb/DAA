#include "graph.h"
#include <iostream>

using namespace std;

bool visited[1000];

void DFS(struct Graph G,int s)
{
	s=0;
	struct node *temp = G.N[s];

	visited[s] = true;

	cout << "Visited " << s << "\n";

	while(temp!=NULL)
	{
		int connectedvertex = temp->data;
		
		if(visited[connectedvertex] == 0)
		{
			DFS(G,connectedvertex);
		}
	temp = temp->next;
	}
}
