#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
int dp[40000] [55], ara[40000];




int rec(int pos, int box) {


    if(pos == n+1) {
        if(!box) return 0;
        else return -1e9;
    }
    if(box<=0) return -1e9;

    int &ret = dp[pos] [box];
    if(ret != -2e9) return ret;


    set<int> sset;
    for(int i=pos; i<=n; i++)
    {
        sset.insert(ara[i]);

        ret = max(ret, rec(i+1, box-1)+(int)sset.size());



    }

    return ret;


}




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    scanf("%d %d", &n, &k);

    for(int i=1; i<=n; i++)
        scanf("%d", &ara[i]);

    for(int i=1; i<=n; i++)
        for(int j=0; j<=k; j++)
            dp[i][j] = -2e9;

    printf("%d\n", rec(1, k));


    return 0;
}


