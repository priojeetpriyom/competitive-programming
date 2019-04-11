#include <bits/stdc++.h>
using namespace std;
int ara[50010], ans1[50010], ans2[50010];
map<int,bool> mp;
int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int n,x;
    scanf("%d",&n);

    for(int i=0; i<n; i++){

        scanf("%d",&ara[i]);
        mp[ara[i]] =1;
    }

    sort(ara, ara+n);

    for(int i=n-1; i>=0; i--) {
//        scanf("%d",&x);
//    printf("%d => ",ara[i]);
        x = ara[i];
        int last=x;
        while(x>1) {
            if(x&1)
                x--;
            x = x>>1;
            if(!mp[x])
            {
                last = x;
            }

        }
        ans1[i]=last;
//        printf("%d \n",last);
        mp[last]=1;
    }
    mp.clear();

    for(int i=0; i<n; i++) {
//        scanf("%d",&x);
//    printf("%d => ",ara[i]);
        x = ara[i];
        int last=x;
        while(x>1) {
            if(x&1)
                x--;
            x = x>>1;
            if(!mp[x])
            {
                last = x;
            }

        }
        ans2[i] = last;
        mp[last]=1;
//        printf("%d \n",last);

    }
    int mx1=0, mx2 = 0;
    for(int i=0; i<n; i++) {
        mx1 =  max(mx1,ans1[i]);
        mx2 =  max(mx2, ans2[i]);
    }

    if(mx1<mx2) {
        for(int i=0; i<n; i++)
            printf("%d ",ans1[i]);
    } else {
        for(int i=0; i<n; i++)
            printf("%d ",ans2[i]);
    }


    printf("\n");

    return 0;
}
