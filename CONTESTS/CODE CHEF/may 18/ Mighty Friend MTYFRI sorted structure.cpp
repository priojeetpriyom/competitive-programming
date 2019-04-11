#include<bits/stdc++.h>

using namespace std;
typedef long long ll;




int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int t;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++)
    {
        multiset<ll> motu, tomu;
        ll n,x, k, turn=0;
        scanf("%lld %lld", &n, &k);
        for(int i=0; i<n; i++)
        {
            scanf("%lld", &x);
            if(turn^1)
                motu.insert(x);
            else
                tomu.insert(x);
            turn^=1;
//            printf("inputing i %d n %lld\n",i,n);

        }
        if(n==1)
         {
            printf("NO\n");
            continue;
         }
        ll t, m;
        while(k>0) {
            t = *(tomu.begin());
            m = *(--motu.end());
//            printf("t %")
            if(t>=m)
                break;

//            printf("k %lld\n", k);
            tomu.erase(tomu.find(4));
            printf("tomu_size %d\n", tomu.size());
            motu.erase(--motu.end());

            tomu.insert(m);
            motu.insert(t);
            k--;
        }
//        printf("oka\n");

        ll sumt=0, summ=0;


        for(auto i: tomu)
            sumt+= i;
        for(auto i: motu)
            summ+= i;

        if(sumt>summ)
            printf("YES\n");
        else
            printf("NO\n");

    }


    return 0;

}

