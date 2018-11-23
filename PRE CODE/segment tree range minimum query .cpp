#include <bits/stdc++.h>
using namespace std;
#define size 100
int ara[size], tree[size *3] = {1<<31};

int build(int node, int beg, int endd) {
//    getchar();
    printf("node %d left %d right %d\n",node,  beg, endd);
    if(beg == endd) {
        return tree[node] = ara[beg];
    }

    int left = node<<1;
    int right = left | 1;
    int mid = (beg + endd)>>1;
//    build(left, beg, mid);build(right, mid+1, endd);
    tree[node] = min(tree[node], build(left, beg, mid));
    tree[node] = min(tree[node], build(right, mid+1, endd));
    return tree[node];


}

int query(int node, int beg, int endd, const int s, const int f) {
    if(beg >= s && endd <= f) {
        return tree[node];
    }
    if(beg> f || endd < s)
        return INT_MAX;

    int left = node<<1;
    int right = left | 1;
    int mid = (beg + endd)>>1;

    return min(query(left, beg, mid), query(right, mid+1, endd));

}

int main()

{
    int n;
    cin>>n;
    for(int i=0; i< size*3; i++)
        tree[i] = INT_MAX;
    for(int i=1; i<=n; i++)
        scanf("%d", &ara[i]);
    build(1,1,n);

//    for(int i=1; i<20; i++)
//        printf("%d ", tree[i]);

    s=1, f=3;
    while(scanf("%d %d", &s, &f)==2) {
        printf("%d\n", query(1, 1, n));
    }

    return 0;
}
