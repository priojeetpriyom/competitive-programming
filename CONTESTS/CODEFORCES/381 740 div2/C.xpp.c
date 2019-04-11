#include <bits/stdc++.h>
using namespace std;

vector < vector<pair<int,int> > > query[100010];
int ara[100010];
int main()
{
//    freopen("myOut.txt", "w", stdout);
    memset(ara, -1, sizeof(ara));
    int n,m, ans=INT_MIN;
    int mx=1;
    scanf("%d %d", &n, &m);
    int l,r;
    for(int i=0; i<m; i++) {
        scanf("%d %d", &l, &r);
        ans = min(ans , (r-l)+1);
        if(l==r)
        {
            ara[l] = 0;
        }
        else
        {
            mx = max(mx, r-l);
            query(r-l).push_back(make_pair(l-1,r-1));
        }
    }

    for(int i=1; i<=mx; i++) {
        int len = query[i].size();
        for(int j=0; j< len; j++) {
            l = query[i][j].first;
            r = qury[i][j].second;
            int temp =-1;
            for(int k =l; k<=r; k++) {
                temp = max(ara[k], temp);
            }
            temp++;
            for(int k =l; k<=r; k++) {
                if(ara[k] == -1)
                {
                    ara[k] = temp++;
                }
            }
        }
    }

    printf("%d\n",ans);
    for(int i=0; i<n; i++)
        printf("%d ", ara[i]);
    return 0;
}
