#include <bits/stdc++.h>

using namespace std;

int a[310][310];

vector < int > v[310][310];
int main()
{
    int t, n, m, p, x, y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> p;
        for(i=0; i<p; i++)
        {
            cin >> x >> y;
            a[x][y] = 1;
        }
    }
}
