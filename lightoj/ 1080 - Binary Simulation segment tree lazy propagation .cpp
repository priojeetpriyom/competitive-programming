/*
    algo: segment tree
    idea: update with lazy for each l,r. carry the propagation while query

*/


#include<stdio.h>
#include<string.h>

//#include <bits/stdc++.h>

//using namespace std;
//typedef unsigned long long ull;
//typedef long long ll;
#define MX 100100
//#define mod 1000000007
struct node {
    int val, propagate;

}tree[MX<<2];
int t, tc;
char str[MX];
int n, q, s, f;


void build(int node, int beg, int endd)
{

    if(beg==endd)
    {
        tree[node].propagate=0;
        tree[node].val = (str[beg]-'0');
        return;
    }
    tree[node].val = tree[node].propagate=0;
    int left = node<<1;
    int  right = left+1;
    int mid = (beg+endd)/2;
    build(left, beg, mid);
    build(right, mid+1, endd);


}
void update(int node, int beg, int endd)
{
//    if(beg>f || endd< s)
//        return;
    if(beg>=s && endd<=f)
    {
        tree[node].propagate ^= 1;
        return;
    }

    int left = node<<1;
    int  right = left+1;
    int mid = (beg+endd)/2;
    if(!(beg>f || mid<s))
    update(left, beg, mid);
    if(!(mid>f || endd<s))
    update(right, mid+1, endd);


}
int query(int node, int beg, int endd, int carry)
{

//    if(beg>s || endd< s)
//        return ;
    if(beg>=s && endd<=s)
    {
        return carry ^ tree[node].propagate ^ tree[node].val;
//        return;
    }

    int left = node<<1;
    int  right = left+1;
    int mid = (beg+endd)/2;
    if(mid>=s)
        return query(left, beg, mid, carry^ tree[node].propagate);

    return query(right, mid+1, endd, carry ^ tree[node].propagate);


}

int main()
{
//freopen("output.txt", "w", stdout);

//    process[0]= {1,2,3};

//    cout<<process[0].id<<" "<<process[0].at<<" "<<process[0].bt<<endl;

    scanf("%d", &t);
//    memset(ncr, -1, sizeof ncr);
//    memset(dp, -1, sizeof dp);
//        for(int i=1; i<MX; i++)
//        {
//            dist[i] = 1<<30;
//        }
    for( tc=1; tc<=t; tc++)
    {
//    memset(tree, 0, sizeof tree);
//    len=0;
//        memset(dist, -1, sizeof dist);
//        memset(vis, 0, sizeof vis);
//        int n;
//        int start;
//        scanf("%d", &n);
        scanf("\n%s", str+1);
        str[0]=1;
        n = strlen(str)-1;
//        cout<<n<<" "<<str<<endl;
        build(1, 1, n);
        scanf("%d", &q);
//        wildcard.clear();
        char c;

        printf("Case %d:\n", tc);

        while(q--)
        {
            scanf("\n%c", &c);
            if(c=='I')
            {
                scanf("%d %d", &s, &f);
                update(1, 1, n);
            }
            else
            {
                scanf("%d", &s);
                printf("%d\n", query(1, 1, n, 0));
            }
//            printf("%s\n", grid[i]+1);
        }

    }
//    printf("\n");


    return 0;
}
