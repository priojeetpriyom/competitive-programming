#include <bits/stdc++.h>

using namespace std;

//typedef ll long long;

vector<int> vec[100100], cum[100100];
int mx[100100];
int main()
{
//   freopen("out.txt", "w", stdout);

    int n,m, k;

    cin>>n>>m;
    int x;
    for(int i=1; i<=n; i++)
    {
        vec[i].push_back(0);
        cum[i].push_back(0);
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%d", &x);
            vec[i].push_back(x);
            cum[i].push_back(0);
        }
    }


    for(int j=1; j<=m; j++) {
        int cnt=0;
        for(int i=2; i<=n; i++) {
            if(vec[i][j] >= vec[i-1] [j]) {
                cum[i][j] = cum[i-1] [j] +1;
            }
        }
    }

    for(int i= 1; i<=n; i++) {
        x = 0;
        for(int j=1; j<=m; j++) {
            x = max(x, cum[i][j]);
        }
        mx[i] = x;
    }

    cin>>k;

    int l, r;

    while(k--) {
        scanf("%d %d", &l, &r);
//        r--;l--;
        if(r-l <= mx[r]) {
            printf("Yes\n");
        }else
            printf("No\n");
    }



    return 0;
}
