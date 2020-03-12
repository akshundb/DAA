#include "graph.h"
#include<iostream>

#define MAX 10000

using namespace std;

bool visited[MAX];

bool DFS(struct Graph G, int s, int t)
{

        struct node *temp = G.N[s];

        visited[s] = 1;

        if(s == t)
        {
          return 1;
        }


        while(temp!=NULL)
        {
            int connectedVertex = temp->data;
            if(visited[connectedVertex] == 0)
            {
                return DFS(G, connectedVertex, t);
            }

            temp = temp->next;
        }
}
