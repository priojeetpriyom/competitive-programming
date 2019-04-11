#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MX 555

struct node
{


    int val, r, c;
    node(int v, int rr, int cc)
    {
        val = v;
        r= rr;
        c = cc;
    }
};


bool cmp(node a, node b)
{

    return a.val < b.val;

}

int ara[MX][MX];
int ans[MX][MX];
vector<node> vec;

pair<int, int> get_min(int r, int c) {

    int mn = 1e9;
    int retr=r, retc=c;

    if(ara[r-1][c]< mn) {
//            ara[r][c]++;
            mn = ara[r-1][c];
            retr = r-1;
            retc = c;
//            ara[r-1][c]=0;
        }
        if(ara[r-1][c+1]) {
            mn = ara[r-1][c+1];
            retr = r-1;
            retc = c+1;
//            ara[r-1][c+1]=0;
        }
        if(ara[r][c+1]) {
            mn = ara[r][c+1];
            retr = r;
            retc = c+1;
        }
        if(ara[r+1][c+1]) {
            mn = ara[r+1][c+1];
            retr = r+1;
            retc = c+1;
        }
        if(ara[r+1][c]) {
            mn = ara[r+1][c];
            retr = r+1;
            retc = c;
        }
        if(ara[r+1][c-1]) {
            mn = ara[r+1][c-1];
            retr = r+1;
            retc = c-1;
        }
        if(ara[r][c-1]) {
            mn = ara[r][c-1];
            retr = r;
            retc = c-1;
        }
        if(ara[r-1][c-1]) {
            mn = ara[r-1][c+1];
            retr = r-1;
            retc =-1;
        }
    return make_pair(retr, retc);

}
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n, m;

    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>ara[i][j];
            vec.push_back(node(ara[i][j], i,j));
            ans[i][j]=1;
        }

    }

    sort(vec.begin(), vec.end(), cmp);


    for(int i=0; i<vec.size(); i++) {
        int r = vec[i].r;
        int c = vec[i].c;
        if(ans[r-1][c]) {
            ans[r][c]++;
            ans[r-1][c]--;
//            ans[r-1][c]=0;
        }
        if(ans[r-1][c+1]) {
            ans[r][c]++;
            ans[r-1][c+1]--;
//            ans[r-1][c+1]=0;
        }
        if(ans[r][c+1]) {
            ans[r][c]++;
            ans[r][c+1]--;
//            ans[r][c+1]=0;
        }
        if(ans[r+1][c+1]) {
            ans[r][c]++;
            ans[r+1][c+1]--;
//            ans[r+1][c+1]=0;
        }
        if(ans[r+1][c]) {
            ans[r][c]++;
            ans[r+1][c]--;
//            ans[r+1][c]=0;
        }
        if(ans[r+1][c-1]) {
            ans[r][c]++;
            ans[r+1][c-1]--;
//            ans[r+1][c-1]=0;
        }
        if(ans[r][c-1]) {
            ans[r][c]++;
            ans[r][c-1]--;
//            ans[r][c-1]=0;
        }
        if(ans[r-1][c-1]) {
            ans[r][c]++;
            ans[r-1][c-1]--;
//            ans[r-1][c-1]=0;
        }

    }


    printf("aise\n");


    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(ans[i][j]) {

                pair<int, int>p = get_min(i, j);
                int curr, curc;
                while(p.first!= i || p. second != j) {


                    ans[p.first] [p.second] += ans[i][j];
                    ans[i][j]=0;
                    p = get_min(p.first, p.second);
                }

            }
        }
    }


    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }




    return 0;
}


