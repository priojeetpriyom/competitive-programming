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



#define MX 2000100
#define double long double
#define mod 1000000007
#define mod2 1000000009

char temp[MX/2], str[MX];
int failure[MX];

int get_max_prefix_suffix_match(int len) {
    // cout<<"len "<<len<<endl;
    // int mx=1;
    for(int i=2; i<=len; i++) {
        int j = failure[i-1];
        while(true) {
            // cout<<"j "<<j<<endl;
            if(str[i-1]==str[j] && j<len/2) {
                failure[i] = j+1;
                break;
            } else if(j==0) {
                failure[i] =0;
                break;
            }
            j = failure[j];
        }
        // mx = max(mx, failure[i]);
        // cout<<"i "<<i<<" failure "<<failure[i]<<endl;
    }
    return failure[len];
}

bool is_palindrom(int len) {

    for(int i=0; i<len/2; i++) {
//        cout<<"i "<<i<<" other "<<len-i-1<<endl;
        if(temp[i]!= temp[len-i-1])
            return false;
    }
    return true;

}

int main()
{
//    double time = clock();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

//    si(t)
    int t=1;

//    cin>>t;
    si(t);
    // getchar();
    for(int tc=1; tc<=t; tc++) {
        // for(int i=0; i<1e6; i++)
        //     temp[i] = 'a';
        //     temp[999999] = 'b';
        //     temp[1000000]= '\0';
        scs(temp);
        int len = strlen(temp);


        if(is_palindrom(len) ) {
            pr("Case %d: %d\n", tc, len);
        } else {

            for(int i = len-1; i>=0; i--)
                str[len-i-1] = temp[i];

            for(int i = 0; i<len; i++)
                str[i+len] = temp[i];

            str[len+len] = '\0';

            pr("Case %d: %d\n", tc, len+len-get_max_prefix_suffix_match(len+len));
        }
        // cout<<str<<endl;


    }
//    cout<<(clock()-time)/CLOCKS_PER_SEC;

    return 0;
}
