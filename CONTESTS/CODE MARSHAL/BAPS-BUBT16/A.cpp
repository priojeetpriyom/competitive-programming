#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myInput.txt","r",stdin);
//    freopen("myOutput.txt","w",stdout);

    int tcase;
    scanf("%d",&tcase);

    for(int t=1; t<=tcase; t++) {
        int k,n;
        scanf("%d %d",&k,&n);
        printf("Case %d:\n",t);
        if(k==0) {
            printf("%d\n%d\n%d\n",n/3,((n*4)/9), ((n*2)/9));
        } else {
            printf("%d\n%d\n%d\n",((n*3)/2),n*2,((n*9)/2));
        }

    }

    return 0;
}


