#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int a,b,c,d;

    cin>>a>>b>>c>>d;
int i=max(b,d);
    for(; i<=10000000; i++) {
        if((i-b)%a ==0 && (i-d)%c==0) {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}


