#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 60

int dist[105] [105];
int main()
{


    int x, y;
    int n=100;
    int tc=1;
    int mp[105] = {0};
    while(scanf("%d %d", &x, &y)==2)
    {
        if(x==0) break;
        for(int i=1; i<=n; i++)
        {
            for( int j=1; j<=n; j++)
                if(i!= j)
                    dist[i][j] = (1<<10);
        }
        n=2;
        memset(mp, 0, sizeof mp);
        mp[x]=1;
        x=1;
        mp[y]=2;
        y=2;
        dist[x][y]=1;
        while(x!=0)
        {
            scanf("%d %d", &x, &y);
            if(x==0) break;
            if(!mp[x])
                mp[x] = ++n;
            x = mp[x];
            if(!mp[y])
                mp[y] = ++n;
            y = mp[y];
            dist[x][y]=1;
            //n = max(n, max(x, y));
        }

        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(dist[i][k]+dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
        double ans=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(dist[i][j] != (1<<10) )
                {
                    ans+= dist[i][j];
                }
                //printf("i %d j %d dist %d\n", i, j, dist[i][j]);
            }
        }
//        cout<<ans/(n*(n-1))<<endl;
//        printf("nnn %d\n", n);
//        printf("ans %lf n %d\n", ans, n);

        printf("Case %d: average length between pages = %0.3lf clicks\n",tc++, ans/ (double)(n *(n-1)));
    }



    return 0;
}
