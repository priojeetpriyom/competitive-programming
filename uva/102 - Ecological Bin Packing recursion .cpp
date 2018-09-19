
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node
{
    ll color[3];
} ara[10];
int vis[10], dir[10], path[10];

ll get_cost(int pos_bin, int col)
{
    ll cost=0;
    for(int i=0; i<3; i++)
    {
        if(i!= pos_bin)
            cost+= ara[i].color[col];
    }
    return cost;
}
ll ans = INT_MAX;
void rec(int pos_bin, ll val)
{
    if(pos_bin == 3)
    {
        if(val < ans)
        {
//            for(int i=0; i<3; i++)
//                printf("%d ", path[i]);
//            printf("\n");

            for(int i=0; i<3; i++)
                dir[i] = path[i];
            ans = val;
        }
        return;
    }
//    ll ret =INT_MAX, x;
    for(int i=0; i<3; i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            path[pos_bin] = i;
            rec(pos_bin+1, val+ get_cost(pos_bin, i));
//            if(x<ret) {
//                dir[pos_bin] = i;
//                ret = x;
//            }
//            ret = min(ret, );
            vis[i]=0;

        }
    }

//    return ret;
}


int main()
{
//    freopen("out.txt", "w", stdout);

    while(scanf("%d %d %d", &ara[0].color[0], &ara[0].color[2],&ara[0].color[1])==3)
    {

//        printf("oka\n");
        for(int i=1; i<3; i++)
        {
            scanf("%lld %lld %lld", &ara[i].color[0], &ara[i].color[2],&ara[i].color[1]);
        }
//        for(int i=0; i<3; i++)
//        {
//            printf("%lld %lld %lld\n", ara[i].color[0], ara[i].color[2],ara[i].color[1]);
//        }
        ans = INT_MAX;
        rec(0,0);

//        for(int i=0; i<3; i++)
//            printf("%d ", dir[i]);
//        printf("\n");

        for(int i=0; i<3; i++)
        {
//            printf("%d ", dir[i]);
            char ch;
            if(dir[i]==0) ch='B';
            else if(dir[i]==1) ch = 'C';
            else ch='G';

            printf("%c",ch);
        }
        printf(" %lld\n", ans);
    }

    return 0;
}

