#include<bits/stdc++.h>
using namespace std;

void binaryrep(int n)
{
    if(n>1)
    {
        binaryrep(n>>1);
    }
    cout<<(n&1);
}

int main(void)
{
    binaryrep(6);
}