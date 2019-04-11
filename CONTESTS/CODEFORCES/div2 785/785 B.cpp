#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


struct node {
int l,r;
};

bool comp(node a, node b) {
    return a.l < b.l;
}

struct node chess[200100],    prog[200100];
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n,m;
    cin>>n;
    for(int i=0; i<n; i++) {
        scanf("%d %d", &chess[i].l, &chess[i].r);
    }
    cin>>m;
    for(int i=0; i<m; i++) {
        scanf("%d %d", &prog[i].l, &prog[i].r);
    }

    int mx =0;
    for(int i=0; i<n; i++) {
        if(chess[i].r < prog[m-1].l) {
//            printf("prog %d chess %d", prog[m-1].l, chess[i].r);
            mx = max(mx, prog[m-1].l - chess[i].r);
        }
    }


    for(int i=0; i<m; i++) {
        if(prog[i].r < chess[n-1].l) {
//            printf("prog %d chess %d", prog[i].l, chess[i].r);
            mx = max(mx, chess[n-1].l - prog[i].r);
        }

    }

    cout<<mx;

    return 0;
}


