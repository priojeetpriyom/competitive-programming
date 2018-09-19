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
#define prl(n) printf("%lld\n", n);
#define prll(n, m) printf("%lld %lld\n", n, m);

// ------------- BIT MANIPULATION ------------

#define CHECK(n, pos) ( (n& (1<<pos))>0)
#define SET(n,pos) (n | (1<<pos))
#define RESET(n,pos) (n ^ (1<<pos))
#define mem(ara, val) memset(ara, val, sizeof ara);


//--------others
#define SET_TIMER double timer =(double) clock();
#define PRINT_TIMER cout<<(clock()- timer)/CLOCKS_PER_SEC<<endl;





#define MX 100011
#define double long double
#define mod 1000000007
#define mod2 1000000009


int aodd, aeven, bodd, beven;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("input.txt", "w", stdout);


//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    SET_TIMER

    char str[MX];
    scs(str+1);
    int len = strlen(str+1);

//    cout<<"len "<<len<<endl;

    for(int i=1; i<=len; i++) {
        if(str[i]=='a') {
            if(i&1)
                aodd++;
            else
                aeven++;

        } else {
            if(i&1)
                bodd++;
            else
                beven++;

        }
    }

//    cout<<"aeven_size "<<aeven.size()<<" aodd_size "<<aodd.size()<<endl;
//    cout<<"beven_size "<<beven.size()<<" bodd_size "<<bodd.size()<<endl;

    ll odd=0, even=0;

    for(int i=1; i<=len; i++) {
        if(i&1) {
            if(str[i]=='a') {
//                int pos = distance(aeven.begin(), upper_bound(aeven.begin(), aeven.end(), i));
                even+= aeven;
//                pos = distance(aodd.begin(), upper_bound(aodd.begin(), aodd.end(), i));
                odd+= aodd;
                aodd--;
            } else {

//                int pos = distance(beven.begin(), upper_bound(beven.begin(), beven.end(), i));
//                cout<<"beven pos "<<pos<<endl;
                even+= beven;
//                pos = distance(bodd.begin(), upper_bound(bodd.begin(), bodd.end(), i));
//                cout<<"bodd pos "<<pos<<endl;
                odd+= bodd;
                bodd--;
            }
        } else {

            if(str[i]=='a') {
//                int pos = distance(aeven.begin(), upper_bound(aeven.begin(), aeven.end(), i));
                odd+= aeven;
//                pos = distance(aodd.begin(), upper_bound(aodd.begin(), aodd.end(), i));
                even+= aodd;
                aeven--;
            } else {

//                int pos = distance(beven.begin(), upper_bound(beven.begin(), beven.end(), i));
                odd+= beven;
//                pos = distance(bodd.begin(), upper_bound(bodd.begin(), bodd.end(), i));
                even+= (bodd);
                beven--;
            }
        }
//        cout<<"i "<<i<<" even "<<even<<" odd "<<odd<<endl;
    }

    prll(even, odd);

//    PRINT_TIMER
    return 0;
}
