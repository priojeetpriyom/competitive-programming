#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOutput.txt","w",stdout);

    int tcase;
    scanf("%d",&tcase);

    for(int t=1; t<=tcase; t++) {
        int a,b;
        scanf("%d %d",&a,&b);
        if(a+6>=b && a<b)
        {
            printf("Yes\n");
        } else
        printf("No\n");

    }

    return 0;
}


