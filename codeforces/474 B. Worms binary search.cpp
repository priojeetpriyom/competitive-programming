#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ara[100100];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    cin>>n>>ara[0];

    for(int i=1; i<n; i++) {
        scanf("%I64d", &ara[i]);
        ara[i]+=ara[i-1];
    }
    ara[n] = INT_MAX;
    int m;
    cin>>m;
    ll x;
    for(int i=0; i<m; i++) {
        scanf("%I64d", &x);
        int j=0;
//        printf("oka");
        for(int high = n/2; high>0; high/=2) {
            if(ara[j+ high] <=x)
                j+=high;
        }
        while(ara[j]<x)
            j++;
        printf("%d\n", j+1);
    }



    return 0;
}




