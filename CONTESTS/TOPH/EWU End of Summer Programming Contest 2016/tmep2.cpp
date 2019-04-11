#include <bits/stdc++.h>
using namespace std;

int ara[10005];
vector<int> ans[10005];

int main()
{
//    freopen("myOutput.txt","w",stdout);


    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        int n,q;
        scanf("%d %d",&n,&q);

        for(int k=0; k<n; k++)
        {
            scanf("%d",&ara[k]);
        }

        for(int k =0; k<n; k++)
        {

//            ans[k][k]=0;
            for(int m = k+1; m<n; m++)
            {


                if(ara[k]>ara[m] && ara[k]%ara[m]==0)
                {
//                    printf("aise\n");
                    ans[k].push_back(m);

                }
//                else
//                    ans[k][m]=ans[k][m-1];
//                printf("%d ",ans[k][m]);
            }
//            printf("\n");

        }
        printf("Case %d:\n",i);
        while(q--)
        {
            int l,r;
            scanf("%d %d",&l,&r);

            int anss=0;
            int z=r-1;
            for(int x = l-1; x<r; x++) {
                for(int y=0; y<ans[x].size(); y++) {
                    if(ans[x][y]>z)
                        break;
                    anss++;
                }
            }
            printf("%d\n",anss);

        }
        for(int k =0; k<n; k++)
            ans[k].clear();

    }

    return 0;
}
