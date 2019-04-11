#include <bits/stdc++.h>
using namespace std;
int ara[100010];

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int n, k;
    int cnt;

    while(scanf("%d %d", &n, &k)==2) {
        cnt =0;
        ara[0] =0;
        for(int i=1; i<=n; i++) {
            scanf("%d", &ara[i]);
        }
        sort(ara, ara+n);
        ara[n] = INT_MAX;
        k*=2;
        for(int i=0; i<= n; i++) {
            int sum=0;

            for(int j= i+1; j<=n; j++) {
                sum+= (ara[j] - ara[j-1]);
                if(sum >k) {
                    cnt++;
                    if(j-i==1){
                        cout<<cnt<<endl;
                        i = max(0, j-1);
                    }
                    else
                        i = max(0, j-2);

                    break;
                } else if(sum==k){
                    cnt++;
                    i = j-1;
                    break;
                    }

                if(j== n-1) {
                    cnt++;
                    i = n;
                }
            }
        }

        printf("%d\n", cnt);
    }


    return 0;
}
