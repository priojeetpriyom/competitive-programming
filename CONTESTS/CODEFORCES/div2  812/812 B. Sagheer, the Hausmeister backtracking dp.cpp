#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char str[111];
int n,m, ara[20];
int l[200], r[200];
int leftt=0, rightt=1;

int dp[22] [111] ;
int cnt;
int rec(int lights, int pos, int dir)
{
//    printf("pos %d dir %d lights %d\n", pos, dir, lights);
    if(lights == 0) return -1;

    int &ret = dp[pos] [dir] ;

    if(ret != -1) {
//        printf("dp_returned %d\n", ret);
        return ret;
    }
    if(lights-ara[pos]==0) {
//            printf("pos %d dir %d cost %d\n", pos, dir, dir==0 ? l[pos]: r[pos]);

        if(dir == leftt) {
            return l[pos];
        } else
        {
        return r[pos];

        }
    }
//     else printf("pos %d lights %d ara %d\n", pos, lights, ara[pos]);



    ret = 1e9;

    if(dir==leftt)
    {
//        if(l[pos] == 0)
//            ret = min(rec(lights-ara[pos], pos+1, rightt)+ m+1, rec(lights-ara[pos], pos+1, leftt) )+1;
//        else
            ret = min(rec(lights-ara[pos], pos+1, rightt)+ m+1, rec(lights-ara[pos], pos+1, leftt)+l[pos]*2 )+1;
    }
    else
    {
        if(r[pos] == 0)
            ret = min(rec(lights-ara[pos], pos+1, leftt)+ m+1, rec(lights-ara[pos], pos+1, rightt))+1;
        else
            ret = min(rec(lights-ara[pos], pos+1, leftt)+ m+1, rec(lights-ara[pos], pos+1, rightt)+ r[pos]*2 )+1;

    }
//    printf("pos %d dir %d ret %d\n", pos,dir, ret);
    return ret;
}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    cin>>n>>m;
    memset(dp, -1, sizeof dp);
    cin.ignore();

    for(int i=0; i<n; i++)
    {
        cin>>str;
        int pos=0;
        int x=0;
        for(int j=0; j<strlen(str); j++)
        {
            if(str[j] =='1') cnt++,pos =j, x++;
        }
        ara[n-i-1] = x;
        l[n-i-1] = pos;
        pos = m+1;

        for(int j = strlen(str)-1; j>=0; j--)
        {
//            printf(" j %d\n", j);
            if(str[j]=='1') pos=j;
        }
//            printf("1pos %d r %d l %d\n", n-i-1, pos, l[n-i-1]);
            r[n-i-1] = m+1- pos;
//            printf("2pos %d r %d l %d ara %d\n", n-i-1, r[n-i-1], l[n-i-1], ara[n-i-1]);

    }
//    int f=0;
//    for(int i=0; i<n; i++) if(l[i] || r[i]) f=1;
//    printf("cnt %d\n", cnt);
    if(cnt)
    cout<<rec(cnt, 0, 0);
    else cout<<0;
//    cout<<rec(0, 1);



    return 0;
}


