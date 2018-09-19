#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 100100

//ll dp[105][MX];
int tc;
//int ara[105];
//int c[105];
double dp[MX];
//int n;
//
#define mod 100000007

int vis[MX];
int xx=1;


double rec(int n)
{
//    cout<<n<<endl;
    if(n==1)
        return 0;

    double &ret = dp[n];
//    if(ret>0)
    if(vis[n])
        return ret;
//    cout<<n<<" "<<vis[n]<<endl;
    vis[n]=1;
    int rt=sqrt(n)+1;
    vector<int> vec;
    for(int i=1; i<rt; i++)
        if(n%i==0)
        {
            vec.push_back(i);
            if(i!= n/i)
                vec.push_back(n/i);
        }

    for(int i=0; i<vec.size(); i++)
    {
        if(n != vec[i])
        ret+= rec(vec[i]);
    }

    ret=(ret+vec.size())/ max(1,(int) vec.size()-1);

    return ret;



}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t, k;
    scanf("%d", &t);
    int n;
    for(tc=1; tc<=t; tc++)
    {
        scanf("%d", &n);


        printf("Case %d: %lf\n",tc, rec(n));

    }



    return 0;
}
