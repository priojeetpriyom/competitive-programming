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

    int l,r,a;

    cin>>l>>r>>a;
    int pre = 2*min(l,r);
    int left = abs(l-r);
    int more = (min(left, a)+a);
        more -= (more&1);
    cout<< pre+more;



    return 0;
}


