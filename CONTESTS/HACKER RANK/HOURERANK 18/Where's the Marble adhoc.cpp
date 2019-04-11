#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int main()
{
//        freopen("out.txt", "w", stdout);

    int n,m, ara[12];

    cin>>m>>n;

    for(int i=1; i<=10; i++) {
        ara[i]= i;
    }
    for(int i=1; i<=n; i++) {
        int x,y;
        cin>>x>>y;
        swap(ara[x], ara[y]);
    }

    for(int i=1; i<=10; i++)
        if(ara[i] == m)
            printf("%d\n",i);

    return 0;
}


