#include"graph.h"

void DFS(Graph G);
{
struct node* temp;
temp=N[0];

while(temp!=NULL && visited(temp->data)==false)
{
cout<<temp->data<<endl;
}

}
