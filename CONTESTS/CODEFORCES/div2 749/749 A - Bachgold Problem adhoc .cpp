#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOut.txt", "w", stdout);
    int n;
    cin>>n;
    if(n==2){

        cout<<"1\n2";
        return 0;
    }

    int ans = n/2;
    if(n %2 == 1) {

    cout<<ans<<endl<<3<<" ";

    ans--;
    }
    while(ans--) {
        cout<<2<<" ";
    }
    return 0;
}



