#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;

struct node
{
    int cur_employee, day;
};
vector<int> connection[2511];
int day[3000];
int mx, mx_day;
int vis[2511];
void bfs(int start)
{
    struct node cur, neww;
    cur.day=1;
    cur.cur_employee = start;
    queue<struct node> Q;
    Q.push(cur);
    vis[start]=1;
    while(!Q.empty())
    {
        cur = Q.front();
        Q.pop();

        int len = connection[cur.cur_employee].size();
        int &cur_em = cur.cur_employee;

        int cnt=0;

        for(int i=0; i<len; i++)
        {
            int frnd = connection[cur_em] [i];
            if(!vis[frnd])
            {
                vis[frnd] = cur.day;
//                cnt++;
                day[cur.day]++;
//                if(!vis[frnd]) {
                neww.day = cur.day+1;
                neww.cur_employee = frnd;
                Q.push(neww);
//                }
            }
        }

    }
}

int main()
{
    while(scanf("%d", &n)==1)
    {
        for(int i=0; i<n; i++)
        {
            int x,m;
            scanf("%d", &m);
            for(int j=0; j<m; j++)
            {
                scanf("%d", &x);
                connection[i].push_back(x);
            }
        }

        int q;
        scanf("%d", &q);
        while(q--)
        {
            memset(vis, 0, sizeof vis);
            memset(day, 0, sizeof day);
            int start;
            scanf("%d", &start);

            bfs(start);
            mx = mx_day  = 0;
            for(int i=1; i<=n; i++)
            {
                if(day[i]>mx)
                {
                    mx = day[i];
                    mx_day =i;
                }
            }
            if(mx == 0) printf("0\n");
            else printf("%d %d\n", mx, mx_day);
        }

        for(int i=0; i<2501; i++)
            connection[i].clear();
    }
    return 0;
}

