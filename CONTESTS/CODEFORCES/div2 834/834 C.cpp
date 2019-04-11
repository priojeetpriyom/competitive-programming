#include <bits/stdc++.h>

using namespace std;
typedef long long ll;






map <ll, ll> pre;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    for(ll i=1; i<=1000005; i++)
        pre[i*i*i] = i;

    int n;
    scanf("%I64d", &n);
    ll a,b;
    while(n--)
    {
        scanf("%I64d %I64d", &a, &b);
        ll temp = a*b;
        if(pre.find(temp) != pre.end()) temp = pre[temp];
        else temp= -1;
        if(temp!= -1 && a%temp==0 && b % temp==0) printf("Yes\n");
        else printf("No\n");


    }





    return 0;
}


