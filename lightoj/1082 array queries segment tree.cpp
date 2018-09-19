#include <bits/stdc++.h>
using namespace std;
int ara[100010],tree[300010];
int s,f;
void init(int node, int b, int e) {
    if(b==e) {
        tree[node] = ara[b];
        return;
    }
    int left = node*2;
    int right = left+1;
    int mid = (b+e)/2;
    init(left,b, mid);
    init(right,mid+1,e);
    tree[node] = min(tree[left],tree[right]);
}

int query(int node, int b,int e, int mn) {

    if(b>=s && e<=f) {
        return tree[node];
    }
    if(b>e || e<s || b==e) {
        return INT_MAX;
    }
    int left = node*2;
    int right = left+1;
    int mid = (b+e)/2;
    if(e>=s)
    mn = min(mn, query(left,b,mid,mn));
    if(b<=f)
    mn = min(mn, query(right,mid+1,e,mn));
    return mn;

}


int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int t;
    scanf("%d",&t);

    for(int tc=1; tc<=t; tc++) {
        int n, q;
        scanf("%d %d",&n, &q);
        printf("Case %d:\n",tc);
        for(int i=1; i<=n; i++)
            scanf("%d",&ara[i]);
        init(1,1,n);

        for(int i=0; i<q; i++) {
            scanf("%d %d",&s, &f);
            printf("%d\n",query(1,1,n, INT_MAX));

        }
    }

    return 0;
}
