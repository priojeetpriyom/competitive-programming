#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    char c;
    int t;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++)
    {
       ll a,b,c;
       scanf("%lld %lld %lld", &a, &b, &c);
       printf("Case %d: ", tc);
       if(a>b && a>c)
        swap(a,c);
       else if(b>a && b>c)
        swap(b, c);
       if(c == sqrt(a*a + b*b) )
        printf("yes\n");
       else
        printf("no\n");


    }



    return 0;
}
