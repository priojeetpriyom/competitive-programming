#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100

vector<int> dx, dy;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

	ll x, y;
	cin>>x>>y;
	
	if(x<=10 && y<=10)  {
		ll sx=1, sy=1;
		
		for(int i=0; i<x; i++)
			sy*=y;
		
		for(int i=0; i<y; i++)
			sx*=x;
		
	if(sx==sy)
	cout<<"="<<endl;
	else if(sx>sy)
	cout<<">"<<endl;
	else
	cout<<"<"<<endl;
	return 0;
	}
	
	if(x==y)
	cout<<"="<<endl;
	else if(x==1)
	cout<<"<"<<endl;
	else if(y==1)
	cout<<">"<<endl;
	else if(x<y)
	cout<<">"<<endl;
	else
	cout<<"<"<<endl;




    return 0;
}


