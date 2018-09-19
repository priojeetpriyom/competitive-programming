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
#define MX 500010
//#define mod 1000000007
int ara[MX];

ll cnt[MX] ,sum[MX];
int main()
{
//freopen("output.txt", "w", stdout);


    int z, o;
    cin>>z>>o;
    if(o> ((z+1)*2) || z>o+1)
		{
			cout<<-1<<endl;
			return 0;
		}
		
    while(z>0 && o>0) {
		if(z==o) {
			cout<<"10";
			z--, o--;
		} 
		else if(o>z) {
			cout<<"110";
			o-=2, z-=1;
			}
		else {
			cout<<"01";
			o--, z--;
			}
	}
	
	while(z--)
		cout<<"0";
	
	while(o--)
		cout<<"1";
	
	cout<<endl;
    return 0;
}

