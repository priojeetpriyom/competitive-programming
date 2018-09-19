*
    algo:
    idea:

*/
//
//
//#include<stdio.h>
//#include<string.h>

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 1000100
//#define mod 1000000007
struct node
{
    ll sum, propagate;

} tree[MX];
int t, tc;
int ara[MX];
int n, q, s, f, val;


//void build(int node, int beg, int endd)
//{
//
//    tree[node].propagate=0;
//        tree[node].sum = 0;
//    if(beg==endd)
//    {
//        return;
//    }
////    tree[node].propagate=0;
//    int left = node<<1;
//    int  right = left+1;
//    int mid = (beg+endd)/2;
//    build(left, beg, mid);
//    build(right, mid+1, endd);
//
//    tree[node].sum = tree[left].sum + tree[right].sum;
//}
void update(int node, int beg, int endd)
{
//    if(beg>f || endd< s)
//        return;
    if(beg>=s && endd<=f)
    {
        tree[node].propagate+= val;
        tree[node].sum += (endd-beg+1)*val;
        return;
    }

    int left = node<<1;
    int  right = left+1;
    int mid = (beg+endd)/2;
    if(!(beg>f || mid<s))
        update(left, beg, mid);
    if(!(mid>f || endd<s))
        update(right, mid+1, endd);

    tree[node].sum = tree[left].sum + tree[right].sum + (endd-beg+1)*tree[node].propagate;
}
ll query(int node, int beg, int endd, ll carry)
{

//    if(beg>s || endd< s)
//        return ;
    if(beg>=s && endd<=f)
    {
//        printf("full_inRange b %d e %d ret %lld\n",beg, endd, carry*(endd-beg+1) + tree[node].sum);
        return carry*(endd-beg+1) + tree[node].sum;
//        return;
    }

    int left = node<<1;
    int  right = left+1;
    int mid = (beg+endd)/2;
    ll ret=0;
    if(!(beg>f || mid<s))
        ret = query(left, beg, mid, carry+tree[node].propagate);
    if(!(mid>f || endd<s))
    ret +=query(right, mid+1, endd, carry + tree[node].propagate);

    return ret;
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
    memset(tree, 0, sizeof tree);
//    len=0;
//        memset(dist, -1, sizeof dist);
//        memset(vis, 0, sizeof vis);
//        int n;
//        int start;
        scanf("%d %d", &n, &q);
//        scanf("\n%s", str+1);
//        str[0]=1;
//        n = strlen(str)-1;
//        cout<<n<<" "<<str<<endl;
//        for(int i=1; i<=n; i++)
//        {
//            scanf("%d", &ara[i]);
//        }
//        build(1, 1, n);
//        scanf("%d", &q);
//        wildcard.clear();
        char c;

        printf("Case %d:\n", tc);

        while(q--)
        {
            scanf("\n%c", &c);
            if(c=='0')
            {
                scanf("%d %d %d", &s, &f, &val);
                s++;
                f++;
                update(1, 1, n);
            }
            else
            {
                scanf("%d %d", &s, &f);
                s++,f++;
                printf("%lld\n", query(1, 1, n, 0));
            }
//            printf("%s\n", grid[i]+1);
        }

    }
//    printf("\n");


    return 0;
}
