#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll pw[100100];

int bin(int low, int high, ll val) {

    int mid = (high+low)>>1;

    while(low<high) {
        mid = (high+low)>>1;
        if(pw[mid] ==val)
            return mid;
        if(pw[mid]<val)
            low = mid+1;
        else high = mid-1;



    }
    if(pw[low]>val) low--;

    return low;



}


//unordered_map<ll, ll> mp;
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    for(ll i=1; i<=100002; i++) {
        pw[i] = i*i;
    }

    scanf("%d", &t);
    ll val;
    while(t--) {
        int ans=0;
        scanf("%lld", &val);
        int diff = min(700LL, val-1);
        for(int i=1; i<=diff; i++) {
//            if(mp[val])
            ans+=bin(1,sqrt(val-i)+1, val-i);
        }
        printf("%d\n", ans);
    }



    return 0;
}


