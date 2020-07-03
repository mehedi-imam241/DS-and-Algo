#include <bits/stdc++.h>
using namespace std;

void BellmanFord(vector<pair<int, int> > adjList[], int Vertex, int Source)
{
    int dist[Vertex];
    for (int i = 0; i < Vertex; i++)
    {
        dist[i] = INT_MAX;
    };
    dist[Source] = 0;
    for (int i = 0; i < Vertex - 1; i++)
    {
        for (int u = 0; u < Vertex; u++)
        {
            for (auto v:adjList[u])
            {
                dist[v.first] = min(dist[v.first], dist[u] + v.second);
            }
        }
    }
    cout << "Vertex     Distance"<<endl;
    for (int i = 0; i < Vertex; i++)
    {
        cout << i << "    " << dist[i] << endl;
    }

    bool hasNegativeCycle =false;
    for(int u=0;u<Vertex;u++)
    {
        for(auto v:adjList[u])
        {
            if(dist[v.first]>dist[u]+v.second)
            {
                hasNegativeCycle=true;
            }
        }
    }
    cout<<"Negative cycle Exist?"<<(hasNegativeCycle ? "Yes" : "No")<<endl;

    if(!hasNegativeCycle)
    {
        for(int i=0;i<Vertex;i++)
        {
            cout<<Source<<" "<<i<<" "<<dist[i]<<endl;
        }
    }

}


int main(void)
{
    freopen("bellmanFord.txt", "r", stdin);
    //freopen("output.txt","w",stdout);
    int Vertex, Edge, Source;
    cin >> Vertex >> Edge >> Source;
    vector<pair<int, int> > adjList[Vertex];
    for (int i = 0; i < Edge; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adjList[u].push_back(make_pair(v, wt));
    }

    BellmanFord(adjList, Edge, Source);

}