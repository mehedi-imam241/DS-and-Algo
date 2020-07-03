#include <bits/stdc++.h>
using namespace std;
#define LSOne(S) (S & -S)

int getsum(int BITTree[], int index)
{
    int sum = 0;
    index++;
    for (; index; index -= LSOne(index))
    {
        sum += BITTree[index];
    }
    return sum;
}

void updateBIT(int BItree[], int n, int index, int val)
{
    index++;
    for (; index <= n; index += LSOne(index))
    {
        BItree[index] += val;
    }
}
//return sum of [0.....index]
int sum(int index, int BITtree1[], int BITtree2[])
{
    return (getsum(BITtree1, index) * index) - getsum(BITtree2, index);
}

void updateRange(int BITree1[], int BITree2[], int n, int val, int l, int r)
{
    updateBIT(BITree1, n, l, val);
    updateBIT(BITree1, n, r + 1, -val);

    updateBIT(BITree2, n, l, val * (l - 1));
    updateBIT(BITree2, n, r + 1, -val * r);
}

int rangeSum(int l,int r,int BITtree1[],int BITtree2[])
{
    return sum(r,BITtree1,BITtree2)-sum(l-1,BITtree1,BITtree2);
}

int *constructBITTree(int n)
{
    int *BITtree = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        BITtree[i] = 0;
    }
    return BITtree;
}

int main(void)
{
    int n = 5;
    //int array[] = {0, 0, 0, 0, 0};
    int *BITTree1, *BITTree2;
    BITTree1 = constructBITTree(n);
    BITTree2 = constructBITTree(n);
    int l = 0 , r = 4 , val = 5; 
    updateRange(BITTree1,BITTree2,n,val,l,r); 
  
    // Add 2 to all the elements from [2,4] 
    l = 2 , r = 4 , val = 10; 
    updateRange(BITTree1,BITTree2,n,val,l,r); 
  
    // Find sum of all the elements from 
    // [1,4] 
    l = 1 , r = 4; 
    cout << "Sum of elements from [" << l 
         << "," << r << "] is "; 
    cout << rangeSum(l,r,BITTree1,BITTree2) << "\n"; 
  
    return 0; 
}