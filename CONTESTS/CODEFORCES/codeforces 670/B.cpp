#include <bits/stdc++.h>
using namespace std;
unsigned long long sum[100002];
int main()
{
//    freopen("myOutput.txt","w",stdout);
//    //freopen("myInput.txt",") ;;;
    for(int i=1; i<100001; i++)
        sum[i]= sum[i-1]+i;
    int ids[100002];
    int n,k;
    scanf("%d %d",&n, &k);
    for(int i=1; i<=n; i++)
        scanf("%d",&ids[i]);
//    for(int i=1; i<11; i++)
//        printf("%d ",sum[i]);
    for(int i=1; i<100001; i++)
    {
        if(k<=sum[i])
        {
            if(k== sum[i])
            {
                printf("%d\n",ids[i]);
                return 0;
            }
            printf("%d\n",ids[k- sum[i-1]]);
            return 0;
        }
    }
    return 0;

}

