#include <bits/stdc++.h>
using namespace std;

class DisjSet
{
    int *rank, *parent, n;

public:
    DisjSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeset();
    }
    void makeset()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void Union(int x, int y)
    {
        int xParent = find(x);
        int yParent = find(y);

        if (xParent == yParent)
        {
            return;
        }
        if (rank[xParent] < rank[yParent])
        {
            parent[xParent] = yParent;
        }
        else if (rank[xParent] > rank[yParent])
        {
            parent[yParent] = xParent;
        }
        else
        {
            parent[yParent] = xParent;
            rank[xParent]++;
        }
    }
};
int main(void)
{
    DisjSet obj(5);
    obj.Union(0, 2);
    obj.Union(4, 2);
    obj.Union(3, 1);
    if (obj.find(4) == obj.find(0))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    if (obj.find(1) == obj.find(0))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}