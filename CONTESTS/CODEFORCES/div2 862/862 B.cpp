#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll a, b;

int group[100100];
queue<int> Q;
vector<int> conn[100100];
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;
    scanf("%d", &n);
    for(int i=1; i<n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        conn[u].push_back(v);
        conn[v].push_back(u);
    }

    group[1] =1;
    a=1;
    Q.push(1);

    while(!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
//        printf("cur %d col %d\n", cur, group[cur]);
        int col = group[cur];
        if(col ==1) col=2;
        else col=1;
        int len = conn[cur].size();
        for(int i=0; i<len; i++)
        {
            int &v = conn[cur] [i];
            if(!group[v ])
            {
                group[v] = col;
                Q.push(v);
                if(col ==2) b++;
                else a++;
            }
        }
    }
//    printf("a %lld b %lld\n", a, b);

    printf("%lld\n", max((ll)0, (a*b)- ( (ll) n-1 )) );


    return 0;
}


