/*
    algo:
    idea:
    Let's call inu the time that we reach the node u in depth first search and outu=max(inv1,inv2,⋯,invk) where vi is a child of u. If node u is in charge of node v (u is an ancestor of v) then inu≤inv≤outu. Suppose we don't have to ignore any node then the answer to each query is the LCA of two nodes u and v (l≤u,v≤r), where u and v are chosen so that inu=max(inl,inl+1,…,inr) and inv=min(inl,inl+1,…,inr). Proof: Let r be the LCA of u and v, then inr≤inv≤inu≤outr. For every node w∈[l,r], inv≤inw≤inu⇒inr≤inw≤outr⇒r is an ancestor of w. Therefore, the node that needs to be ignored is either u or v. Suppose we ignore u, the query splits into two halves [l,u−1]∪[u+1,r]. We find the LCA to each half and get the LCA of them. We do similarly for v

    and optimize the answer.

    Complexity: O(Nlog(N)+Qlog(N))
    .
*/
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

//------------ loop macros

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define fr(i,start, till) for(int i=start; i<=till; i++)
#define frr(i,start, till) for(int i=start; i>=till; i--)


//-------------- input macros

#define cin0(n, ara) for(int i=0; i<n; i++) {cin>>ara[i];}
#define cini0(i, n, ara) for(int i=0; i<n; i++) {cin>>ara[i];}

#define cin1(n, ara) for(int i=1; i<=n; i++) {cin>>ar[i];}
#define cini1(i, n, ara) for(int i=1; i<=n; i++) {cin>>ar[i];}


#define si(n) scanf("%d", &n);
#define sii(n, m) scanf("%d %d", &n, &m);
#define siii(n, m, k) scanf("%d %d %d", &n, &m, &k);
#define siiii(n, m, k, o) scanf("%d %d %d %d", &n, &m, &k, &o);

#define sl(n) scanf("%lld", &n);
#define sll(n, m) scanf("%lld %lld", &n, &m);
#define slll(n, m, k) scanf("%lld %lld %lld", &n, &m, &k);
#define sllll(n, m, k, o) scanf("%lld %lld %lld %lld", &n, &m, &k, &o);

#define sd(n) scanf("%lf", &n);
#define sdd(n, m) scanf("%lf %lf", &n, &m);
#define sddd(n, m, k) scanf("%lf %lf %lf", &n, &m, &k);
#define sdddd(n, m, k, o) scanf("%lf %lf %lf %lf", &n, &m, &k, &o);

#define sid(n, m) scanf("%d %lf", &n, &m);


#define scs(s) scanf("\n%s", s);
#define scss(s, ss) scanf("\n%s \n%s", s, ss);


//--------------output----------

#define pr printf
#define pri(n) printf("%d\n", n);
#define prl(n) printf("%lld\n", n);
#define prll(n, m) printf("%lld %lld\n", n, m);
#define prd(n) printf("%.10lf\n", n);
#define prs(str) printf("%s\n", str);

// ------------- BIT MANIPULATION ------------

#define CHECK(n, pos) ( (n& (1LL<<pos))>0)
#define SET(n,pos) (n | (1<<pos))
#define RESET(n,pos) (n ^ (1<<pos))
#define mem(ara, val) memset(ara, val, sizeof ara);



//--------data structures
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define pdl pair<double, ll>
#define pid pair<int, double>
#define pld pair<ll, double>

//--------others
#define SET_TIMER double timer =(double) clock();
#define PRINT_TIMER cout<<(clock()- timer)/CLOCKS_PER_SEC<<endl;
#define PRINT_LOJ_TC printf("Case %d: ", tc);
#define pb push_back
#define mp make_pair
#define log2ceil(n) ( (ll) ceil(log2(n)))
#define pow2(n) (1<<n)
#define FAST_READ ios_base::sync_with_stdio(0); cin.tie(0);



#define MX 100100
#define double long double
#define mod 1000000007
#define mod2 1000000009

vector<int> conn[MX];
int level[MX];
int par [MX] [33];
bool vis[MX];
int visCount;
int in[MX];
void dfs(int curNode, int lvl) {
    level[curNode] = lvl;
    int len = conn[curNode].size();
    vis[curNode] = true;
    in[curNode] = ++visCount;
    for(int i=0; i<len; i++) {
        if(!vis[conn[curNode] [i]]) {
            dfs(conn[curNode] [i], lvl+1);
            // par[x] [0] = curNode;

        }
    }
    // return curNode;
}


void build_lca_segment_tree_sparse_table(int n) {
//    printf("oka\n");

    // for(int i = 1; i<11; i++)
    //     printf("%d ",level[i]);
    // printf("\n");

    dfs(1, 0);
    par[1] [0] = -1;
    for(int j=1; j<30; j++) {
        for(int i=1; i<=n; i++) {
            if(par[i] [j-1] != -1)
                par[i] [j] = par[par[i] [j-1]] [j-1];
        }
    }
}


int matchLevel(int u, int v) {

    for(int i= 30; i>=0; i--) {
        if(par[u][i]!= -1 && level[par[u][i] ] >= level[v])
            u = par[u] [i];
    }
    return u;
}

int find_lca(int u, int v) {
    if(u== -1 || v==-1)
        return u+v+1;

    if(level[u] > level[v])
        u = matchLevel(u,v);
    else if(level[v] > level[u])
        v= matchLevel(v, u);

    if(u==v)
        return u;

    for(int i=30; i>=0; i--) {
        if(par[u][i] != -1 && par[v] [i]!=-1 && par[u][i] != par[v][i] )
        {
            u = par[u][i];
            v= par[v] [i];
        }
    }
    return par[u] [0];
}

void init(int n = MX-1) {
    memset(par, -1, sizeof(par));
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<=n; i++) {
        conn[i].clear();
    }
    visCount=0;

}


pii tree_min_max_in[MX<<2];
pii build_ans_segment_tree(int node, int beg, int endd, const int n) {
//    getchar();
//    printf("node %d left %d right %d\n",node,  beg, endd);
    if(beg == endd) {
        return tree_min_max_in[node] = mp(beg, beg);
    }

    int left = node<<1;
    int right = left | 1;
    int mid = (beg + endd)>>1;
//    build_ans_segment_tree(left, beg, mid);build_ans_segment_tree(right, mid+1, endd);
    pii left_del = build_ans_segment_tree(left, beg, mid, n);
    pii right_del = build_ans_segment_tree(right, mid+1, endd, n);

    tree_min_max_in[node].first = (in[left_del.first] < in[right_del.first]? left_del.first: right_del.first);
    tree_min_max_in[node].second = (in[left_del.second] > in[right_del.second]? left_del.second: right_del.second);

    return tree_min_max_in[node];


}

//struct Range{
//    int del_node;
//    int l, r;
//};

pii query_tree_min_max_in(int node, int beg, int endd, const int n, const int s, const int f) {
    if(beg >= s && endd <= f) {
//        Range range = {tree_min_max_in[node], beg, endd};
//        return range;
        return tree_min_max_in[node];
    }
    if(beg> f || endd < s){
//        Range range = {-1, -1, -1};
//        return range;
        return mp(n+1, 0);
    }

    int left = node<<1;
    int right = left | 1;
    int mid = (beg + endd)>>1;

    pii left_del = query_tree_min_max_in(left, beg, mid,n,  s, f);
    pii right_del = query_tree_min_max_in(right, mid+1, endd, n, s, f);

    pii p;

    p.first = (in[left_del.first] < in[right_del.first]? left_del.first: right_del.first);
    p.second = (in[left_del.second] > in[right_del.second]? left_del.second: right_del.second);

    return p;
}

int range_lca(int l , int r , int n) {
    pii p = query_tree_min_max_in(1, 1, n, n, l, r);
    return find_lca(p.first, p.second);
}

int main()
{
    FAST_READ


    int n, q;
    cin>>n>>q;

    in[n+1] = 1e9;

    init();

    fr(i,2, n) {
        int u;
        cin>>u;
        par[i][0] = u;
        conn[i].pb(u);
        conn[u].pb(i);
    }

    build_lca_segment_tree_sparse_table(n);

    // build_lca_segment_tree(1, 1, n);
    build_ans_segment_tree(1, 1, n, n);

    while(q--) {
        int l,r;
        cin>>l>>r;

        pii del_node = query_tree_min_max_in(1, 1, n, n, l, r);
        // cout<<"mn_in "<<del_node.first<<" max_in "<<del_node.second<<endl;
        int lll = find_lca(range_lca(l, del_node.first-1, n), range_lca(del_node.first+1, r, n));

        int rrr = find_lca(range_lca(l, del_node.second-1, n), range_lca(del_node.second+1, r, n));

        // cout<<"mn_lca "<<lll<<" mx_lca "<<rrr<<endl;
        int ans_level, ans_node;
        if(level[lll]>level[rrr]) {
            ans_node = del_node.first;
            ans_level = level[lll];
        } else {
            ans_node = del_node.second;
            ans_level = level[rrr];
        }
        cout<<ans_node<<" "<<ans_level<<endl;

    }




    return 0;
}
