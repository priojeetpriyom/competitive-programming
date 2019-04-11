#include <bits/stdc++.h>

using namespace std;


int main ()
{

    int x,t;
    int total;
    scanf("%d",&t);
    for(int i=1; i<=t; i++) {
        total=0;
        for(int k=0; k<4; k++)
        {
            scanf("%d",&x);
            total+=x;
        }
        printf("Case %d: ",i);

        if(total>=10000) {
            total = (total) - ((total*2)/10);
        }
        else if(total>=7500) {
            total = (total) - (total/10);
        }

        printf("%d\n",total);
    }
    return 0;
}


