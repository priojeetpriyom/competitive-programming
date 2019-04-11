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


    int o, c;

    cin>>c>>o;
    if(o<=0 || (o==1 && c>0)) {
        cout<<"No"<<endl;
        return 0;
    }
    o--;
    c-=o;

    if(c>=0 && c%2==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;


    return 0;
}


