#include <bits/stdc++.h>
using namespace std;
int ara[100],cnt[100];
int n,k,x;
void possible(int i, int sum) {
    if(sum==k)
    {
        x=1;
        return;
    }
    if(sum>k || i==n)
        return;
//    printf("ara[i] %d cnt %d sum %d\n",ara[i],cnt[i],sum);
//    for(; i<n; i++)
        if(cnt[i]<2)
    {
        cnt[i]++;
        possible(i,sum+ara[i]);
        cnt[i]--;
    }
        possible(i+1,sum);
//            return true;
//    }
}

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int t;
    scanf("%d",&t);

    for(int tcase=1; tcase<=t; tcase++) {

        scanf("%d %d",&n,&k);
//        n*=2;
        for(int i=0; i<n; i++) {
            scanf("%d",&ara[i]);
            cnt[i]=0;
        }
        printf("Case %d: ",tcase);
        x=0;
        possible(0,0);
        if(x==1)
            printf("Yes\n");
        else
            printf("No\n");
    }


    return 0;
}
