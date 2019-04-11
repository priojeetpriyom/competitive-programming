#include <bits/stdc++.h>
//#include <iostream>
using namespace std;
typedef long long ll;



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        ll r, c, ans=0;
        scanf("%lld %lld",&r, &c);
        while(r>0 && c>0) {
            ans = ans + ((r*c) *15);
            r--;c--;
        }
        printf("Case %d: %lld\n",tc, ans);


    }

    return 0;
}




