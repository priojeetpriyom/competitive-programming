#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 105




int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++)
    {
        int n, p;
        cin>>n>>p;
        int cake=0, hard=0;
        int x;
        for(int i=0; i<n; i++) {
            cin>>x;
            if( x >= p/2) cake++;
            if(x<= p/10) hard++;
        }

        if(cake==1 && hard==2) {
            cout<<"yes"<<endl;
        } else cout<<"no"<<endl;


    }



    return 0;
}
