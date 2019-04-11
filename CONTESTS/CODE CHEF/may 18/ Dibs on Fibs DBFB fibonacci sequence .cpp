#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100
ull mod= 1e9+7;
ull A[MX], B[MX], F[MX];

int main()
{
//cout<<mod;

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);
    F[1] = F[2]=1;

    for(int i=3; i<MX; i++)
    {
        F[i] = F[i-1] + F[i-2];
//        if(F[i]>=mod)
//            F[i]-=mod;
//        if(F[i]>=mod)
//            printf("Fcked up here!");
    }
//        printf("oka");
//        printf("%lld\n", F[100000]);

    int t;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++)
    {
        ull n,m;
        scanf("%llu %llu", &m, &n);
        ll suma=0, sumb=0;
        for(int i=0; i<m; i++)
        {
            scanf("%llu", &A[i]);
            suma+= A[i];
        }
        for(int i=0; i<m; i++)
        {
            scanf("%llu", &B[i]);
            sumb+=B[i];
        }
        if(n==1)
        {
            printf("%lld\n", suma);
            continue;
        }
        else
        if(n==2)
        {
            printf("%llu\n", suma);
            continue;
        }
//         for(int i=1; i<=10; i++)
//         printf("i %d %lld\n",i,  F[i]);
        ull ans=0;
        for(int i=0; i<m; i++)
        {
            ans += (m* ((A[i] * F[n-2])%mod) );
            if(ans>=mod)
                ans%=mod;

            ans += (m* ((B[i] * F[n-1])%mod) );
            if(ans>=mod)
                ans%=mod;
        }
        printf("%llu\n", ans);

    }


    return 0;

}

