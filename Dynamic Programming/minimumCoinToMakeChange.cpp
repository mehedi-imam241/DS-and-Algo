#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int coins[]={1,2};
    int size=2;
    int sumToMake=5;
    int dp[sumToMake];
    for(int i=1;i<sumToMake;i++)
    {
        dp[i]=100000;
    }
    dp[0]=0;
    for(int i=0;i<size;i++)
    {
        for(int j=coins[i];j<=sumToMake;j++)
        {
            dp[j]=min(dp[j],dp[j-coins[i]]+1);
        }
    }
    cout<<dp[sumToMake]<<endl;
}