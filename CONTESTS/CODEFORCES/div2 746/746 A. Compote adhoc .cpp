#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myOut.txt", "w", stdout);
    int a,b,c;
    cin>>a>>b>>c;
//    if(a==1)
//        a++;
    int mn =INT_MAX;
    mn = min(mn, a);
    mn = min(mn, b/2);
    mn = min(mn, c/4);

    mn+= (mn*2) + (mn*4);
    printf("%d\n", mn);
    return 0;
}


