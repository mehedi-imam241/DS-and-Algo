#include <bits/stdc++.h>
using namespace std;

int temp[101], arr[101][101], top, bottom;

int kadane1D(int n)
{
    int sum = 0;
    int max = INT_MIN;
    int tempTop;
    for (int i = 0; i < n; i++)
    {
        sum += temp[i];
        if (sum > max)
        {
            max = sum;
            top = tempTop;
            bottom = i;
        }
        if (sum < 0)
        {
            sum = 0;
            tempTop = i + 1;
        }
    }
    return max;
}

void maxrangesum(int rowN,int colN)
{
    int max = INT_MIN, finalTop, finalBottom, finalRight, finalLeft;
    for (int left = 0; left < colN; left++)
    {
        memset(temp, 0, sizeof(temp));
        for (int right = left; right < colN; right++)
        {
            for (int k = 0; k < rowN; k++)
            {
                temp[k] += arr[k][right];
            }
            int t = kadane1D(rowN);
            if (t > max)
            {
                max = t;
                finalTop = top;
                finalBottom = bottom;
                finalLeft = left;
                finalRight = right;
            }
        }
    }
    cout << finalTop << " " << finalBottom << endl;
    cout << finalLeft << " " << finalRight << endl;
    cout << max << endl;
}

int main(void)
{
    freopen("input.txt","r",stdin);
    int colN,rowN ; // N is the number of rows and columns .
    while(cin>>rowN>>colN)
    {
        for(int i=0;i<rowN;i++)
        {
            for(int j=0;j<colN;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        maxrangesum(rowN,colN);
    }
}
