#include "graph.h"
#include <iostream>

using namespace std;

bool visited[1000];

void DFS(struct Graph G,int s)
{
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

int main()
{
	Graph g;
	
	g.n = 7;
	
	g.insertEdge(0,1, 2);
	g.insertEdge(2,1, 21);
	g.insertEdge(1,3, 20);
	g.insertEdge(4,2, 88);
	g.insertEdge(5,6, 10);
	g.insertEdge(0,6, 1);
	
	cout << endl;
	
	cout << "Linking of nodes is as follows " << endl;
	g.print();
	cout << "\n";

	DFS(g,4);
	cout << endl;
		
	return 0;
}