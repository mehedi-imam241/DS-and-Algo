#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int val[] = {7, 8, 4}, wt[] = {3, 8, 6}, W = 10, n = 3;

    int dp[51];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        for (int j = W; j >= wt[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
        }
    }
    cout << dp[W] << endl;
}