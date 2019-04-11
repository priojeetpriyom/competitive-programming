#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node
{
    int r=0,g=0,b=0;
//    node() {
//        r=g=b=0;
//    }


};
struct node ans;

int dp[202] [202] [202];


node setNode(int r, int g, int b)
{

    node x;
    x.r=r;
    x.g  = g;
    x.b = b;

    return x;

}

void rec(node n)
{
    if(n.r<0 || n.g<0 || n.b<0) return;
    if(n.b + n.g + n.r == 1)
    {
//            printf("n.r %d n.g %d n.b %d\n", n.r, n.g, n.b);

        ans.b+= n.b;
        ans.g += n.g;
        ans.r += n.r;
        return;
    }
    int &ret =dp[n.r][n.g][n.b];
    if(ret!= -1) {
//        printf("dp returned\n");
        return;
    }

    ret =1;
    if(n.r>1)
        rec(setNode(n.r-1, n.g, n.b) );
    if(n.g>1)
        rec(setNode(n.r, n.g-1, n.b) );
    if(n.b>1)
        rec(setNode(n.r, n.g, n.b-1) );
    rec(setNode(n.r-1, n.g-1, n.b+1) );
    rec(setNode(n.r-1, n.g+1, n.b-1) );
    rec(setNode(n.r+1, n.g-1, n.b-1) );
}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);
    memset(dp, -1, sizeof dp);

    int len;
    cin>>len;
    struct node n;
    char c;
    while(len--)
    {
        cin>>c;
        if(c== 'R') n.r++;
        else if(c=='B') n.b++;
        else n.g++;
    }


    rec(n);

    cout<< ( (ans.b >= 1) ? "B":"") << ( (ans.g>=1) ? "G":"") << ( (ans.r>=1) ? "R":"") <<endl;

    return 0;
}
