
/*
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
struct Node
{
    int zero, one, two, propagate;

} tree[MX];
int t, tc;
int n, q, s, f;


void build(int node, int beg, int endd)
{
    if(beg==endd)
    {
        tree[node].zero=1;
        return;
    }
//    tree[node].propagate=0;
    int left = node<<1;
    int  right = left+1;
    int mid = (beg+endd)/2;
    build(left, beg, mid);
    build(right, mid+1, endd);

    tree[node].zero = tree[left].zero + tree[right].zero;
}
void swapValues(int node) {
    swap(tree[node].zero, tree[node].two);
    swap(tree[node].one, tree[node].two);
}
int getDivs(int node, int mod) {
    if(mod==0) {
        return tree[node].zero;
    }if(mod==1) {
        return tree[node].two;
    }if(mod==2) {
        return tree[node].one;
    }
	return 0;
}
void sumChildNodes(int root) {
    tree[root].zero = tree[root*2].zero + tree[root*2+1].zero;
    tree[root].one = tree[root*2].one + tree[root*2+1].one;
    tree[root].two = tree[root*2].two + tree[root*2+1].two;


}
void update(int node, int beg, int endd)
{
    if(beg>f || endd< s)
        return;
    if(beg>=s && endd<=f)
    {
        tree[node].propagate+=1;
        swapValues(node);
//        printf("update_node %d beg %d end %d zero %d ones %d twos %d\n", node, beg, endd, tree[node].zero, tree[node].one, tree[node].two);
        return;
    }

    int left = node<<1;
    int  right = left+1;
    int mid = (beg+endd)/2;

    update(left, beg, mid);

    update(right, mid+1, endd);

    sumChildNodes(node);
    int temp = tree[node].propagate%3;
    while(temp--)
        swapValues(node);
}
int ones, twos;
int query(int node, int beg, int endd, int carry)
{
    if(beg>f || endd< s)
        return 0;
    if(beg>=s && endd<=f)
    {
//        printf("query_node %d beg %d end %d carry %d zero %d ones %d twos %d\n", node, beg, endd, carry, tree[node].zero, tree[node].one, tree[node].two);

//        printf("full_inRange b %d e %d ret %lld\n",beg, endd, carry*(endd-beg+1) + tree[node].sum);
        return getDivs(node, carry%3);
//        return;
    }

    int left = node<<1;
    int  right = left+1;
    int mid = (beg+endd)/2;
    int ret=0;

    ret = query(left, beg, mid, carry+tree[node].propagate);

    ret +=query(right, mid+1, endd, carry + tree[node].propagate);

    return ret;
}

void printAll() {
    for(int i=1; i<=n; i++) {
                    s=i, f=i;
                    printf("%d ", query(1, 1, n, 0));
                }   printf("zeros \n");

    for(int i=1; i<=n; i++) {
                    s=i, f=i;
                    printf("%d ", query(1, 1, n, 1));
                }   printf("ones \n");

    for(int i=1; i<=n; i++) {
                    s=i, f=i;
                    printf("%d ", query(1, 1, n, 2));
                }   printf("twos \n\n\n");
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
        build(1, 1, n);
//        printAll();
//        scanf("\n%s", str+1);
//        str[0]=1;
//        n = strlen(str)-1;
//        cout<<n<<" "<<str<<endl;
//        for(int i=1; i<=n; i++)
//        {
//            build(1, 1,n);
//        }
//        build(1, 1, n);
//        scanf("%d", &q);
//        wildcard.clear();
        int c;

        printf("Case %d:\n", tc);

        while(q--)
        {
            scanf("%d", &c);
            if(c==0)
            {
                scanf("%d %d", &s, &f);
                s++,f++;
                update(1, 1, n);
//                s=1, f=n;
//                printf("%d\n", query(1, 1, n, 0));
//                printAll();
            }
            else
            {
                scanf("%d %d", &s, &f);
                s++,f++;
                printf("%d\n", query(1, 1, n, 0));
            }
//            printf("%s\n", grid[i]+1);
        }

    }
//    printf("\n");


    return 0;
}
