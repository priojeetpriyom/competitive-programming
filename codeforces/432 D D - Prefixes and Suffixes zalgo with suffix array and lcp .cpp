/*
    algo: suffix array with z-algo
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



#define MX 100100
#define double long double
#define mod 100000007
#define mod2 1000000009

void z_algo(const char s[], int lens, int z[], int offset) {
//    vector<int> z(lens);
//    for(int i=0; i<lens; i++)
//        cout<<z[i]<<" ";
//    cout<<endl;
   z[0]=lens;
//    mem(z, 0)

    for(int i=1, l=0, r=0; i<lens; i++) {
//        z[i]=0;
        if(i<=r) {
            z[i] = min(r-i+1, z[ i-l ]);
        }
                // cout<<"1i "<<i<<" z_i "<<z[i]<<" l "<<l<<" r "<<r<<endl;

        while(i+ z[i]<lens && s[offset+ z[i] ] == s[offset+ i+z[i]])
            z[i]++;

        if(i+z[i]-1 > r) {
            l = i, r = i+z[i]-1;
        }

        // cout<<"2i "<<i<<" z_i "<<z[i]<<" l "<<l<<" r "<<r<<endl;

//        cout<<"i "<<i<<" l "<<l<<" r "<<r<<" z_i "<<z[i]<<endl;
    }

//    return z;
}

int z[MX];
char str[MX];





class suf{
public:
    int idx;
    int rank1, rank2;

    void set(int i, int r1, int r2) {
        idx = i;
        rank1=r1;
        rank2 = r2;
//        cout<<"idx "<<idx<<" rank1 "<<rank1<<" rank2 "<<rank2<<endl;
    }
};

bool cmp(suf a, suf b) {
    if(a.rank1!= b.rank1)
        return a.rank1< b.rank1;
    return a.rank2 < b.rank2;
}

int RANK[100] [MX];
int power[100];
int suffixs[MX];
int step;

void build_suffix_array(char s[], int len) { //use one based indexing and lowercase letters
    // int len = s.size()-1;

    for(int i=1; i<= len; i++) {
        s[i] = tolower(s[i]);
        RANK[0] [i] = (int)(s[i]- 'a');
    }
    for(int i=0; i<31; i++)
        power[i] = 1<<i;


    step =1;

    for(int i=1; power[i-1]<len; i++, step++) {
//        cout<<" i "<<i<<endl;
        suf l[len+5];
        for(int j=1; j<=len; j++) {
            l[j].set(j, RANK[i-1][j], (j+ power[i-1]<=len ? RANK[i-1] [j+power[i-1]]: -1));
        }
//        for(int j=1; j<=len; j++) {
//            cout<<"j "<<j<<" idx "<<l[j].idx<<" rank1 "<<l[j].rank1<<" rank2 "<<l[j].rank2<<endl;
//        }

        sort(l+1, l+len+1, cmp);

        // cout<<"current_step "<<step<<endl;
        for1(j, len) {
//            cout<<" j "<<j<<" l[j].idx "<<l[j].idx<<endl;
            RANK[i][ l[j].idx ] = (j>1 && l[j].rank1 == l[j-1].rank1 && l[j].rank2 == l[j-1].rank2)? RANK[i][l[j-1].idx] : j;

        }

            // for(int j=1; j<=len; j++)
            //     cout<<RANK[step] [j]<<" ";
            // cout<<endl;

    }

    step--;

//    cout<<"step "<<step<<endl;
//    int ans[MX];
    for(int j=1; j<=len; j++)
        suffixs[RANK[step] [j]] = j;

    // for(int j=1; j<=len; j++)
    //     cout<<"suffix[j] "<<suffixs[j]<<" "<<s+suffixs[j]<<endl;




}


int lcp(int i, int j, int len) {
  // cout<<"i "<<i<<" j "<<j<<endl;
    int ret = 0;

    for (int k = step; k >= 0; k--) {
      // if(1<<k > len)
      //   continue;
        // cout<<"k "<<k<<" i "<<i<<" j "<<j<<endl;

        if (RANK[k][i] == RANK[k][j] && max(i, j)-1+(1<<k)<=len) {
            ret += 1 << k;
            i += 1 << k;
            j += 1 << k;
        }
    }
    return ret;
}

int cum[MX];

int main()
{
  SET_TIMER
   // FAST_READ
   // FRE_IN
  // FRE_IN_OUT
  //
  // for(int i=0; i<1e5; i++)
  //   cout<<'A';
  //   cout<<endl;
  // return 0;

  // cout<<"aise\naise\n";

  scs(str+1)
  // str[0]='0';
  // cout<<str+1<<endl;

  int len = strlen(str+1);

  // cout<<"input oka "<<endl;

  z_algo(str, len, z, 1);

  // cout<<"zalo done time: ";PRINT_TIMER

  // for0(i, len)
  //   cout<<z[i]<<" ";
  // cout<<endl;


  build_suffix_array(str, len);

  // int rank_by_positions[MX];
  //
  // for1(i, n)
  //   rank_by_positions[suffixs[i]] = i;

  // cout<<"step "<<step<<endl;
  // for1(i, len)
  //   cout<<RANK[step] [i]<<" ";
  // cout<<endl;


  for1(i, len) {
    // int ret = lcp(RANK[step] [1], RANK[step] [i], len);
    int ret = lcp(1, i, len);
    // cout<<"i "<<i<<" lcp "<<ret<<endl;
    cum[ret]++;
  }

  frr(i, len, 1)
    cum[i]+= cum[i+1];

  // for1(i, len)
  //   cout<<cum[i]<<" ";
  // cout<<endl;

  int cnt=0;
  frr(i, len, 1) {
    // cout<<"i "<<i<<" z[i] "<<z[i]<<" len "<<len<<endl;
    if(i+z[i-1]-1 == len) {
      cnt++;
    }
  }

  pri(cnt)

  frr(i, len, 1) {
    if(i+z[i-1]-1 == len) {
      prii(z[i-1], cum[z[i-1] ]);
    }
  }
  // PRINT_TIMER

    return 0;
}
