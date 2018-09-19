#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pll;
#define MX 1000100

string s;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin>>t;

    while(t--) {
        int a=0, b=0, prev=-1;
        cin>>s;


        for(int i=0; i<s.size(); i++) {
            if(s[i]=='A'){
                a= a +  ((s[prev] == s[i])? (i-prev):1 );
                prev = i;
            }
            else if(s[i]=='B') {
                b = b + ( (s[i] == s[prev]) ? i-prev : 1 );
                prev = i;
            } else if(!a && !b) prev=i;


        }

        cout<<a<<" "<<b<<endl;
    }


    return 0;
}

