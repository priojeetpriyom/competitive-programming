#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100


unordered_set<ll> sset;
map<ll, ll> mp;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    ll n, x;

    scanf("%I64d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%I64d", &x);
        sset.insert(x);
        mp[x]=1;
    }
//    cout<<sset.size()<<endl;


    for(ll i=1; i<30; i++)
    {
        for(auto s : sset)
        {
            ll cnt=0;
            for(ll j=0; j<3; j++)
            {
                if(sset.find(s+ (j *(1LL<<i)) )!=sset.end() )
                {
                    cnt++;
                }
            }

            if(cnt==3)
            {
                printf("3\n");
                for(ll j=0; j<3; j++)
                {
                    printf("%I64d ",s+ j *(1LL<<i));

                }
                printf("\n");
                return 0;
            }

            mp[s] = max(mp[s], cnt);

//         cout<<"i "<<(1LL<<i)<<" s "<<s<<" mp "<<mp[s]<<endl;

//            cout<<"s "<<s<<" mp "<<mp[s]<<endl;
        }
    }
    ll mx=1, idx=0;
    for(auto m:mp)
    {
        if(m.second > mx)
        {
            mx = m.second;
            idx = m.first;
        }
    }
//    cout<<"mx "<<mx<< " idx "<<idx<<endl;

    if(mx==1)
    {
        for(auto s : sset)
        {
            if(sset.find(s+1 )!= sset.end())
            {
                        printf("%I64d\n",2);

                        printf("%I64d %I64d\n",s, s+1);
                return 0;
            }

        }

    }
printf("%I64d\n%I64d", mx, *sset.begin());



    return 0;
}


