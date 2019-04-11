#include<bits/stdc++.h>

using namespace std;
typedef long long ll;




int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++)
    {
        ll n,x,ans=0;
        scanf("%lld", &n);
        for(int i=0; i<n; i++)
        {
            scanf("%lld", &x);
            ans^= (x+x);
        }
        printf("%lld\n", ans);
    }


    return 0;

}

