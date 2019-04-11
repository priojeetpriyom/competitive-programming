#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    double a,b,c;

    int n, m;

    cin>>n>>m;

    double mn = 1e9;

    for(int i=0; i<n; i++)
    {
        cin>>a>>b;
        if((a/b)*m <=mn)
            mn = (a/b)*m;
    }

    printf("%.08lf\n", mn);



    return 0;
}


