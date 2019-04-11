#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ara[11111];



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++) {
        scanf("%d", &ara[i]);
    }

    int l,r,x;

    while(m--) {
        scanf("%d %d %d", &l, &r, &x);
//        x
//        int pos= ara[x];
        for(int i=l; i<=r; i++) {
            if(ara[x]> ara[i]) l++;
        }
//        printf("l %d x %d\n", l, x);
        if(l == x) {
            printf("Yes\n");
        }
        else printf("No\n");
    }




    return 0;
}


