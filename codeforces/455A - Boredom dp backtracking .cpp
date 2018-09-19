/*
    algo:
    idea:

*/
//
//
//#include<stdio.h>
//#include<string.h>

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 100010
//#define mod 1000000007
int n;

ll ara[MX], dp[MX][3];
int mx;

ll rec(int pos, bool prev) {
	if(pos == mx+1)
		return 0;
	ll & ret = dp[pos] [prev];
	if(~ret)
		return ret;
	
	ret = max(rec(pos+1, 0), (prev)?0: (rec(pos+1, true)+ara[pos]));
	return ret;
	}



int main()
{
//freopen("output.txt", "w", stdout);

	cin>>n;
	int x;
	for(int i=0; i<n; i++)
	{
		cin>>x;
		ara[x]++;
		mx = max(mx, x);
	}
	
	for(int i=1; i<=mx; i++)
		ara[i] = i*ara[i];
	
	memset(dp, -1, sizeof dp);
	
	
	cout<<rec(1, 0)<<endl;
    
    return 0;
}

