#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myOut.txt", "w", stdout);

    int s;
    int x1,x2;
    int d;
    int p;
    int t1,t2;
    cin>>s>>x1>>x2>>t1>>t2>>p>>d;
    int direct = abs(x1-x2)*t2;
    if(x1==x2) {
        cout<<"0";
    } else if(x1<x2) {
        if(d==1) {
            if(p > x1) {
                direct  = min(direct, (s-p)*t1 + s*t1 + x2*t1 );
            } else
                direct = min(direct, (x2 - p)*t1);
        } else {
            direct = min(direct, p*t1 + x2*t1);
        }
    }   else {
            if(d == -1) {
                if(p < x1) {
                    direct = min(direct, p*t1 + s*t1 + (s-x2)*t1 );
                }
            } else {
                direct = min(direct, (s-p)*t1 + (s-x2)*t1);
            }
    }
    cout<<direct;
    return 0;
}

