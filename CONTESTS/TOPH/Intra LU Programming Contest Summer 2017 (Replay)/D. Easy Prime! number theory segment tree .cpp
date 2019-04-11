#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//#include <stdio.h>
//#include <string.h>
//#define ll long long
int gen[10001000], ara[100100];

//vector<int> primes;

void prime_gen()
{
    gen[1] = gen[0]=1;
    for(int i=4; i<10000010; i+=2) gen[i]=1;

    for(int i=3; i<4000; i+=2)
    {
        if(!gen[i])
            for(int j = i*i; j<10000001; j+=i)
                gen[j]=1;
    }
//        primes[3]=1;
//     for(int i=2; i<10000010; i++ ) {
//        primes[i] += primes[i-1]+ (!gen[i-1] );
//     }

}


int val, tree[800100], idx;

int build (int b, int e, int node)
{
//    printf("b %d e %d node %d\n", b,e, node);

    if(b == e)
    {
        tree[node] = !gen[ ara[b] ];
        return tree[node];
    }

    int left = node<<1;
    int right = left+1;
    int mid = (b+e)/2;


    tree[node] = build(b, mid, left) + build(mid+1, e, right);
    return tree[node];

}


int update(int b, int e, int node)
{

    if(b>idx || e < idx) return tree[node];
    if(b == e)
    {
        tree[node] = !gen[val];
        return tree[node];
    }


    int left = node<<1;
    int right = left+1;
    int mid = (b+e)/2;


    tree[node] = update(b, mid, left) + update(mid+1, e, right);
    return tree[node];

}

int s, f;

int query(int b, int e, int node)
{
    if(b>f || e<s) return 0;

    if(b>=s && e <=f) return tree[node];


    int left = node<<1;
    int right = left+1;
    int mid = (b+e)/2;


    return query(b, mid, left) + query(mid+1, e, right);
//                 return tree[node];

}




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, n,q;
//    cin>>t;
    prime_gen();
//    vector<int>:: iterator it;

//    while(t--)
    {
        scanf("%d", &n);

        for(int i=1; i<=n; i++)
            scanf("%d", &ara[i]);

        scanf("%d", &q);
        build(1, n, 1);
//        printf("aise\n");
        int x;
        while(q--) {
            scanf("%d", &x);

            if(x==1) {
                scanf("%d %d", &s, &f);
                printf("%d\n", query(1,n,1));
            } else {
                scanf("%d %d", &idx, &val);
                update(1, n, 1);
            }


        }

//        printf("%d\n", primes[n]);


    }


    return 0;
}
