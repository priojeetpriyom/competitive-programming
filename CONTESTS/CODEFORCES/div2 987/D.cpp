#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

	double n, m;
	cin>>n>>m;
	cout<<pow(n, 1/n)<<endl;
	cout<<pow(m, 1/m);
	
	cout<<" "<<pow(n, 1/n) - pow(m, 1/m);



    return 0;
}


