#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


map<string , int> mp;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    mp["Tetrahedron"] = 4;
    mp["Cube"] = 6;
    mp["Octahedron"] = 8;
    mp["Dodecahedron"] = 12;
    mp["Icosahedron"] = 20;

    int n;
    cin>>n;
    string s;
    int ans=0;
    while(n--)
    {
        cin>>s;
        ans+= mp[s];
    }
    cout<<ans;

    return 0;
}


