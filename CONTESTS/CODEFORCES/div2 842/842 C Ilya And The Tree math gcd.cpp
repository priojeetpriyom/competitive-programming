#include <bits/stdc++.h>

using namespace std;
typedef long long ll;




vector<int> conn[200100];
int val[200100], vis[200100], ans[200100];
map<int, int > mp;


map<int, int > :: iterator it;
void count_it(int n)
{

    for(it = mp.begin(); it!= mp.end(); it++)
        if(n % it->first ==0)
            it->second = (it->second) + 1;


}
void discount_it(int n)
{

    for(it = mp.begin(); it!= mp.end(); it++)
        if(n % it->first ==0)
            it->second--;


}
int get_ans(int cnt)
{

    int ans=1;
    for(it = mp.begin(); it!= mp.end(); it++)
        if( abs(it->second -cnt) <=1)
            ans = max(ans, it->first);
    return ans;
}
int get_ans_before(int cnt)
{
    int ans=1;
    for(it = mp.begin(); it!= mp.end(); it++)
        if( abs(it->second -cnt) ==1)
            ans = max(ans, it->first);
    return ans;


}
//print(int n) {
//    printf("%d-> ", n);
//
//    for(it = mp.begin(); it!= mp.end(); it++)
//        printf("%d-%d ", it->first, it->second);
//    printf("\n");
//
//
//}

void dfs(int u, int cnt)
{

    vis[u]=1;
//    print(1);
    if(u!= 1) ans[u] = max(ans[u], get_ans_before(cnt) );
//    printf("1 u %d ans %d\n", u, ans[u]);
    count_it(val[u]);
    int len = conn[u].size();

//    print(2);
    if(u!= 1)
        ans[u] = max(ans[u], get_ans(cnt) );
//    printf("2 u %d ans %d\n", u, ans[u]);
    for(int i=0; i<len; i++)
    {
        if(!vis[conn[u][i] ])
            dfs(conn[u][i], cnt+1);
    }


    discount_it(val[u]);



}

void pre(int u, int vall)
{
//    printf("pre u %d val %d\n", u, vall);
    int x = __gcd(val[u], vall);
    ans[u] = x;
    vis[u]=1;
    int len = conn[u].size();

    for(int v=0; v<len; v++)
        if(!vis[conn[u][v] ])
            pre(conn[u][v], x);

}

void set_divs(int n)
{

    int root=  sqrt(n)+1;

    for(int i=1; i< root; i++)
        if(n%i==0)
            mp[i]=0, mp[n/i]=0;


}




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);


    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        scanf("%d", &val[i]);

    int u, v;
    for(int i=1; i<n; i++ )
    {
        scanf("%d %d", &u, &v);
        conn[u].push_back(v);
        conn[v].push_back(u);


    }

    ans[1] = val[1];
    vis[1]=1;
    for(int i=0; i<conn[1].size(); i++)
        pre(conn[1][i],0);

//    for(int i=1; i<=n; i++)
//        printf("%d ", ans[i]);
//    printf("\n");



    memset(vis, 0, sizeof vis);
    set_divs(ans[1]);
    dfs(1, 1);

    for(int i=1; i<=n; i++)
        printf("%d ", ans[i]);
    printf("\n");




    return 0;
}


