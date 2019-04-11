#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 105

int dp [MX] [MX];
int n, ara[MX], even[MX], odd[MX];

bool is_possible(int pos,int i) {
  return (odd[i]- odd[pos-1])== (even[i] - even[pos-1]); // && (odd[n]- odd[i])== (even[n] - even[i]);
}

 int rec(int pos, int left) {
   if(pos >n )
    return 0;
   int &ret = dp[pos] [left];

   if(~ret)
    return ret;
    ret=0;
   for(int i = pos+1; i<n; i++) {
     if(abs(ara[i] - ara[i+1])>left)
        continue;
    if(is_possible(pos, i))
      ret = max(ret, rec(i+1, left - abs(ara[i] - ara[i+1]))+1);
   }

   return ret;

 }


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof dp);
    int b;
    cin>>n>>b;
    for(int i=1; i<=n; i++) {
      cin>>ara[i];
      if(ara[i]%2==1)
        odd[i]=1;
        else
        even[i]=1;
    }
    for(int i=1; i<=n; i++) {
      odd[i]+= odd[i-1];
      even[i]+=even[i-1];
    }

    cout<<rec(1, b)<<endl;

    return 0;
}
