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


    int  x=0, y=0;
    int cur_side=0, new_side;

    int n, cnt=0;
    cin>>n;
    char c;
    for(int i=1; i<=n; i++) {
        cin>>c;
        if(c=='U')
            y++;
        else
            x++;
        if(x>y)
            new_side = 1;
        else if(y>x)
            new_side=2;
        else
            new_side = cur_side;
        if(cur_side!=new_side) {
            if(i!=1)
            cnt++;
            cur_side = new_side;
        }
    }

    cout<<cnt<<endl;


    return 0;
}


