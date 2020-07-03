#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> segTree, inputArray;
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
            segTree[num] = L; //also okay with R cz they are equal
        }
        else
        {
            build(left(num), L, (L + R) / 2);
            build(right(num), (L + R) / 2 + 1, R);
            int p1 = segTree[left(num)];
            int p2 = segTree[right(num)];
            segTree[num] = inputArray[p1] < inputArray[p2] ? p1 : p2;
        }
    }
    int rangeMinimumQuery(int num, int L, int R, int querylow, int queryHigh)
    {
        if (queryHigh < L || querylow > R)
        {
            return -1;
        }
        if (queryHigh >= R && querylow <= L)
        {
            return segTree[num];
        }
        int p1 = rangeMinimumQuery(left(num), L, (L + R) / 2, querylow, queryHigh);
        int p2 = rangeMinimumQuery(right(num), (L + R) / 2 + 1, R, querylow, queryHigh);
        if (p1 == -1)
        {
            return p2;
        }
        if (p2 == -1)
        {
            return p1;
        }
        return inputArray[p1] < inputArray[p2] ? p1 : p2;
    }

public:
    SegmentTree(vector<int> const &A)
    {
        inputArray = A;
        n = inputArray.size();
        segTree.assign(4 * n, 0);
        build(1, 0, n - 1);
    }
    int rangeMinimumQuery(int i, int j)
    {
        return rangeMinimumQuery(1, 0, n - 1, i, j);
    }
};

int main()
{
    int arr[] = {-1, 17, 13, 19, 15, 11, 20};
    vector<int> A(arr, arr + 7);
    SegmentTree st(A);
    cout << "RMQ (0, 3)= " << st.rangeMinimumQuery(1, 8) << endl;
    cout << "RMQ (4, 6)= " << st.rangeMinimumQuery(4, 6) << endl;
}