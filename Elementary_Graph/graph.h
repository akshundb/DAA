#include<iostream>
using namespace std;

struct node
{
	int data;
	int weight;

	struct node *next;
};

struct node* insert(int data,  struct node *head, int w)
{
	struct node *insert=(struct node*)malloc(sizeof(struct node));
	insert->next = NULL;
	insert->data = data;
	insert->weight = w;
	 if(head!=NULL)
	 {
	 	insert->next = head->next;
	 	head->next = insert;
	 }
	 else
	 {
	 	insert->next = NULL;
	 	return insert;
	 }

	 return head;

}

void printList(struct node *head)
{
	struct node *temp = head;

	while(temp!=NULL)
	{
		cout << temp->data << "  ";
		temp = temp->next;
	}
}

class queue
{

  struct node *front;
  struct node *rear;

  public:

  queue()
  {
    front = rear = NULL;
  }

  void enqueue(int x)
  {
  	struct node* temp = (struct node*) malloc (sizeof(struct node));
  	temp->data = x;
    temp->next = NULL;

    if(rear == NULL)
  	{
  		front = temp;
  	  rear = temp;
      return;
  	}
  	else
  	{
  	  rear->next = temp;
  		rear = temp;
  	}
  }

  int dequeue()
  {
    if(front==NULL)
    {
      return -420;
    }

    int x = front->data;
    front = front->next;

    if(front == NULL)
      rear = NULL;

    return x;
  }

  void printQ()
  {
  	struct node *temp = front;

  	while(temp!=rear)
  	{
  		cout << temp->data << "  ";
  		temp = temp->next;
  	}
  }

  bool isEmpty()
  {
    if(front==NULL)
    {
      return 1;
    }
    return 0;
  }
};

class Graph
{
	public :
	int n;

	struct node *N[100];

	Graph()
	{
		for(int i=0; i<n; i++)
		{
			N[i] = NULL;
		}
	}

	void insertEdge(int n1, int n2, int w)
	{
		N[n1] = insert(n2, N[n1], w);
		N[n2] = insert(n1, N[n2], w);
	}

	void print()
	{
		for(int i=0; i<n; i++)
		{
			printList(N[i]);
			cout<<endl;
		}
	}

};




void DFS(Graph G, int s, int t);
void DFS(Graph G, int s);
bool DFS(Graph G);

void BFS(Graph G, int s, int t);
void BFS(Graph G, int s);
bool BFS(Graph G);

vector<int> BFS_SPATH(Graph G, int s, int flag);

void LPATH(Graph G, int flag);

void MAX_Weight_MST(Graph G);

void TEST_bipartite(Graph G);
void Test_articulationpoints(Graph G);
void Test_bridges(Graph G);

void MST_Prim(Graph G);
void MST_Kruskal(Graph G);
void MST_youralgo(Graph G);
