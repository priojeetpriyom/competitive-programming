#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


//------------ loop macros

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define fr(i,start, till) for(int i=start; i<=till; i++)
#define frr(i,start, till) for(int i=start; i>=till; i--)

#define MX 300010


    int n, ara[MX]; //, tree[MX<<2];
    int sparse_gcd[MX] [30];
    int sparse_min[MX] [30];

void build() {
    // if(b==e) {
    //     tree[n] = ara[b];
    //     return;
    // }
    // int l = n<<1;
    // int m = (b+e)>>1;
    // build(l, b, m);
    // build(l+1, m+1, e);
    // tree[n] = __gcd(tree[l], tree[l+1]);
    memset(sparse_gcd, -1, sizeof sparse_gcd);
    memset(sparse_min, -1, sizeof sparse_min);

    for1(i, n-1)
        sparse_gcd[i][0] =__gcd(ara[i], ara[i+1]);

    for(int pw=1; pw<=30; pw++) {
        for(int i=n; i>=1; i--) {
            if(i+(1<<pw) <=n) {
                sparse_gcd[i] [pw] = __gcd(sparse_gcd[i][pw-1], sparse_gcd[i+(1<<(pw-1))] [pw-1]);
            }
        }
    }

    for1(i, n-1)
        sparse_min[i][0] =min(ara[i], ara[i+1]);

    for(int pw=1; pw<=30; pw++) {
        for(int i=n; i>=1; i--) {
            if(i+(1<<pw) <=n) {
                sparse_min[i] [pw] = min(sparse_min[i][pw-1], sparse_min[i+(1<<(pw-1))] [pw-1]);
            }
        }
    }

    // for(int pw=0; pw<=30; pw++) {
    //     for(int i=n; i>=1; i--) {if(i+(1<<pw) <=n) {
    //         cout<<"pw "<<(1<<pw)<<" i "<<i<<" sparse_gcd "<<sparse_gcd[i][pw]<<endl;
    //     }
    //     }
    // }

}
int query_gcd(int l, int r) {
    int d = r -l, u = l, ret = ara[l];

    for(int pw=30; pw>=0; pw--) {
        if(d& (1<<pw)) {
            ret = __gcd(ret, sparse_gcd[u] [pw]);
            u += (1<<pw);
        }
    }
    return ret;
}
int query_min(int l, int r) {
    int d = r -l, u = l, ret = ara[l];

    for(int pw=30; pw>=0; pw--) {
        if(d& (1<<pw)) {
            ret = min(ret, sparse_min[u] [pw]);
            u += (1<<pw);
        }
    }
    return ret;
}

bool ok(int k) {
    // multiset<int> mset;
    // for1(i,k)
    //     mset.insert(ara[i]);
    // if(*mset.begin() == query_gcd(1, k))
    //     return true;

    for(int i = k; i<=n; i++) {
        // mset.erase(mset.find(ara[i-k]));
        // mset.insert(ara[i]);
        // cout<<"i "<<i<<" query_gcd "<<query_gcd(1, 1, n, i-k+1, i)<<" mset_begin "<<*mset.begin()<<endl;
        if(query_min(i-k+1, i) == query_gcd(i-k+1, i))
            return true;
    }
    return false;
}


int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(0);

    scanf("%d", &n);

    for1(i, n)
        scanf("%d", &ara[i]);
    build();
    // cout<<"query_gcd "<<query_gcd(2,2)<<endl;
    // return 0;

    // cout<<"query_gcd 2-5 "<<query_gcd(1, 1, n, 2, 5)<<endl;

    // cout<<"m "<<4<<" oka "<<ok(4)<<endl;

    int l=1, h=n, m;

    while(l<=h) {
        m = (l+h)>>1;
        // cout<<"m "<<m<<" oka "<<ok(m)<<endl;
        if(ok(m))
            l=m+1;
        else
            h=m-1;
    }
    // cout<<l-1<<endl;
    l--;

    vector<int> ans;
    // multiset<int> mset;
    // for1(i,l)
    //     mset.insert(ara[i]);
    // if(*mset.begin() == query_gcd(1, l))
    //     ans.push_back(1);

    for(int i = l; i<=n; i++) {
        // mset.erase(mset.find(ara[i-l]));
        // mset.insert(ara[i]);
        // cout<<"i "<<i<<" query_gcd "<<query_gcd(1, 1, n, i-k+1, i)<<" mset_begin "<<*mset.begin()<<endl;
        if(query_min(i-l+1, i) == query_gcd(i-l+1, i))
            ans.push_back(i-l+1);
    }
    // cout<<ans.size()<<" "<<l-1<<endl;
    printf("%d %d\n", (int)ans.size(), l-1);
    for(int i=0; i<ans.size(); i++)
        printf("%d ", ans[i]);
    printf("\n");

    return 0;

}
