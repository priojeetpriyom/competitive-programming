#include <stdio.h>

int main()
{

    int t;
    scanf("%d", &t);

    int n, x;


    for(int tc=1; tc<=t; tc++)
    {

        int ans=0;
        scanf("%d", &n);
        int allOne = true, odd  = (n&1);

        for(int i=1; i<=n; i++) {
            scanf("%d", &x);
            if(x!=1)
                allOne =false;
            ans^=x;
        }

        printf("Case %d: ",tc);
        if( (ans && !allOne) || (allOne && (!odd))) {
            printf("Alice\n");
        } else
            printf("Bob\n");


    }



    return 0;
}

