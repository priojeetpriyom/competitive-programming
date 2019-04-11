#include <bits/stdc++.h>
using namespace std;
//vector<int> vec;
long long ara[10], mn=INT_MAX;
void rec(long long sum, long long cost, int i) {
    if(sum%4==0) {
        mn = min(mn, cost);
        return;
    }
    if(cost>mn || sum>100)
        return;
    for( ; i<3; i++) {
        rec(sum+ (i+1), cost+ara[i],i);
        rec(sum, cost,i+1);
    }
}
int main()
{
//    freopen("myOut.txt", "w", stdout);

    long long n;
    cin>>n>>ara[0]>>ara[1]>>ara[2];
    rec(n%4, 0, 0);
    cout<<mn;
    return 0;
}
