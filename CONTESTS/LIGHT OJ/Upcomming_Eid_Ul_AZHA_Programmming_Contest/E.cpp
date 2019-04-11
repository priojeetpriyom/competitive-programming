#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOutput.txt","w",stdout);

    int tcase;
    scanf("%d",&tcase);

    for(int t=1; t<=tcase; t++) {
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        printf("case %d: ",t);
        if(n==m && n==k) {
            printf("1\n");
        }
        else if(n<=m) {
            printf("Impossible\n");
        } else {
            if(m!=0)
            printf("%d\n",k/(n-m));
            else
            printf("%d\n",k/(n-m)+1);
        }

    }

    return 0;
}


