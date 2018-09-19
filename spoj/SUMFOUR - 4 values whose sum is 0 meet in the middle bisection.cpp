//alias g++11="g++ -std=c++0x"
//this program will be accepted i fwe use binary search instead of stl map
#include <bits/stdc++.h>
#include<unordered_map>



using namespace std;
typedef long long ll;

int a[2501],b[2501],c[2501],d[2501];


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }
    unordered_map<ll, int> mp;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            mp[a[i] + b[j]]++;
        }
    }
    //vector<int>v;


    ll ans =0;


    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(mp.count(- (c[i] + d[j])))
                ans+= mp[- (c[i] + d[j])];
        }
    }
    printf("%lld\n", ans);

    return 0;
}



