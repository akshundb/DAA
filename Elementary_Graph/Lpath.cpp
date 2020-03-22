#include"graph.h"
#include<vector>
#include<list>
#include<iterator>
#include <algorithm>


list<int> Lpath (Graph G, bool flag)
{
  list<int> longestPath;

  int far1, far2;

  vector<int> v;

  v = BFS_SPATH(G,0,false);
  far1 = max_element(v.begin(), v.end()) - v.begin(); // farthest element from 0

  v = BFS_SPATH(G,far1,false);
  far2 = max_element(v.begin(), v.end()) - v.begin(); // farthest element from far1


  longestPath.push_back(far1);
  longestPath.push_back(far2);

  return longestPath;
}
