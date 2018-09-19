#include <bits/stdc++.h>
using namespace std;
int n, tree[10001000], lim=10000000;

void update(int idx) {
    while(idx<= lim) {
        tree[idx]+=1;
        idx += (idx & -idx);
    }
}

long long query(int idx) {
    long long sum=0;
    while(idx!=0) {
        sum+= tree[idx];
        idx-= (idx & -idx);
    }
    return sum;
}

int main()
{
//        freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    int t,x;
    cin>>t;

    while(t--) {
        memset(tree, 0, sizeof tree);
        scanf("%d", &n);
        long long ans=0;
        while(n--) {
            scanf("%d", &x);
            ans+= (query(lim) - query(x));
            update(x);
        }
        printf("%lld\n", ans);
    }

    return 0;
}









