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


#define MXQ 100100
#define MX 100100
#define SQRT_MX ((int)sqrt(MX))
#define double long double
#define mod 1000000007
#define mod2 1000000009



struct query{
	int id, l, r;

	bool operator<(const query &b) const {
		if(l / SQRT_MX < b.l / SQRT_MX) {
			return 1;
		}
		if(l / SQRT_MX > b.l / SQRT_MX) {
			return 0;
		}
		return r < b.r;
	}
} queries[MXQ];

query cur = {-1, -1, -1};

ll ans[MXQ], ara[MX];


void add(ll val) {

}

void del(ll val){

}

ll get_ans() {

}

void mo(query q) {
	while(cur.r < q.r) {
		cur.r++;
		add(ara[cur.r]);
	}

	while(cur.r > q.r) {
		del(ara[cur.r]);
		cur.r--;
	}

	while(cur.l < q.l) {
		if(~cur.l)
			del(ara[cur.l]);
		cur.l++;
	}

	while(cur.l > q.l) {
		cur.l--;
		add(ara[cur.l]);
	}

	ans[q.id] = get_ans();
}


int main() {
    FAST_READ


	int n,q;
	cin>>n>>q;

	for1(i,n){
        cin>>ara[i];
	}

	for1(i, q) {
		queries[i].id = i;
		cin>>queries[i].l>>queries[i].r;
	}

	sort(queries+1, queries+q+1);


	for1(i, q) {
		cout<<queries[i].l<<" "<<queries[i].r<<endl;
	}

	for1(i, q) {
		mo(queries[i]);
	}

}
