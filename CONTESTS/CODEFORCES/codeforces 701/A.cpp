
#include <bits/stdc++.h>

using namespace std;

int main ()
{
//    freopen("input.txt","r",stdin);
    int ara[2] [102];
    int n;
    scanf("%d",&n);
//    n+=n;
    for(int i=1; i<=n;i++)
        {
            scanf("%d",&ara[0][i]);
            ara[1][i]=i;
        }

    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(ara[0][i]>ara[0][j])
            {
                swap(ara[0][i],ara[0][j]);
                swap(ara[1][i],ara[1][j]);
            }
        }
    }

//    for(int i=1; i<=n;i++)
//        printf("%d ",ara[0][i]);
//    printf("\n");

    for(int i=1; i<=n/2;i++) {
        printf("%d %d\n",ara[1][i],ara[1][n-i+1]);
    }
    return 0;
}


