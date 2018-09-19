#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 1111
#define double long double
#define mod 1000000007
#define mod2 1000000009


ll hasht, pw, base=257;

int main()
{
//    double time = clock();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

//    memset(dp, -1, sizeof dp);

    int x,y,z,x1,y1,z1;

    cin>>x>>y>>z>>x1>>y1>>z1;
    int ara[10];

    for(int i=0; i<6; i++)
        cin>>ara[i];
    ll sum=0;
    if(y<0)
        sum+= ara[0];
    if(y>y1)
        sum+= ara[1];
    if(z<0)
        sum+= ara[2];
    if(z>z1)
        sum+= ara[3];
    if(x<0)
        sum+= ara[4];
    if(x>x1)
        sum+= ara[5];

    cout<<sum<<endl;


//    cout<<(clock()-time)/CLOCKS_PER_SEC;

    return 0;
}
