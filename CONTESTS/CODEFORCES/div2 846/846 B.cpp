#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
map<pair<pair<int, int>, int>, int > dp;
map<pair<pair<int, int>, int>, int > :: iterator ret;
pair<pair<int, int>, int> t;
int cost[100];

int rec(int pos, int mn, int val)
{
    if(pos>k)
    {
        printf("1 pos %d mn %d val %d returned %d\n", pos, mn, val, dp[t]);

        return mn;

    }
    printf("pos %d mn %d val %d\n", pos, mn, val);
    t = make_pair(make_pair(pos, mn), val);
//    ret = dp.find(t);
    if(dp.find(t) != dp.end()) return dp[t];
//    dp[t]=0;
    int rrr=0;
    for(int i=0; i<=n; i++)
    {
        if( (i*cost[pos]) <=val)
        {
            rrr= max(rrr, rec(pos+1, min(mn, i), val - (i* cost[pos]))+ i );
        }
    }
    printf("pos %d mn %d val %d returned %d\n", pos, mn, val, dp[t]);
    dp[t] = rrr;
    return (int)rrr;

}



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin>>n>>k>>m;
    for(int i=1; i<=k; i++)
    {
        cin>>cost[i];
    }

    cout<<rec(1, 1e9, m);



    return 0;
}


