#include<bits/stdc++.h>

using namespace std;


vector<int> primes;
int len_primes;
int dp[1001] [1001];


int rec(int now, int goal) {
//    printf("now %d goal %d\n", now, goal);
    if(now == goal) return 0;

    int &ret = dp[now] [goal];

    if(ret!= -1) return ret;
    ret= 1e5;

    for(int i=0; i<len_primes; i++) {
        if(now%primes[i]==0 && now!= primes[i] && now+primes[i]<= goal)
            ret = min(ret, rec(now+primes[i], goal)+1);
    }

    return ret;
}

bool not_prime(int n) {
    for(int i=0; i<len_primes; i++)
        if(n% primes[i]==0) return true;

    return false;
}

int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int t, s,tt;
    memset(dp, -1, sizeof dp);
    cin>>t;
    primes.push_back(2);
    for(int i=3; i<=1000; i+=2) {
        int f=1;
        for(int j=2; j<i; j++) {
            if(i%j==0) {
                f=0;
                break;
            }
        }
        if(f)
            primes.push_back(i);
    }
    len_primes = primes.size();

    for(int tc=1; tc<=t; tc++) {
        scanf("%d %d", &s, &tt);

        int ans = 1e5;
        if(not_prime(s) )
            {
//                printf("rec called\n");
                ans = rec(s,tt);
            }
        else if(s == tt) ans=0;



        printf("Case %d: %d\n",tc, (ans>=1e5) ? -1 : ans);
}




    return 0;

}
