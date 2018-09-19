#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int ara1[5050], ara2[5050];
vector<int> conn1[5050], conn2[5050];
int dp[5050] [5050] ;

int n,m;

int lcis(int pos1, int pos2)
{
    if(pos1 == n || pos2 == m)
    {
        return 0;
    }
    int &ret = dp[pos1] [pos2] ;
    if(ret != -1) return ret;

    ret=0;
    int x=0;
    if(ara1[pos1] == ara2[pos2] )
    {
//        printf("milse pos1 %d pos2 %d ara %d\n", pos1, pos2, ara1[pos1]);
        int len1 = conn1[pos1].size();
        int len2 = conn2[pos2].size();
        for(int i=0; i<len1; i++)
        {
            for(int j=0; j<len2; j++)
                ret = max(ret, lcis(conn1[pos1][i], conn2[pos2] [j]));
        }

//        for(int i=0; i<len; i++)
//        {
//            ret = max(ret, lcis(pos1+1, conn2[pos2] [i] ));
//        }
        if(ara1[pos1] == ara2[pos2])
            ret++;
    }
//    else
    {
        ret = max(ret, lcis(pos1, pos2+1));
        ret = max(lcis(pos1+1, pos2), ret);

    }
//    printf("pos1 %d pos2 %d ret %d\n", pos1, pos2, ret+x);
    return ret+=x;

}


int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin>>n;
    int x;
    for(int i=0; i<n; i++)
    {
        cin>>ara1[i];
    }
    cin>>m;
    for(int i=0; i<m; i++)
    {
        cin>>ara2[i];
    }



    for(int i=0; i<n; i++)
    {
        for(int j= i+1; j<n; j++)
        {
            if(ara1[j]>ara1[i])
            {
                conn1[i].push_back(j);
            }
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j= i+1; j<m; j++)
        {
            if(ara2[j]>ara2[i])
            {
                conn2[i].push_back(j);
            }
        }
    }

//    printf("n %d m %d\n", n, m);
//    for(int i=0; i<n; i++)
//    {
//        cout<<ara1[i]<<" ";
//    }cout<<endl;
//    for(int i=0; i<m; i++)
//    {
//        cout<<ara2[i]<<" ";
//    } cout<<endl;



    cout<<lcis(0, 0)<<endl;


    return 0;

}

