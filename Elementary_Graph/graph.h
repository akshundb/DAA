#include<iostream>
#include<vector>
#include<list>
using namespace std;

struct node
{
	int data;
	int weight;
	int degree;

	struct node *next;
};

struct node* myinsert(int data, struct node *head, int w);
void printList(struct node *head);

class Graph
{
	public :

	int n;
	struct node *N[100];

	//Graph()
	//{
		//for(int i=0; i<n; i++)
		//{
			//N[i] = NULL;
		//}
	//}

	void insertEdge(int n1, int n2, int w)
	{
		N[n1] = myinsert(n2, N[n1], w);
	}

	void print()
	{
		for(int i=0; i<n; i++)
		{
			cout<<i<<" ";
			printList(N[i]);
			cout<<endl;
		}
	}

};

void DFS(Graph G, int s, int t);
list<int> DFS(Graph G, int s);
list<int> DFS(Graph G);

void BFS(Graph G, int s, int t);
void BFS(Graph G, int s);
bool BFS(Graph G);

vector<int> BFS_SPATH(Graph G, int s, bool flag);

void LPATH(Graph G, int flag);

void MAX_Weight_MST(Graph G);

void TEST_bipartite(Graph G);
void Test_articulationpoints(Graph G);
void Test_bridges(Graph G);

Graph MST_Prim(Graph G);
Graph MST_Kruskal(Graph G);
void MST_youralgo(Graph G);

void clearGlobalList();
void clearGlobalVisit(int n);
