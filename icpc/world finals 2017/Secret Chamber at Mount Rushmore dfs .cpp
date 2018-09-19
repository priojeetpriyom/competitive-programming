#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<int> conn[200];
int vis[200], possible[200] [200];


void dfs(int u, int pos)
{

    int len = conn[u].size();
    possible[pos] [u] =1;
    vis[u]=1;
    for(int i=0; i<len; i++)
    {
        if(!vis[ conn[u][i] ])
        {
            dfs(conn[u][i], pos);
        }
    }
}

bool valid(string from, string to)
{
    int len = from.size();
    for(int i=0; i<len; i++)
    {
        if(!possible[from[i] ] [to[i] ])
            return false;
    }
    return true;
}

int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin>>m>>n;
    cin.ignore();
    char u, v;
    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
//        cout<<u<<" "<<v<<endl;
        conn[u].push_back(v);
    }
    for(int i=0; i<200; i++) possible[i][i]=1;

    for(int i= 'a'; i<='z'; i++)
    {
        memset(vis, 0, sizeof vis);
        dfs(i,  i);
    }
    string from, to;

    while(n--)
    {
        cin>>from>>to;

        if(from.size()== to.size() && valid(from, to) )
            printf("yes\n");
        else printf("no\n");
    }

    return 0;

}
