/*
    algo:
    idea:

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
#define prii(n, m) printf("%d %d\n", n, m);
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
#define FRE_IN_OUT FRE_IN FRE_OUT
#define FRE_IN freopen("in.txt", "r", stdin);
#define FRE_OUT freopen("out.txt", "w", stdout);

#define MX 10050
#define LVL log2ceil(MX)
#define double long double
#define mod 100000007
#define mod2 1000000009
#define inp_int(n) inline void inp( int &n ){n=0;int ch=getchar_unlocked();int sign=1;while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}while(  ch >= '0' && ch <= '9' )n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();n=n*sign;}


int subsize[MX], par[MX] [log2ceil(MX)+5], level[MX];
vector<int>conn[MX], cost[MX];

void dfs(int u, int p, int d) {

   // cost[u] = c;
   par[u][0] = p;
   subsize[u]=1;
   level[u] = d;

   for(int i=0; i<conn[u].size(); i++) {
      if(conn[u][i]!=p) {
         dfs(conn[u][i], u, d+1);
         subsize[u]+= subsize[conn[u][i] ];
      }
   }

}

int len_chains=1, len_base_ara=0;
ll base_ara[MX], base_ara_ind[MX], chain_ind[MX], chains_head[MX];
//prerequisite mem(chains_head, -1)
void hld(int u, int p, int d) {
   // if(~p)
   // cout<<"u"
   base_ara[++len_base_ara] = d;

   base_ara_ind[u] = len_base_ara;

   chain_ind[u] = len_chains;

   if(chains_head[len_chains] == -1)
      chains_head[len_chains] = u;

   int mxchild=0, pos;

   for(int i=0; i< conn[u].size(); i++) {
      int &v = conn[u][i];
      if(v!= p && subsize[v]>mxchild) {
         mxchild = subsize[v];
         pos = i;
      }
   }

   if(mxchild) {
      hld(conn[u][pos], u, cost[u][pos]);


         for(int i=0; i< conn[u].size(); i++) {
            int &v = conn[u][i];
            if(v!= p && i!= pos) {
               len_chains++;
               hld(v, u, cost[u][v]);
            }
         }
   }


}


void build_lca(int n, int lvl) {
   for(int j=1; j<=lvl; j++) {
     for(int i=1; i<=n; i++) {
         if(par[i][j-1]) {
           par[i][j] = par[par[i][j-1] ] [j-1];
         }
      }
   }
}

ll tree[MX*4];

void build_st(int node, int b, int e) {

   if(b==e) {
      tree[node] = base_ara[b];
      return ;
   }

   int l = node<<1, r = l|1;
   int mid = (b+e)>>1;

   build_st(l, b, mid); build_st(r, mid+1, e);

   tree[node] = max(tree[l], tree[r]);

}


 int get_lca(int u, int v) {

   if(level[u]< level[v])
      swap(u, v);

   int diff = level[u] - level[v];

   for(int i = log2ceil(diff); i>=0; i--) {
      if(CHECK(diff, i))
         u = par[u][i];
   }
   if(u==v)
      return u;

   for(int i = log2ceil(level[v]); i>=0; i--) {
      if(par[u][i] != par[v][i])
      {
         u = par[u][i];
         v = par[v][i];
      }
   }

   return par[u][0];

}


void update_st(int node, int b, int e,const int& pos,const int& val) {

   if(b>pos || e<pos)
      return;


   if(b == e) {
      tree[node] = val;
      return;
   }

      int l = node<<1, r = l|1;
      int mid = (b+e)>>1;
   update_st(l, b, mid, pos, val); update_st(r, mid+1, e, pos, val);

   tree[node] = max(tree[l], tree[r]);


}

ll query_st(int node, int b, int e, const int& s, const int& f) {
   if(b>f || e<s)
      return 0;
   if(b>=s && e<=f)
      return tree[node];


   int l = node<<1, r = l|1;
   int mid = (b+e)>>1;

   return max(query_st(l, b, mid, s, f), query_st(r, mid+1, r, s, f));

}

ll get_mx_till_lca(int u, int lca_node){
   ll mx = -1e18;
   while(chain_ind[u] != chain_ind[lca_node]) {
      int chain_id = chain_ind[u];
      mx = max(mx, query_st(1, 1, len_base_ara, base_ara_ind[ chains_head[chain_id] ], base_ara_ind[u] ));
      u = par[chains_head[chain_id]] [0];
   }
   if(base_ara_ind[u]<base_ara_ind[lca_node]) {
      mx = max(mx, query_st(1, 1, len_base_ara, base_ara_ind[u], base_ara_ind[lca_node] ));
   } else {
      mx = max(mx, query_st(1, 1, len_base_ara, base_ara_ind[ lca_node], base_ara_ind[u] ));
   }
   return mx;
}

ll query(int u, int v) {

   ll mx=0;
   // cout<<"aise"<<endl;
   int lca_node = get_lca(u,v);
   // cout<<"u "<<u<<" v "<<v<<" lca "<<lca_node<<endl;
   mx = max(get_mx_till_lca(u, lca_node), get_mx_till_lca(v, lca_node));

   return mx;
}

void init_hld(){
  mem(base_ara, 0);
  mem(chains_head, -1);
  // mem(chain_ind, 0);
  // mem(par, -1);
  // mem(tree, 0);
  len_base_ara=0;
  len_chains=1;
  // mem(base_ara_ind, 0);
}

vector<pii> edge_list;

int main()
{
  // SET_TIMER
   // FAST_READ
   // FRE_IN
   //FRE_OUT
  // FRE_IN_OUT

  int t;

  cin>>t;

  while(t--) {
     int n;
     getchar();

     cin>>n;

     edge_list.clear();
     init_hld();

     for1(i, n)
     {
        conn[i].clear();
        cost[i].clear();
     }


     for1(i, n-1) {
       int u,v,c;
       cin>>u>>v>>c;

       conn[u].pb(v);
       conn[v].pb(u);

       cost[u].pb(c);
       cost[v].pb(c);

       edge_list.pb(mp(u, v));
    }


       dfs(1,-1,  1);

       build_lca(n, log2ceil(n));

       hld(1, -1, 0);

       // cout<<"len_base_ara "<<len_base_ara<<endl;

       // for1(i, len_base_ara)
       //   cout<<base_ara[i]<<" ";
         // cout<<"__base_ara"<<endl;

       build_st(1, 1, n);

       // for1(i, 10)
       //   cout<<"st_"<<i<<" "<<tree[i]<<endl;


       while(1) {
          // cout<<"while1 e dhukse"<<endl;
          string s;
          // cin.ignore();
          getchar();
          cin>>s;
          // cout<<"cin pass korse s="<<s<<endl;
          if(s == "DONE")
            break;

            int u, v;
            cin>>u>>v;
            if(s == "QUERY") {
               // cout<<"query te dhukse"<<endl;
               // int l = get_lca(u, v);
               // cout<<max(query(u, l), query(v, l))<<endl;
               cout<<query(u, v)<<endl;
               // cout<<"QUERY ANS: "<<endl;
            } else {
               pii p = edge_list[u-1];
               u = (par[p.first][0]== p.second?  p.first: p.second);
               // cout<<"u "<<p.first<<" v "<<p.second<<" tobe_changed "<<u<<endl;
               update_st(1, 1, n, base_ara_ind[u], v);
            }



     }
 }



  // PRINT_TIMER

    return 0;
}
