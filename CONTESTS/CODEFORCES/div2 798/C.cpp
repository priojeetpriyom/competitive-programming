#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll gcd(ll a, ll b)
{
    return (a%b==0) ? b: gcd(b, a%b);
}

ll get_gcd(ll a, ll b)
{
    if(!a || !b) return max(a,b);
    return max(gcd(a,b), -gcd(a,b));
}
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    cout<<gcd( 0,4);
    int n;
    cin>>n;

    ll ara[100100];

    for(int i=0; i<n; i++)
        scanf("%I64d", &ara[i]);
    ll ans=0;
    for(int i=0; i<n-1; i++)
    {
        while(1)
        {

            if(get_gcd(abs(ara[i]), abs(ara[i+1])) >1)
                break;
            if(i<n-2)
            {
                if(ara[i]%2==0 )
                {
//                        printf("i %d ara[i] %I64d\n",i,ara[i]);
                    break;
                }
            }
//                getchar();
//            printf("gcd %d\n", abs(gcd(ara[i], ara[i+1]) ));
            ara[i+1]+=ara[i];
            ara[i] -= (ara[i+1]-ara[i]);
            ans++;
//            printf("i %d, %I64d %I64d\n", i, ara[i], ara[i+1]);
        }
    }
    for(int i=0; i<n-1; i++)
    {
        while(1)
        {

            if(get_gcd(abs(ara[i]), abs(ara[i+1])) >1)
                break;
//                idz
//                getchar();
//            printf("gcd %d\n", abs(gcd(ara[i], ara[i+1]) ));
            ara[i+1]+=ara[i];
            ara[i] -= (ara[i+1]-ara[i]);
            ans++;
//            printf("i %d, %I64d %I64d\n", i, ara[i], ara[i+1]);
        }
    }
    for(int i=0; i<n; i++)
        printf("%I64d ", ara[i]);
    printf("\n");
    printf("YES\n%I64d\n", ans);
    return 0;
}


