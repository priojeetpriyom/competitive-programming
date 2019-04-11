#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOutput.txt","w",stdout);

    int tcase;

    scanf("%d",&tcase);
    for(int t=1; t<=tcase; t++) {
        int ara[162] ={0};
        int n;
        scanf("%d",&n);
        float n_by_four = (float)n/4;

        for(int i=0; i<n; i++) {
            int x;
            scanf("%d",&x);
            ara[x]++;
        }
//        printf("oka");
////
//        for(int i=0;i<161; i++)
//            printf("i %d ara[i] %d\n",i,ara[i]);

        for(int i=1; i<161; i++)
            ara[i]+=ara[i-1];

        int diff=0, mn_diff=INT_MAX,mn_a,mn_b,mn_c;
        for(int i=0; i<161; i++) {
                diff= abs(n_by_four-  ara[i]);
            for(int j = i+1; j<161; j++) {
                int diff_j= diff+ abs(n_by_four-  (ara[j]-ara[i]));
                for(int k = j+1; k<161; k++) {

                    int diff_k= diff_j+ abs(n_by_four-  (ara[k]-ara[j]));
                    diff_k += abs(n_by_four-  (ara[160]-ara[k]));
                    if(diff_k<mn_diff) {
//                            printf("diff_k %d\n",diff_k);
                        mn_a = i;
                        mn_b=j;
                        mn_c = k;
                        mn_diff = diff_k;
                    }
                }
            }
        }

        printf("Case %d: %d %d %d\n",t,mn_a,mn_b,mn_c);
    }
    return 0;
}

