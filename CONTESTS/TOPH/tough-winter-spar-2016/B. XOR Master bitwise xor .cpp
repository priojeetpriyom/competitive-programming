#include <bits/stdc++.h>
using namespace std;

long long ara[100010], cum[100010];

int main()
{
//        freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    int n;

    while(scanf("%d", &n)==1) {
        map<long long, int>mp;
        long long x;
        for(int i=0; i<n; i++) {
            scanf("%lld", &x);
            mp[x]++;
        }

        map<long long, int>::iterator it= mp.begin();

        for(int i=1; it != mp.end(); it++) {
            ara[i++] = it->second;
        }
        cum[0]=0;
        for(int i=1; i<=n; i++) {
            cum[i] = cum[i-1]+ara[i];
        }
        long long sum=0;
        for(int i=1; i<=n; i++) {
            sum= sum+ (cum[n]-cum[i])* ara[i];
        }

        printf("%lld\n", sum);
    }

    return 0;
}







