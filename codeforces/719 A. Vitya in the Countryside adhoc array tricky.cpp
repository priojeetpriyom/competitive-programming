#include <bits/stdc++.h>
using namespace std;


int ara[100];
int main()
{
//    freopen("myInput.txt","r",stdin);
//    freopen("myOutput.txt","w",stdout);

    int tcase;
    scanf("%d",&tcase);

    for(int t=1; t<=tcase; t++) {
        scanf("%d",&ara[t-1]);


    }
    if(ara[tcase-1] == 0)
        printf("UP\n");
    else if(ara[tcase-1] == 15)
        printf("DOWN\n");
    else if(tcase==1)
        printf("-1\n");
    else if(((ara[tcase-1]>ara[tcase-2]))) {
        printf("UP\n");
//        printf("%d %d\n",ara[tcase-2],ara[tcase]);
    } else
            printf("DOWN\n");

    return 0;
}


