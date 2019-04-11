#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n,t,k,d;
    cin>>n>>t>>k>>d;

    int ans =(int) ( ((ceil) ( (double) n/k ) ) *t);
    ans -= t;

    if(ans>d) printf("YES\n");
    else printf("NO\n");
    return 0;
}


