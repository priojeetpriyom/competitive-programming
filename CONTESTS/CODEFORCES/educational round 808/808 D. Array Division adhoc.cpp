#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int n;

ll ara[100100], cum[100100];
//set<ll> sset[100100];
map<ll, set<ll> > mp;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        scanf("%I64d", &ara[i]);
        cum[i]+= cum[i-1] +ara[i];
        mp[ara[i]].insert(i);

    }
    set<ll> :: iterator it;

    for(int i=1; i<=n; i++)
    {
        ll x = abs(cum[i] - (cum[n]-cum[i]) );
        if(x&1) continue;
        x>>=1;
        if(mp[x].size())
        {
            {

                if(cum[i] > cum[n]-cum[i])
                {
                    it = mp[x].lower_bound(1);
                    if(it== mp[x].end() || *it >i) continue;
                }
                else if(cum[i] < cum[n]-cum[i])
                {
                    it = mp[x].end();
                    it--;
                    if(*it <= i) continue;
                }

//                printf("i %d ara_n %I64d ara_i %I64d\n", i, cum[n] ,cum[i]);
                return printf("YES\n"),0;
            }
        }
    }

    printf("NO\n");





    return 0;
}


