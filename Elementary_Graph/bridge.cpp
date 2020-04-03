#include<iostream>
#include<stdlib.h>
#include<vector>
#include<list>
#include<queue>

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
void myDelete(int data,struct node *head);

struct node* myinsert(int data,  struct node *head, int w)
{
	struct node *myinsert=(struct node*)malloc(sizeof(struct node));
	myinsert->next = NULL;
	myinsert->data = data;
	myinsert->weight = w;
	if(head!=NULL)
	{
		myinsert->next = head->next;
		head->next = myinsert;
	}
	else
	{
		myinsert->next = NULL;
	 	return myinsert;
	}

	return head;

}

void myDelete(int data,struct node *head)
{
	struct node* temp = head;
	struct node* prev;
	
	if(head->data == data)
		head = temp->next;
	else{
		while(temp){
			if(temp->data == data){
				prev->next = temp->next;
				break;
			}
			prev = temp;
			temp = temp->next;
		}
	}
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

	void deleteEdge(int n1,int n2)
	{
		myDelete(n2,N[n1]);
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

bool BFS(Graph G, int s, int t)
{
    queue<int> Q;
    bool visit[G.n];
    for(int i = 0; i < G.n; i++)
        visit[i] = false;
    visit[s] = true;
    Q.push(s);
    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        struct node* temp = G.N[x];
        int i;
        while(temp)
        {
            i = temp->data;
            if(!visit[i])
            {
                if(t == i)
                    return true;
                visit[i] = true;
                Q.push(i);
            }
            temp = temp->next;
        }
    }
    return false;
}

void Test_bridges(Graph G)
{
    vector<int> u;
    vector<int> v;


    struct node *temp;
    for(int u1=0;u1<G.n;u1++)
    {
        temp=G.N[u1];
		G.print();
        while(temp != NULL)
        {
            int v1=temp->data;
            int w=temp->weight;
            myDelete(v1, G.N[u1]);
            G.print();
			cout<<endl;
            if(!BFS(G,u1,v1))
            {
                u.push_back(u1);
                v.push_back(v1);
            }
            G.insertEdge(u1,v1,w);
            G.insertEdge(v1,u1,w);
            temp=temp->next;
        }
    }

    cout<<"Bridges are:-"<<endl;
    cout<<"hi";
    cout<<u.size();
    for(int i=0;i<10;i++)
    {
    cout<<"hello"<<endl;
        cout<<"Edge "<<u[i]<<"-->"<<v[i]<<endl;
    }
    cout<<endl<<endl;
}

int main()
{
  	Graph G;
  	Graph K;
  	G.n = 10;
  	K.n = 10;
  	for(int i=0; i<G.n; i++)
	{
		G.N[i] = NULL;
	}
  	for(int i=0; i<G.n; i++)
	{
		K.N[i] = NULL;
	}

  	G.insertEdge(0,1,3);
  	G.insertEdge(0,2,2);
  	G.insertEdge(1,2,6);
  	G.insertEdge(1,3,4);
  	G.insertEdge(2,3,2);
  	G.insertEdge(2,4,5);
  	G.insertEdge(3,4,1);
  	G.insertEdge(3,5,10);
  	G.insertEdge(3,6,8);
  	G.insertEdge(4,6,7);
  	G.insertEdge(6,7,3);
  	G.insertEdge(1,0,3);
  	G.insertEdge(2,0,2);
  	G.insertEdge(2,1,6);
  	G.insertEdge(3,1,4);
  	G.insertEdge(3,2,2);
 	G.insertEdge(4,2,5);
  	G.insertEdge(4,3,1);
  	G.insertEdge(5,3,10);
 	G.insertEdge(6,3,8);
  	G.insertEdge(6,4,7);
  	G.insertEdge(7,6,3);
  	G.deleteEdge(1,2);
  	G.print();
	//Test_bridges(G);
}
