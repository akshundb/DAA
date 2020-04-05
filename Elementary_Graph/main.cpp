#include"graph.h"
#include<list>
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

void printTree(list<int> l,int s)
{   
    cout<<"Vertices Visted From<"<<s<<":-"<<endl;
    list<int> :: iterator i;
    for(i=l.begin();i!=l.end();i++)
    {
         cout << '\t' << *i << ",";
    }
    cout<<endl;
}

int main()
{

    int choice;

    Graph G1;
    cout<<"Enter the no of vertices:-"<<endl;
    cin>>G1.n;


    for(int i=0; i<G1.n; i++)
	{
		G1.N[i] = NULL;
	}

    int u,v,w;
    list<int> D;
    bool flag;
    do
    {
        cout<<"---------------MENU----------------"<<endl;
        cout<<"1.Add Edge"<<endl<<"2.Remove Edge"<<endl<<"3.Print Graph"<<endl;
        cout<<"4.Module 1"<<endl<<"5.Module 2"<<endl<<"6.Module 3"<<endl;
        cout<<"7.Module 4"<<endl<<"8.Module 5"<<endl<<"9.Exit"<<endl;
        cout<<"Enter choice:-";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter Vertix 1:-";
            cin>>u;
            cout<<"Enter Vertix 2:-";
            cin>>v;
            cout<<"Enter Weight:-";
            cin>>w;
            G1.insertEdge(u,v,w);
            break;
            case 2:
            cout<<"Enter Vertix 1:-";
            cin>>u;
            cout<<"Enter Vertix 2:-";
            cin>>v;
            G1.deleteEdge(u,v);
            break;
            case 3:
            G1.print();
            break;
            case 4:
                cout<<"-------------MODULE 1-----------------";
                cout<<"1.DFS(Graph G)"<<endl;
                cout<<"2.DFS(Graph G,vertex s)"<<endl;
                cout<<"3.DFS(Graph G,vertex s,vertex t)"<<endl;
                cout<<"Enter choice:-";
                cin>>choice;
                switch (choice)
                {

                case 1:
                D=DFS(G1);
                printTree(D,0);
                break;

                case 2:
                cout<<"Enter Starting Vertex :-";
                cin>>u;
                D=DFS(G1,u);
                printTree(D,u);
                break;

                case 3:
                cout<<"Enter Starting Vertex :-";
                cin>>u;
                cout<<"Enter Ending Vertex :-";
                cin>>v;
                flag=DFS(G1,u,v);
                if(flag)
                cout<<"Reachable"<<endl;
                else
                cout<<"Not Reachable"<<endl;
                break;
                }
            break;

            case 5:
                cout<<"-------------MODULE 2-----------------";
                cout<<"1.BFS(Graph G)"<<endl;
                cout<<"2.BFS(Graph G,vertex s)"<<endl;
                cout<<"3.BFS(Graph G,vertex s,vertex t)"<<endl;
                cout<<"Enter choice:-";
                cin>>choice;
                switch (choice)
                {

                case 1:
                D=BFS(G1);
                printTree(D,0);
                break;

                case 2:
                cout<<"Enter Starting Vertex :-";
                cin>>u;
                D=BFS(G1,u);
                printTree(D,u);
                break;

                case 3:
                cout<<"Enter Starting Vertex :-";
                cin>>u;
                cout<<"Enter Ending Vertex :-";
                cin>>v;
                flag=BFS(G1,u,v);
                if(flag)
                cout<<"Reachable"<<endl;
                else
                cout<<"Not Reachable"<<endl;
                break;
                }
            break;

            case 6:
                cout<<"-------------MODULE 3-----------------";
                cout<<"1.BFS_SPATH(Graph G)"<<endl;
                cout<<"2.LPATH(Tree T)"<<endl;
                cout<<"3.MAX_Weight_MST(Graph G)"<<endl;
                cout<<"Enter choice:-";
                cin>>choice;
                switch (choice)
                {
                    //SPATH AND LPATH NEED TO BE FIXED
                }
            break;

            case 7:
                cout<<"-------------MODULE 4-----------------";
                cout<<"1.Test_Bipartite(Graph G)"<<endl;
                cout<<"2.Test_ArticulationPoints(Graph G)"<<endl;
                cout<<"3.Test_Bridges(Graph G)"<<endl;
                cout<<"Enter choice:-";
                cin>>choice;
                switch (choice)
                {
                    case 1:
                    if(TEST_bipartite(G1))
                    cout<<"Graph IS Bipartite"<<endl;
                    else
                    cout<<"Graph IS NOT Bipartite"<<endl;
                    break;
                    case 2:
                        Test_articulationpoints(G1);
                    break;
                    case 3:
                        Test_bridges(G1);
                    break;
                }
            break;

            case 8 :
                cout<<"-------------MODULE 5-----------------";
                cout<<"1.MST_Prim(Graph G)"<<endl;
                cout<<"2.MST_Kruskal(Graph G)"<<endl;
                cout<<"3.MST_YourAlgo(Graph G)"<<endl;
                cout<<"Enter choice:-";
                cin>>choice;
                switch (choice)
                {
                    case 1:
                    Graph Prim = MST_Prim(G1);
                    Prim.print();
                    break;
                    case 2:
                    Graph Kruskal = MST_Kruskal(G1);
                    Kruskal.print();
                    break;
                    case 3:
                    Graph MyAlgo = MST_youralgo(G1);
                    MyAlgo.print();
                    break;
                }
            break;

            case 9:
                cout<<"EXITED"<<endl;
            break;  
            default:
            cout<<"INVALID CHOICE"<<endl;
        }
    }while(choice!=9);
    return 0;
}