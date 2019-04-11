#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MX 55

struct node
{
    int val, type;
} ara[5555] ;

int len=0;
int dp[5050] [5] [5];


int rec(int pos,int last,  int cost)
{
    if(cost==3) return -1e9;
    if(pos == len) return 0;

    int & ret = dp[pos] [last] [cost];

    if(ret!= -1) return ret;
    int newCost;
    if(ara[pos].type+1 == last)
    {
        newCost = cost;
    }
    else
    {
        if(last==0)
            newCost = ara[pos].type;
        else
            newCost = cost+1;
    }
    ret = max(rec(pos+1,ara[pos].type+1,newCost)+ara[pos].val, rec(pos+1,last, cost));
//    printf("pos %d type %d cost %d ret %d\n", pos, ara[pos].type, cost, ret);
    return ret;
}



int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    string s;

    cin>>s;

    for(int i=0; i<s.size(); i++)
    {
        int cnt=1;
        ara[len].type = (s[i] == 'b');
        while(s[i] == s[i+1] && i<s.size()-1)
        {
            cnt++;
            i++;
//            printf("i %d\n", i);
        }
        ara[len++].val = cnt;
    }

//    for(int i=0; i<len; i++)
//        printf("%d ", ara[i]);
//    printf("\n");


    int mx =1;


//    for(int i= 0; i<len; i++) {
//        mx = max(mx, ara[i]+ara[i+1]+ara[i+2] - (type[i]=='b' ? ara[i+2]:0 ));
//    }

    cout<<rec(0,0, 0)<<endl;



    return 0;
}


