#include <bits/stdc++.h>
//#include <iostream>
using namespace std;
typedef long long ll;
int n;
int dp[1<<20], price[14][14];

int CHECK(int mask, int pos)
{
    return mask & (1<<pos);
}
int SET(int mask, int pos)
{
    return mask | (1<<pos);
}
int RESET(int mask, int pos)
{
    return mask & (~(1<<pos));
}

int calc_cost(int mask, int pos)
{
    int sum=0;
    for(int i=0; i<n; i++)
    {
        if(CHECK(mask, i))
            sum+=price[pos][i];
    }
    return sum;
}


int rec(int mask)
{
    if(mask == (1<<n)-1) return 0;
    int &ret = dp[mask];
    if(ret!= (1<<28)) return ret;

    for(int i=0; i<n; i++)
    {
        if(!CHECK(mask, i))
        {
            ret = min(ret, rec(SET(mask, i))+ calc_cost(SET(mask,i), i));
        }
    }
    return ret;
}


int main()
{
//    f reopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        cin>>n;

        for(int i=0; i< (1<<n); i++) dp[i] = (1<<28);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                scanf("%d", &price[i][j]);
        }

        printf("Case %d: %d\n",tc, rec(0));
    }

    return 0;
}





