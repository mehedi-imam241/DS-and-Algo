#include<bits/stdc++.h>
using namespace std;

int BFS(vector<int> adjList[],int v,int Nodes)
{
    int discovered[Nodes];
    int level[Nodes];
    for(int i=0; i<Nodes; i++)
    {
        discovered[i]=0;
    }
    queue<int> q;
    q.push(v);

    discovered[v]= 1;
    level[v] = 0;

    while(!q.empty())
    {
        v=q.front();
        q.pop();

        for(int u : adjList[v])
        {
            if(!discovered[u])
            {
                discovered[u]=1;
                level[u]=level[v]+1;
                q.push(u);
            }
            else if(level[v]==level[u])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main (void)
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int Node,Edge;
    cin>>Node>>Edge;
    vector <int> adjList[Node];
    for(int i=0; i<Edge; i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i=0; i<Node; i++)
    {
        cout<<i<<"---"<<endl;
        for(auto it=adjList[i].begin(); it!=adjList[i].end(); it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }


    if(BFS(adjList, 0, Node))
    {
        cout<<"Bipartite Graph"<<endl;
    }
    else
    {
        cout<<"Not a Bipartite Graph"<<endl;
    }
    return 0;
}
