#include <bits/stdc++.h>
using namespace std;

void parmutation(string s, int st, int en)
{
    if (st == en)
    {
        cout << s << endl;
    }
    else
    {
        for (int i = st; i <= en; i++)
        {
            swap(s[st], s[i]);
            parmutation(s, st + 1, en);
            swap(s[st], s[i]);
        }
    }
}

int main(void)
{
    freopen("output.txt","w",stdout);
    string s = "xyz";
    parmutation(s, 0, s.size()-1);
}