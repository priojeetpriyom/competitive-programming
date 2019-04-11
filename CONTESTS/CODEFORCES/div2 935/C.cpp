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


    double center_x, center_y, fa_x, fa_y, R, r, fi_x, fi_y;


    cin>>R>>center_x>>center_y>>fa_x>>fa_y;

    double dist = sqrt( ( (center_x-fa_x) * (center_x-fa_x)  ) +  ( (center_y-fa_y) * (center_y-fa_y)));
    cout<<dist<<endl;

    if(dist>R) {
        r = R;
    } else
        r = max( ( (double)1/1e15 ), dist- ( (double)1/1e10 ));

    cout<<r<<endl;

    cout<<center_x+r<<" "<<center_y+r<< " "<<r<<endl;

    return 0;
}


