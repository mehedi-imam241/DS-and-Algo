#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    for(int i=1;i<n;i++)
    {
        maxTillNow = max({maxTillNow*a[i],minTillNow*a[i],a[i]});
        minTillNow = min({maxTillNow*a[i],minTillNow*a[i],a[i]});
        ans = max(maxTillNow,ans);
        prevMax=maxTillNow;
        prevmin=minTillNow;
    }
}