#include <bits/stdc++.h>
using namespace std;

int ara[10005];
int ans[10005];
int main()
{
//    freopen("myOutput.txt","w",stdout);


    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++) {
        int n,q;
        scanf("%d %d",&n,&q);

        for(int k=0; k<n; k++) {
            scanf("%d",&ara[k]);
        }

//        sort(ara,ara+n);
        memset(ans,0,sizeof(ans));
        for(int x=n-1; x>=0; x--) {
            for(int y = x-1; y>=0; y--) {
                int a= ara[x],b = ara[y];
                if(b>a)
                    swap(a,b);
                if( a!=b && a%b==0) {
                    ans[x]++;
                }
            }
        }
        for(int k=0; k<n; k++)
            printf("%d ", ans[k]);
        printf(" ans \n");
        printf("oka");
        for(int k=1; k<10001;k++)
            ans[k]+=ans[k-1];


        printf("Case %d:\n",i);
        while(q--) {
            int l,r;
            scanf("%d %d",&l,&r);
            printf("%d\n",ans[r-1] - ans[l-1]);
        }
    }

    return 0;
}
