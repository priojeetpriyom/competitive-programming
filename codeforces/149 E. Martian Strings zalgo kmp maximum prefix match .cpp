#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

//------------ loop macros

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define fr(i,start, till) for(int i=start; i<=till; i++)


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


#define scs(s) scanf("\n%s", s)
#define scss(s, ss) scanf("\n%s \n%s", s, ss)


//--------------output----------

#define pr printf
#define pri(n) printf("%d\n", n);
#define prl(n) printf("%lld\n", n);
#define prll(n, m) printf("%lld %lld\n", n, m);
#define prd(n) printf("%lf\n", n);
#define prs(str) printf("%s\n", str);

// ------------- BIT MANIPULATION ------------

#define CHECK(n, pos) ( (n& (1<<pos))>0)
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





#define MX 201100
#define double long double
#define mod 1000000007
#define mod2 1000000009



int pref[1005], suf[1005];
int sufz[MX], prefz[MX];


void get_match(const char s[], int lens, int z[], int offset, bool is_prefix) {
//    vector<int> z(lens);
//    for(int i=0; i<lens; i++)
//        cout<<z[i]<<" ";
//    cout<<endl;
//    z[0]=0;
//    mem(z, 0)
    for(int i=1, l=0, r=0; i<lens; i++) {
//        z[i]=0;
        if(i<=r) {
            z[i] = min(r-i+1, z[ i-l ]);
        }

        while(i+ z[i]<lens && s[z[i] ] == s[i+z[i]])
            z[i]++;

        if(i+z[i]-1 > r) {
            l = i, r = i+z[i]-1;
        }
        if(z[i] && i>offset) {
            if(is_prefix) {
                if(pref[prefz[i] ]==-1) {
                    pref[prefz[i] ] = i- offset-1;
                }
            } else if(suf[sufz[i] ] ==-1) {
                suf[sufz[i] ] = lens- i -1;
            }
        }

//        cout<<"i "<<i<<" l "<<l<<" r "<<r<<" z_i "<<z[i]<<endl;
    }

//    return z;
}

void build_prefix_array(const char s[], int lenp, int lens) {
    memset(pref, -1, sizeof pref);
    memset(prefz, 0, sizeof prefz);
    get_match(s, lens, prefz, lenp, true);

//    cout<<"prefix z"<<endl;
//    for(int i = 0; i<z.size(); i++)
//        cout<<z[i]<<" ";
//    cout<<endl;

//    exit(0);
//    int *z = pref;

//    for(int i=lenp+1; i<lens; i++) {
//        if(pref[prefz[i] ]==-1 && prefz[i]) {
//            pref[prefz[i] ] = i- lenp-1;
//        }
//    }

//    for(int i=lenp; i>=0; i--) {
//        if(pref[i+1]!= -1){
//            if(pref[i]==-1)
//                pref[i] = pref[i+1];
//            else
//                pref[i] = min(pref[i], pref[i+1]);
//        }
//    }

//    for(int i=0; i<z.size(); i++)
//        cout<<pref[i]<<" ";
//    cout<<endl;
}

void build_suffix_array(const char s[], int lenp, int lens) {
    memset(suf, -1, sizeof suf);
    memset(sufz, 0, sizeof sufz);
    get_match(s, lens, sufz, lenp, false);

//    int *z = sufz;

//    cout<<"suffix z"<<endl;
//    for0(i, z.size())
//        cout<<z[i]<<" ";
//    cout<<endl;

//    for(int i=lenp+1; i<lens; i++) {
//        if(sufz[i] && suf[sufz[i] ] ==-1) {
//            suf[sufz[i] ] = lens- i -1;
//        }
//    }
//    for(int i=lenp; i>=0; i--) {
//        if(suf[i+1]!= -1){
//            if(suf[i]==-1)
//                suf[i] = suf[i+1];
//            else
//                suf[i] = max(suf[i], suf[i+1]);
//        }
//    }


//    for(int i=0; i<z.size(); i++)
//        cout<<suf[i]<<" ";
//    cout<<endl;
}




//string text,s,  pat;
//stringstream ss;
char  text[MX],rtext[MX], pat[MX], s[MX];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("input.txt", "w", stdout);


//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    SET_TIMER


//    for(int i=0; i<1e5; i++)
//        cout<<"A";
//    cout<<endl;
//
//    cout<<"1000"<<endl;
//
//    for(int i=0; i<100; i++) {
//        for(int j=0; j<1000; j++) {
//            cout<<"B";
//        }
//        cout<<endl;
//    }
//    exit(0);













    int m;

//    cin>>text>>m;
    scs(text);
//    scs(temp);
//    text = temp;
//    cout<<text<<" "<<m<<endl;
    si(m);


    int lens, lenp, lent;
    lent = strlen(text);




    for(int i=0; i<lent; i++)
        rtext[i] = text[lent-i-1];
    rtext[lent] = '\0';

    int ans=0;
//    for(int i=0; i< lens; i++)
//        temp
    while(m--) {
//        cin>>pat;
        scs(pat);
//        scs(temp);
//        pat = temp;
//        cout<<inp<<endl;
        lenp = strlen(pat);
        if(lenp==1)
            continue;
//        cout<<"Text "<<text<<" Pattern "<<pat<<endl;
//        cout<<"pattern "<<pat<<" len "<<lenp<<endl;


        for(int i=0; i<lenp; i++)
            s[i] = pat[i];
        s[lenp] = '$';

        for(int i=0; i<lent; i++)
            s[i+lenp+1] = text[i];
        s[lent+lenp+1] = '\0';

        lens = strlen(s);
        assert(lens<=1e5+1e3+1);

//        for(int i=0; i<lens; i++)
//        {
//            pref[i]= suf[i]=0;
//        }


//        cout<<"S "<<s<<" size "<<lens<<endl;
        build_prefix_array(s, lenp, lens);


//        reverse(pat.begin(), pat.end());
//        reverse(text.begin(), text.end());

//        cout<<"reverse_pat "<<pat<<endl;
//        cout<<"reverse_text "<<text<<endl;

//        ss.str("");
//        ss<< pat << "$" << text;
//        s = ss.str();

//        reverse(text.begin(), text.end());

//        for(int i=0; i<(lenp>>1); i++)
//            swap(s[i], s[lenp-i-1]);
        for(int i=0; i<lenp; i++)
            s[i]= pat[lenp-i-1];
//        s[lenp] = '$';

        for(int i=0; i< lent; i++)
            s[lenp+1 + i]= rtext[i];
//        s[lent+lenp+1] = '\0';

//        lens = strlen(s);
//        cout<<"S "<<s<<" size "<<lens<<endl;

//        cout<<"S "<<s<<" size "<<s.size()<<endl;
        build_suffix_array(s, lenp , lens);



        for(int i=lenp; i>=0; i--) {
            if(suf[i+1]!= -1){
                if(suf[i]==-1)
                    suf[i] = suf[i+1];
                else
                    suf[i] = max(suf[i], suf[i+1]);
            }

            if(pref[i+1]!= -1){
                if(pref[i]==-1)
                    pref[i] = pref[i+1];
                else
                    pref[i] = min(pref[i], pref[i+1]);
            }
        }



        if(suf[lenp]!=-1 || pref[lenp]!= -1) {
            ans++;
//            continue;
        }
        else
            for(int i=1; i<lenp; i++) {
//                cout<<"i "<<i<<" lenp "<<lenp<<"  pref_i "<<pref[i]<<" suf_lenp-i "<<suf[lenp-i]<<endl;
                if(pref[i]!= -1 && suf[lenp-i]!= -1 && pref[i]+ lenp -1 <= suf[lenp-i])  {
//                    cout<<"GOT i "<<i<<" pref_i "<<pref[i]<<" suf_lenp-i "<<suf[lenp-i]<<endl;
                    ans++;
                    break;
                }
            }
//        cout<<"pat "<<pat<<" ANS "<<ans<<endl;
    }

//    cout<<ans<<endl;
    pri(ans);

//    PRINT_TIMER
}
