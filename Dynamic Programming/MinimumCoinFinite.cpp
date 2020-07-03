#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int coin[]={4,4,5,5};
    int size=4;
    int sum=8;
    int dp[20];//bishal boro size nite hobe. Nahole segfault ashbe...karon emon hote pare ans sumer kache nai...
                // ba ans onek boro

    for(int i=1;i<20;i++) dp[i]=100000;
    dp[0]=0;
    for(int i=0;i<size;i++)
    {
        for(int j=sum+coin[i];j>=coin[i];j--)
        {
            dp[j]=min(dp[j],dp[j-coin[i]]+1);
        }
    }
    for(int i=sum;i<20;i++) //20 ekhane dp size
    {
        if(dp[i]!=100000)
        {
            cout<<i<<" "<<dp[i]<<endl;
            break;
        }
    }
}