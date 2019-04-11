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

	map<string, string> mp;
	
	mp["purple"]  = "Power";
	mp["green"]  = "Time";
	mp["blue"]  = "Space";
	mp["orange"]  = "Soul";
	mp["red"]  = "Reality";
	mp["yellow"]  = "Mind";
	
	int n;
	cin>>n;
	cout<<6-n<<endl;
	string ss;
	
	while(n--)
	{
		cin>>ss;
		mp.erase(mp.find(ss));
	}
	
	
	for(map<string, string>::iterator m=mp.begin(); m!=mp.end(); m++) {
	{
		string s = m->second;
		s[0] = toupper(s[0]);
		cout<<s<<endl;
	}
	
}


    return 0;
}


