#include"graph.h"
#include<queue>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> iPair; 

Graph MST_Prim(Graph G) 
{ 
    Graph K;

    K.n=G.n;

    for(int i=0; i<G.n; i++)
  	{                          
  		K.N[i] = NULL;      
  	} 

    // Create a priority queue to store vertices 
    priority_queue<iPair, vector <iPair> , greater<iPair> > pq; 
  
    int src = 0; // Taking vertex 0 as source/root

    // Create a vector for keys and initialize all keys as infinite (INF) 
    vector<int> key(G.n, INF); 
    // To store parent array which in turn store MST 
    vector<int> parent(G.n, -1); 
    // To keep track of vertices included in MST 
    vector<bool> inMST(G.n, false); 
    // Insert source itself in priority queue and initialize its key as 0. 
    pq.push(make_pair(0, src)); 
    key[src] = 0; 
  
    /* Looping till priority queue becomes empty */
    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        pq.pop(); 
  
        inMST[u] = true;
        
        struct node* temp=G.N[u];
        while(temp!=NULL)
        { 
            // Get vertex label and weight of current adjacent of u. 
            int v =temp->data;
            int weight = temp->weight;
  
            //  If v is not in MST and weight of (u,v) is smaller than current key of v 
            if (inMST[v] == false && key[v] > weight) 
            { 
                // Updating key of v 
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
                parent[v] = u; 
            } 
        } 
    } 
  

     


    // Print edges of MST using parent array 
    for (int i = 1; i < G.n; ++i) 
    {
        K.insertEdge(parent[i],i,key[i]);
    }

    return K;
} 