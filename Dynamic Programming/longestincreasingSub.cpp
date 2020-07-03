#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,ans=0;
    vi v,b,f;
    while (cin>>n)
    {
        v.pb(n);
    }
    f.resize(v.size());
    b.resize(v.size());
    fr(i,0,v.size()-1)
    {
        f[i]=lower_bound(b.begin()+1,b.begin()+1+ans,v[i])-b.begin();
        ans=max(ans,f[i]);
        b[f[i]]=v[i];
    }
    cout<<ans<<endl<<"-"<<endl;
    vi t;
    frr(i,f.size(),0)
    {
        if(ans==f[i])
        {
            t.push_back(v[i]);
            ans--;
        }
    }
    repr(i,t.size())
    {
        cout<<t[i]<<endl;
    }
}
