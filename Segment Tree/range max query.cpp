#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> st, a;
    int n;
    int left(int num)
    {
        return num << 1;
    }
    int right(int num)
    {
        return (num << 1) + 1;
    }

    void build(int num, int L, int R)
    {
        if (L == R)
        {
            st[num] = L;
        }
        else
        {
            build(left(num), L, (L + R) / 2);
            build(right(num), (L + R) / 2 + 1, R);
            int p1 = st[left(num)];
            int p2 = st[right(num)];
            st[num] = (a[p1] > a[p2]) ? p1 : p2;
        }
    }
    int rMaxQ(int num, int L, int R, int queryLow, int queryHigh)
    {
        if (L > queryHigh || R < queryLow)
        {
            return -1;
        }
        else if (L >= queryLow && R <= queryHigh)
        {
            return st[num];
        }
        int p1 = rMaxQ(left(num), L, (L + R) / 2, queryLow, queryHigh);
        int p2 = rMaxQ(right(num), (L + R) / 2 + 1, R, queryLow, queryHigh);
        if (p1 == -1)
            return p2;
        if (p2 == -1)
            return p1;
        return (a[p1] > a[p2]) ? p1 : p2;
    }

public:
    SegmentTree(vector<int> const &A)
    {
        a=A;
        n=a.size();
        st.assign(4*n,0);
        build(1,0,n-1);
    }
    int rmaxq(int i,int j)
    {
        return rMaxQ(1,0,n-1,i,j);
    }
};
int main(void)
{
    int arr[] = {-1, 17, 13, 19, 15, 11, 20};
    vector<int> A(arr, arr + 7);
    SegmentTree st(A);
    cout << "RMQ (0, 3)= " << st.rmaxq(0, 0) << endl;
    cout << "RMQ (4, 6)= " << st.rmaxq(4, 5) << endl;
}

