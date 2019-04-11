#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myInput.txt","r", stdin);
//    freopen("myOutput.txt","w", stdout);
    int n;
    bool yes=false;
    scanf("%d",&n);
    while(n--) {
        char str[11];
        int b,a;
        scanf("\n%s %d %d",str,&b,&a);
        if(b>=2400 && b<a)
        {
            yes=true;
        }
    }
    if(yes)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
