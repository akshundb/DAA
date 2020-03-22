#include "graph.h"
#include <list>
#include <iostream>

using namespace std;

bool visited[1000];
list<int> D;

list<int> DFS(struct Graph G, int s=0)
{
	struct node *temp = G.N[s];

	visited[s] = true;
	D.push_back(s);

	//cout << "Visited " << s << "\n";

	while(temp!=NULL)
	{
		int connectedvertex = temp->data;
		if(visited[connectedvertex] == 0)
		{
			DFS(G, connectedvertex);
		}
	temp = temp->next;
	}
	return D;
}
