#include<cstdlib>
#include<vector>
#include"graph.h"

vector<int> BFS_SPATH(Graph G, int s, bool flag)
{
  bool visit[G.n];
  vector<int> d;
  queue Q;

  for(int i = 0; i<G.n; i++)
  {
        visit[i] = false;
        d.push_back(0);
  }

  visit[s] = true;

  Q.enqueue(s);

  struct node* temp;
  int x;
  int u;

  while(Q.isEmpty() == 0)
  {
      x = Q.dequeue();

      temp = G.N[x];

      while(temp!=NULL)
      {
          u = temp->data;
          if(visit[u] == 0)
          {
              visit[u] = 1;
              d[u] = d[x]+1;

              Q.enqueue(u);

              temp = temp->next;
          }
          else
          {

            temp = temp->next;
          }
      }
    }
  return d;
}
