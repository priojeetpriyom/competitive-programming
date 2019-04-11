#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MX 100100

int ara[MX];


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin>>n;
    int mxz=0,mxo=0, z=0, o=0 , toto=0, totz=0, mx=0;
    int lastz=0, lasto=0;
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;

        if(x==0) {
            z++;
            if(o)
            lasto = o;
            o=0;
            totz++;
            lastz=z;
        } else {
            o++;
            if(z)
            lastz=z;
            z=0;
            toto++;
            lasto=o;
        }

        mx = max(mx, max(lasto,o) +max(lastz,z));
    cout<<lasto<<" "<<lastz<<endl;
    }
//    cout<<mxz<<" "<<mxo<<endl;
//    cout<<totz<<" "<<toto<<endl;

//    if(n1
        cout<<max(mx, max(max(0, totz- toto) +mxo, max(0, toto- totz) +mxz))+1<<endl;
//    else
//        cout<<mxz+mxo<<endl;



    return 0;
}


