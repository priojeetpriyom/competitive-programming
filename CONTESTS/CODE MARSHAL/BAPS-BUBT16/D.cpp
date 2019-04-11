#include <bits/stdc++.h>
using namespace std;

int ara1[10001], ara2[10001];
int main()
{
//    freopen("myInput.txt","r",stdin);
//    freopen("myOutput.txt","w",stdout);

    int tcase;
    scanf("%d",&tcase);

    for(int t=1; t<=tcase; t++) {
        int n,m;
        scanf("%d %d",&n,&m);

        for(int i=0; i<n; i++)
            scanf("%d",&ara1[i]);
//printf("n %d m %d\n",n,m);
        for(int j=0; j<m; j++)
            scanf("%d",&ara2[j]);
//printf("kak2\n");
        long long time=0;
        for(int i=0,j=0;;) {
            if((i==n && j== m-1) || (i==n-1 && j== m)) {
                break;
            }
            if(i==n) {
                time += ara2[j];
                j++;
            } else if(j==m) {
                time+= ara1[i];
                i++;
            } else {
                if(ara1[i]<ara2[j]) {
                    time+= ara1[i];
                    i++;
                } else {
                    time += ara2[j];
                    j++;
                }
            }
        }
        printf("Case %d: %lld\n",t,time);

    }

    return 0;
}


