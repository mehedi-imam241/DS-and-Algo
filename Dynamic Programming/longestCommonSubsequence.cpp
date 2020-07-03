#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    int l1 = text1.length();
    int l2 = text2.length();
    int lcs[l1 + 1][l2 + 1];
    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            if (i == 0 || j == 0)
            {
                lcs[i][j] = 0;
            }
            else if (text1[i - 1] == text2[j - 1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else
            {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
    return lcs[l1][l2];
}

int main(void)
{
    string text1="ami vat khai";
    string text2="ami vat khai na";
    cout<<longestCommonSubsequence(text1,text2);
}