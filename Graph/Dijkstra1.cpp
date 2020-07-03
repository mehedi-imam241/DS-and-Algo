#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>>adjList[],int u,int v,int wt)
{
    adjList[u].push_back(make_pair(v,wt));
    adjList[v].push_back(make_pair(u,wt));
}

void Dijkstra(vector<pair<int,int>>adjList[],int Nodes,int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int dist[Nodes];
    for(int i=0;i<Nodes;i++)
    {
        dist[i]=INT_MAX;
    }
    pq.push(make_pair(0,src));
    dist[src]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        for(auto x:adjList[u])
        {
            int v=x.first;
            int weight=x.second;
            if(dist[v]>dist[u]+weight)
            {
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    cout<<"There goes the Nodes and Distance from source: "<<endl;
    for(int i=0;i<Nodes;i++)
    {
        cout<<i<<"\t"<<dist[i]<<endl;
    }
}

int main(void)
{
    freopen("input.txt","r",stdin);
    int Nodes,Edge;
    cin>>Nodes>>Edge;
    vector<pair<int,int>> adjList[Nodes];
    for(int i=0;i<Edge;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        addEdge(adjList,u,v,wt);
    }
    Dijkstra(adjList,Nodes,0);
}