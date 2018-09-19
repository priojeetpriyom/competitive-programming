#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int coins [] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5}, n=11;

ll dp[30010] [11]; // visited[10010] [11], tc=1;

ll rec(int amount, int pos) {

    if(amount<=0) return amount==0;
    if(pos==n) return 0;

    ll &ret = dp[amount] [pos];
//    int &vis = visited[amount] [pos];
    if(ret != -1) return ret;
//    vis = tc;
    ret=0;
    for(int i =coins[pos]; i<= amount; i+=coins[pos]) {
        ret+= rec(amount-i, pos+1);
    }
    ret+= rec(amount, pos+1);


    return ret;


}



int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    double amount;
    int x;
    memset(dp, -1, sizeof(dp));
    while(scanf("%lf", &amount)==1 && amount!=(double)0) {
        x  =  round(amount*100);
//        printf("x %d\n", x);
        printf("%6.2lf %16lld\n",amount, rec( x,0) );
//        tc++;
    }



    return 0;

}

