#include<bits/stdc++.h>
using namespace std;

int ara[600], ans[600];

int main()
{
    int n,k;
    scanf("%d %d", &n, &k);

    for(int i=1; i<=n; i++)
        scanf("%d", &ara[i]);
//    if(n==1) {
//        printf("%d\n", k-n);
//        return 0;
//        }
    ara[0] = k;
    int sum=0;
    for(int i=1; i<=n; i++) {
        ans[i] = max(0, (k -(ara[i] + ara[i-1])));
//    printf("ans %d ara %d  ", ans[i], ara[i]);
        sum+= ans[i];
//        printf("sum %d a+a %d   ",sum , ara[i] + ara[i-1]);
        ans[i] = ara[i] + ans[i];
        ara[i] = ans[i];

//    printf("ans %d ara %d\n", ans[i], ara[i]);
    }

    printf("%d\n", sum);

    for(int i=1; i<=n; i++)
        printf("%d ",ans[i]);
    printf("\n");

    return 0;
}

