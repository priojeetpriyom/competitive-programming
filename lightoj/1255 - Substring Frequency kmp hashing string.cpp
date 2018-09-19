#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

//------------ loop macros

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)


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

#define scs(s) scanf("\n%s", s)
#define scss(s, ss) scanf("\n%s \n%s", s, ss)


//--------------output----------

#define pr printf
#define pri(n) printf("%d\n", n);

// ------------- BIT MANIPULATION ------------

#define CHECK(n, pos) ( (n& (1<<pos))>0)
#define SET(n,pos) (n | (1<<pos))
#define RESET(n,pos) (n ^ (1<<pos))



#define MX 1000100
#define double long double
#define mod 1000000007
#define mod2 1000000009

char text[MX], pattern[MX];

int failure[MX];

void build_failure(const char str[], int len) {


    for(int i=2; i<=len; i++) {
        int j = failure[i-1];
        while(true) {
            if(str[i-1] == str[j]) {
                failure[i] = j+1;
                break;
            }
            if(j==0) {
                failure[i]=0;
                break;
            }
            j = failure[j];
        }

//        cout<<"i "<<i<<" failure_i "<<failure[i]<<endl;
    }

}

int get_substring_count(char text[], char pattern[], int lent, int lenp) {
    int t=0, p=0;
    int ret=0;
    while(true) {
        if(t==lent)
            return ret;

        if(text[t] == pattern[p]) {
            t++, p++;
        }
        else if(p==0) {
            t++;
        }
        else
            p = failure[p];

        if(p==lenp) {
            ret++;
            p=failure[p];
        }


//        cout<<"p "<<p<<" t "<<t<<" ret "<<ret<<endl;
     }
}


int main()
{
//    double time = clock();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

//    si(t)
    int t;

//    cin>>t;
    si(t);

    for(int tc=1; tc<=t; tc++) {
        scss(text, pattern);
        int lenp = strlen(pattern), lent = strlen(text);
//        cout<<text<<" "<<pattern<<endl;
//        cout<<"lent "<<lent<<" lenp "<<lenp<<endl;
        build_failure(pattern, lenp);

        pr("Case %d: %d\n", tc, get_substring_count(text, pattern, lent, lenp));

    }
//    cout<<(clock()-time)/CLOCKS_PER_SEC;

    return 0;
}
