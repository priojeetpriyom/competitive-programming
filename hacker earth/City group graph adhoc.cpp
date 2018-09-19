#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> conn(100100);


int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n,k;
    cin>>n>>k;
    int x, u, v;
    for(int i=1; i<=k; i++) {
        scanf("%d", &x);
        for(int j=0; j<x;j++) {
            scanf("%d", &u);
            conn[u] = i;
        }
    }

    int q;
    cin>>q;

    while(q--) {
        scanf("%d %d", &u, &v);
        u = conn[u], v=conn[v];
        if(v<u) swap(v,u);
        printf("%d\n", min(v-u, u+k-v));
    }

    return 0;

}

