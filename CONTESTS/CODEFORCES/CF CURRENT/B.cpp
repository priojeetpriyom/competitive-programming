#include <bits/stdc++.h>
using namespace std;

long long getSeq(long long a, long long n) {
    long long x = 2+ ((n-1));
    x = x*n;
    x/=2;
    return x;
}

int main()
{
//        freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);
    long long n,m,k;

    cin>>n>>m>>k;

    long long s =0, ans=0 ;
    for(long long i=1; ; i++) {
        s+= getSeq(i, k-1);
        s+=getSeq(i, n-k);
        s+= i+ (k-1);

        if(s>n) {
            ans = i-1;
            break;
        }
    }


//    long long ans = n / (k-1 + (n-k));

    cout<<ans;

    return 0;
}







