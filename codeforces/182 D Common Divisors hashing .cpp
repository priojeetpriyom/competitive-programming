#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100
#define double long double
#define mod (ll)1e9+7

//ll hasha[MX], hashb[MX];
ll base= 257;

ull get_hash(const char s[], int from, int to) {
    ull pw=1, hash=0;
    for(int i = from; i<=to; i++) {
        hash+= pw* s[i];
        pw*=base;
    }
    return hash;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("input.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

//    for(int i=0;i<1e5; i++)
//        cout<<"a";
//    cout<<endl;
//    for(int i=0;i<1e5; i++)
//        cout<<"a";
//    cout<<endl;

    ll time = clock();
//    string a,b, temp;
    char a[MX], b[MX];
//    a = " "; b = " ";
//    cin>>temp;
//    a += temp;
//    temp.clear();
//    cout<<"oka"<<endl;
//    cin>>temp;
//    b+= temp;
//    cout<<"oka"<<endl;
//    cout<<a<<endl<<b<<endl;
    a[0]=b[0]=' ';
    scanf("\n%s \n%s", a+1, b+1);

    if(strlen(a)>strlen(b))
        swap(a, b);

    int lena = strlen(a)-1, lenb = strlen(b)-1;
//    ll pw=1;
//    for(int i=1; i<=lena; i++) {
//        hasha[i] = hasha[i-1] + pw * a[i];
//        hasha[i]%= mod;
//        pw*= base;
//        pw%=mod;
//    }
//
//    pw=1;
//    for(int i=1; i<=lenb; i++) {
//        hasha[i] = hashb[i-1] + pw * b[i];
//        pw*= base;
//        hashb[i]%= mod;
//        pw%=mod;
//    }
    vector<int> divs({1});
    int root = sqrt(lena)+1;

    for(int i=2; i<root; i++) {
        if(lena%i==0) {
            if(lenb%i==0)
             divs.push_back(i);
            if(i != lena/i && lenb%(lena/i)==0)
                divs.push_back(lena/i);
//            while(lena%i==0)
//              lena/=i;
        }
    }
    lena=strlen(a)-1;
    if(lena>1 && (lenb)%(lena)==0)
        divs.push_back(lena);

    int ans=0;
    for(auto d: divs) {
        bool aok=true, bok= true;
//        cout<<"lena d:"<<d<<endl;
        ull hash = get_hash(a, 1, d);
        for(int i=d; i<=lena; i+=d) {
            if(hash!= get_hash(a, i-d+1, i)) {
                aok=false;
                break;
            }

        }

//        hash = get_hash(b, 1, d);
        for(int i=d; i<=lenb; i+=d) {
            if(hash!= get_hash(b, i-d+1, i)) {
                bok=false;
                break;
            }

        }

        if(aok & bok)
            ans++;
//        cout<<"d "<<d<<" ans "<<ans<<endl;
    }

    cout<<ans<<endl;
//    cout<<(clock()-time)/CLOCKS_PER_SEC<<endl;

    return 0;
}
