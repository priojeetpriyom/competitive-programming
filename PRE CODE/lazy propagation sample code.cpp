#include <bits/stdc++.h>
using namespace std;

int s, f, ara[100001], prop;

struct node{
    int sum=0 , propagate=0;
} tree[100011*3];

void init(int node, int b, int e) {

    if(b==e) {
        tree[node].sum = ara[b];
        return;
    }

    int left = node << 1;
    int right =  left +1;
    int mid = (b+e)/2;

    init(left, b, mid);
    init(right, mid+1, e);
    tree[node].sum = tree[left].sum + tree[right].sum;
}

void update(int node, int b, int e) {

    if(b>=s && e<=f) {
        tree[node].sum += prop *(e-b+1);
        tree[node].propagate += prop;
        return;
    }

    int left  = node<<1;
    int right = left + 1;
    int mid = (b+e)/2;

    if(s<=mid)
        update(left, b, mid);
    if(f>mid)
        update(right, mid+1, e);
    tree[node].sum  = tree[left].sum + tree[right].sum + tree[node].propagate * (e-b+1);
}

int query(int node, int b, int e, int carry) {

    if(b>=s && e<=f)
        return tree[node].sum + (tree[node].propagate+carry)*(e-b+1);

    int left = node << 1;
    int right = left + 1;
    int mid = (b + e)/2;
    int ls=0, rs=0;
    if(s<=mid)
        ls = query(left,b, mid, carry + tree[node].propagate);
    if(f> mid)
        rs = query(right, mid+1, e, carry + tree[node].propagate);
    return ls + rs;
}

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        scanf("%d", &ara[i]);

    init(1,1,n);
    for(int i=1; i<=11; i++)
        printf("%d ", tree[i]);
    printf("\n");
    int q;

    scanf("%d", &q);

    while(q--) {
        int x;
        scanf("%d %d %d", &x, &s, &f);
        if(x==1) {
            scanf("%d", &prop);
            update(1,1, n);
                for(int i=1; i<=7; i++)
        printf("%d ", tree[i]);
        printf("\n");
        } else {
            printf("%d\n", query(1, 1, n,0));
        }
    }



    return 0;
}
