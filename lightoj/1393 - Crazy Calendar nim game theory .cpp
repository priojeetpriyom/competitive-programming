#include <stdio.h>


int main()
{

    int t;
    scanf("%d", &t);


    int n, m;

    for(int tc=1; tc<=t; tc++)
    {
        int ans=0;

        scanf("%d %d", &n, &m);

        int x;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&x);

                if((n-i)&1) {
                    ans ^= x;
                }

                if((m-j)&1) {
                    ans ^= x;
                }
            }


        }

        printf("Case %d: ",tc);
        if(ans) {
            printf("win\n");
        } else
            printf("lose\n");


    }



    return 0;
}
