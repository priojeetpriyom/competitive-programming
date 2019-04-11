#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 1010

int n;
ll dp[MX] [MX] [5];
int s[MX], c[MX];

int rec(int pos, int last, int left) {
		if(!left) 
			return 0;
		if(pos == n+1) {
			return 1e10;
			}
	ll& ret = dp[pos][last][left];
	if(~ret) {
		return ret;
		}
	ret = 1e10;
	
	for(int i = pos; i<=n; i++) {
		if(s[i]> s[last)) {
			ret = min(ret, rec(i+1, i, left-1)+c[i] );
		}
	
	}
	ret = min(ret, rec(i+1, pos, left);
	
		return ret;
	}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
   // std::ios_base::sync_with_stdio(false);
    //cin.tie(0);
	memset(dp,-1, sizeof dp);
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++) {
		scanf("%d", &s[i]);
	}
	for(int i=1; i<=n; i++) {
		scanf("%d", &c[i]);
	}
	
	ll ret = rec(1, 0, 3);
	if(ret>=1e9) {
		cout<<"-1"<<endl;
		}
	else
		cout<<ret<<endl;


    return 0;
}


