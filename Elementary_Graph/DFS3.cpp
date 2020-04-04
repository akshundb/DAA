#include "graph.h"
#include<list>
#include<iostream>

#define MAX 10000

using namespace std;

bool visited[MAX];

bool reach=false;

bool DFS(struct Graph G, int s, int t)
{
    list<int> D;
    D=DFS(G,s);

    list<int> :: iterator i;
    for(i=D.begin();i!=D.end();i++)
    {
        if(*i == t)
        return true;
    }

    return false;
}
