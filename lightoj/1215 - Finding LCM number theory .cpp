//#include<bits/stdc++.h>
//
//using namespace std;
//typedef long long ll;
#include<stdio.h>
#define ll long long


ll __gcd(ll a , ll b)
{
   if(b==0) return a;
   a%=b;
   return __gcd(b,a);
}

int main()
{
//    prime_gen();
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    cout<<__gcd(5,125)<<", "<<__gcd(125,5);
    int t;
    ll a,b,lcm;
//    memset(dp, -1, sizeof dp);
    scanf("%d", &t);


    for(int tc=1; tc<=t; tc++)
    {
        scanf("%lld %lld %lld", &a, &b, &lcm);
        printf("Case %d: ",tc);

        ll lcm_ab = (a*b)/__gcd(a, b), ab= a*b;
//        ll f=0;
        if(lcm % lcm_ab ==0)
        {
//            f=1;
            if(lcm == lcm_ab) printf("1\n");
            else
            {
                lcm_ab= lcm/lcm_ab;
                ll ans=1, d= __gcd(lcm, lcm_ab);
                while(d!=1) {
                    ans*= d;
                    lcm/= d;
                    d = __gcd(lcm, lcm_ab);
                }
                printf("%lld\n", ans);
            }
        }
        else printf("impossible\n");
    }




    return 0;

}
