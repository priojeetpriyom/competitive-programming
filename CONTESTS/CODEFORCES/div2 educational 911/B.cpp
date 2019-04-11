#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 15


int main()
{
//    cout<<-13%5;
//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    int n, a, b;

    cin>>n>>a>>b;

    for(int i=200; i>0; i--) {
//        printf("i %d %d\n",i, (a/i) + (b/i));
        if( (a/i) + (b/i) >=n && min(a,b)>=i)
           {
                cout<<i<<endl;
        return 0;
           }
    }






    return 0;
}

