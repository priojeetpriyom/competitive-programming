#include <bits/stdc++.h>
using namespace std;

//map<int,bool> mp;
int nums[1000010];
int main()
{
//    freopen("myInput.txt","r",stdin);
//    freopen("myOutput.txt","w",stdout);

    int tcase;
    scanf("%d",&tcase);

    for(int t=1; t<=tcase; t++) {
        int m;
        scanf("%d",&m);
        int ara[210];
        for(int i=0; i<m; i++) {
            scanf("%d", &ara[i]);
        }
        sort(ara,ara+m);
        nums[0]=0;
        for(int i=0; i<m; i++) {
            nums[ara[i]]=1;
        }
        for(int i=1; i<1000001; i++) {
            nums[i]+=nums[i-1];
        }
        int a,b;
        scanf("%d %d",&a,&b);
        a--;b++;
        int cnt=0;
        for(int i=0; i<m; i++) {
            for(int j=i; j<m; j++) {
                for(int k=j; k<m; k++) {
//                    for(int l=k; l<m; l++) {
                        int x= ara[i]+ ara[j]+ ara[k]+ ara[l];
                        if( x >a && x <b){
//                                printf("%d -> %d %d %d %d\n",x,ara[i],ara[j],ara[k],ara[l]);
//                            if(!mp[x]){
//                                mp[x]=1;
                                cnt++;
//                            }
                        }
//                    }
                }
            }
        }
        printf("Case %d: %d\n",t,cnt);
//        mp.clear();
    }

    return 0;
}


