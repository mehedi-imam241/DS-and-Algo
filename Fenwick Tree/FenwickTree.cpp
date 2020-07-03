#include <bits/stdc++.h>
using namespace std;
#define LSOne(S) (S & -S)
class FenwickTree
{
    vector<int> Ftree;

public:
    FenwickTree(int n)
    {
        Ftree.assign(n + 1, 0);
    }
    int rsq(int b)
    {
        int sum = 0;
        for (; b; b -= LSOne(b))
        {
            sum += Ftree[b];
            cout << "B: " << b << "    " << Ftree[b] << endl;
        }
        return sum;
    }
    int rsq(int a, int b)
    {
        return rsq(b) - rsq(a - 1);
    }
    void adjust(int k, int v)
    {
        for (; k < Ftree.size(); k += LSOne(k))
        {
            Ftree[k] += v;
            //cout<<"k: "<<k<<" Ftree[k] "<<Ftree[k]<<" v: "<<v<<endl;
        }
        for (int i = 0; i < Ftree.size(); i++)
        {
            cout << Ftree[i] << "  ";
        }
    }
};

int main(void)
{
    int f[] = {0,1, 2, 4, 5};
    FenwickTree ft(4);
    for (int i = 1; i < 5; i++)
    {
        cout << endl
             << "-.-.-.-.-" << i << "   " << f[i] << endl;
        ft.adjust(i, f[i]);
    }
    //cout << ft.rsq(1, 1) << endl;
    // cout << ft.rsq(1, 7) << endl;
    // cout<<ft.rsq(1,6)<<endl;
    // cout<<ft.rsq(1,10)<<endl;
    // cout<<ft.rsq(3,6)<<endl;
    // cout<<"---------"<<endl;
    // ft.adjust(5,2);
    // cout<<ft.rsq(1,10)<<endl;
}