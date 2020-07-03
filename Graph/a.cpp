#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF)
    {
        if (m == n)
        {
            cout << "0.0000" << endl;
        }
        else
        {
            double res = 0.0;
            double a = 10000.0 / m;
            double b = 10000.0 / (m + n);
            double c = 0.0;
            while ((a - c) > b)
            {
                c += b;
            }
            res = (m - 1) * (a - c);
            //double res = (m - 1) * (a - b);
            printf("%.4f\n", res);
        }
    }
}