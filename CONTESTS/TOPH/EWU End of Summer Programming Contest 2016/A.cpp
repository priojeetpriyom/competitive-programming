#include <bits/stdc++.h>
using namespace std;



int main()
{
//    freopen("myOutput.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        if(b>a)
            swap(a,b);
        printf("Case %d: ",i);
        printf("%d%d\n",a+b,a-b );
    }
    return 0;
}
