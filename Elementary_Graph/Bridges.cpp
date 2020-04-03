#include"graph.h"

void Bridge(Graph G){
	for(int i = 0; i < G.n; i++){
		struct node* temp = G.N[i];
		while(temp){
			if(i < temp->data){
				int j = temp->data;
				int w = temp->weight;
				G.deleteEdge(i, j);
				if(!BFS(G, i, j))
					cout<<i<<"-->"<<j<<" is a bridge"<<endl;
				G.insertEdge(i, j, w);
			}
			temp = temp->next;
		}
	}
}
void Test_bridges(Graph G)
{
    vector<int> u;
    vector<int> v;


    struct node *temp;


    for(int u1=0;u1<G.n;u1++)
    {
        temp=G.N[u1];

        while(temp !=NULL)
        {
            int v1=temp->data;
            int w=temp->weight;
            G.deleteEdge(u1,v1);

            if(!BFS(G,u1,v1))
            {
                u.push_back(u1);
                v.push_back(v1);
            }
            G.insertEdge(u1,v1,w);
            temp=temp->next;
        }
    }

    cout<<"Bridges are:-"<<endl;
    for(int i=0;i<u.size();i++)
    {
        cout<<"Edge"<<u[i]<<"-->"<<v[i]<<endl;
    }
    cout<<endl<<endl;
}
