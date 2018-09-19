/*
    IDEA: to compute all possible lis we can measure the effect of every element on the number of lis's. the effect will be all possible lis before the index of
    that number that are less than value of that index +1(the value itself is a lis). we can emplement a range sum from 1 to val[index]-1 for every position.
    comlexity: NlogN
*/


#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
ll tree[100100];
int lim=100000,ara[100100];

void update(int idx, ll val)
{
    if(val>=mod)
        val%=mod;

    while(idx<= lim)
    {
        tree[idx]+=val;
        if(tree[idx]>=mod)
            tree[idx]%=mod;
        idx += (idx & -idx);
    }
}

long long query(int idx)
{
    long long sum=0;
    while(idx!=0)
    {
        sum+= tree[idx];
        idx-= (idx & -idx);
        if(sum>=mod)
            sum%=mod;
    }
    return sum;
}



int main()
{

//    process[0]= {1,2,3};

//    cout<<process[0].id<<" "<<process[0].at<<" "<<process[0].bt<<endl;
    int t;

    scanf("%d", &t);
////    memset(ncr, -1, sizeof ncr);
//    memset(dp, -1, sizeof dp);

    int n, i;
    int sum, neg;
    int x;

    for(int tc=1; tc<=t; tc++)
    {
        sum=0, neg=0;
//        int n;
        scanf("%d", &n);
        for( i=1; i<=n; i++)
        {
            scanf("%d", &ara[i]);
//            temp[i] = ara[i];
            tree[i]=0;
        }
//        sort(temp+1, temp+n+1);
        map<int, int> mp;
        int idx=0;
        for(int i=1; i<=n; i++)
            //if(mp.find(ara[i])== mp.end())
                mp[ara[i] ] = 0;

        for(map<int, int>::iterator it = mp.begin(); it!=mp.end(); it++)
        {
            it->second = ++idx;
        }
        lim = idx;

        for(int i=1; i<=n; i++)
        {
            ara[i] = mp[ara[i]];
        }

        printf("Case %d: ", tc);

        for(int i=1; i<=n; i++)
        {
            //printf("i %d a_i %d q_i %lld\n",i, ara[i], query(ara[i]-1));
            update(ara[i], query(ara[i]-1)+1);
        }

        printf("%lld\n",query(lim));

    }


    return 0;
}
