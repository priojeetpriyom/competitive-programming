#include<bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOut.txt", "w", stdout);
    int n, m,z;
    cin>>n>>m>>z;
    int x=m,cnt=0;
    for(int i=n; i<=z; i+=n) {
        if(i%m==0) {
            cnt++;

        }
    }
    cout<<cnt;
    return 0;

}

