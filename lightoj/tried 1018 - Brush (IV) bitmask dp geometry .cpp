#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 20

struct node
{
    int x, y;
    int sum, sub;
    vector<int> conn;
    vector<int> next_pos;
} ara[MX];

//struct node_mask
//{
//    int y, x, diag1, diag2;
//} mask_ara[MX];

int dp[1<<16+5], tc, vis[1<<16+5];
bool CHECK(int mask, int pos)
{
    return mask & (1<<pos);
}
int SET(int mask, int pos)
{
    return mask | (1<<pos);
}
int OR(int a, int b)
{
    return a|b;
}
int n, lim;

bool colinear(node a, node b, node c)
{

    return ( ( (a.x-b.x)*(b.y-c.y) ) - ( (b.x-c.x) * (a.y-b.y) )  == 0);


}


void pre()
{

    for(int i=0; i<n; i++)
    {
        ara[i].conn.clear();
        int mask_x = (1<<i), mask_y = (1<<i);
        bool flag= false;
        for(int j=0; j<n; j++)
        {
            if(j==i) continue;
            int mask_temp = (1<<i);
            for(int k=0; k<n; k++)
            {
                if(k!=i && colinear(ara[i],ara[j],ara[k]))
                {
                    mask_temp = SET(mask_temp, k);
//                    printf("i %d j %d k %d are colinear\n",i, j, k );
                }
            }
//            printf("i %d j %d mask ",i,j);
//            cout<<bitset<10>(mask_temp)<<endl;
            ara[i].conn.push_back(mask_temp);
             flag= false;
            for(int k=0; k<n; k++)
            {
                if(!CHECK(mask_temp, k))
                {
                    ara[i].next_pos.push_back(k);
                    flag = true;
                }
            }
            if(!flag)
            {
                ara[i].next_pos.push_back(0);
            }
            else flag=false;


            if(abs(ara[i].x) == abs(ara[j].x))
            {
                mask_x = SET(mask_x, j);
            }
            if(abs(ara[i].y) == abs(ara[j].y))
            {
                mask_y = SET(mask_y, j);
            }

        }
//        cout<<"mask_x "<<bitset<10>(mask_x)<<" mask_y "<<bitset<10>(mask_y)<<endl;
//        printf("ara_size %d\n", ara[i].conn.size());
        if(__builtin_popcount(mask_x)>1)
        {
            ara[i].conn.push_back(mask_x);
            for(int k=0; k<n; k++)
            {
                if(!CHECK(mask_x, k))
                {
                    ara[i].next_pos.push_back(k);
                }
            }

            if(!flag)
            {
                ara[i].next_pos.push_back(0);
            }
            else flag=false;
        }
        if(__builtin_popcount(mask_y)>1)
        {
            ara[i].conn.push_back(mask_y);
            for(int k=0; k<n; k++)
            {
                if(!CHECK(mask_y, k))
                {
                    ara[i].next_pos.push_back(k);
                }
            }
            if(!flag)
            {
                ara[i].next_pos.push_back(0);
            }
            else flag=false;
        }
//        printf("ara_size %d\n", ara[i].conn.size());
//        mask_temp=0;

    }

}

int get_pos(int mask) {

    for(int i=0; i<n; i++)
        if(!CHECK(mask, i)) return i;
    return 0;
}



int rec(int mask, int cur, int cnt=0)
{
    if(mask == lim)
        cout<<"mask "<<bitset<15>(mask)<<" cnt "<<cnt<<endl;
//    printf("mask %d\n", mask);
    if(mask == lim) return 0;

    int &ret = dp[mask];
    if( vis[mask] == tc) return ret;
    ret = 1e9;
    vis[mask] = tc;

//    for(int i=0; i<n; i++)
//    {
//        if(!CHECK(mask, i))
//        {
    int len = ara[cur].conn.size(), next=0;

    for(int j=0; j<len; j++)
    {
        int temp_mask = mask | ara[cur].conn[j];
        ret = min(ret, rec(temp_mask, ara[cur].next_pos[j], cnt+1)+1);
    }

//        }
//    }

    return ret;


}


int main()
{
//    freopen("myOut.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);  cin.tie(0);

    int t;
    scanf("%d", &t);

    for( tc=1; tc<=t; tc++)
    {
//        memset(dp, -1, sizeof dp);

        scanf("%d", &n);
        lim = (1<<n)-1;

        for(int i=0; i<n; i++)
        {
            scanf("%lld %lld",&ara[i].x, &ara[i].y);
            ara[i].sum = ara[i].x+ara[i].y;
            ara[i].sub = ara[i].x - ara[i].y;
        }
//        ara[n].y =  = 1e10;



        if(n<=2)
            printf("Case %d: %d\n",tc,  1);
        else
        {

            pre();
            int ans  = rec(0,0);
//            for(int i=0; i<n; i++) {
//                ans = rec()
//            }
            printf("Case %d: %d\n",tc,  ans );
        }

    }



    return 0;
}

