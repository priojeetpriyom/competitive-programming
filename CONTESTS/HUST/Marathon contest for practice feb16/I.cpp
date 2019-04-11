#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, a[51], b[51],MX[10001],lenMx, mx;
    while(scanf("%d",&n)==1) {
        lenMx=0, mx=0;
        for(int i=0; i<10001; i++)
            MX[i]=0;
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        scanf("%d",&m);
        for(int i=0; i<m; i++)
            scanf("%d",&b[i]);
        for(int i=m-1; i>=0; i--)
        {
            for(int j=0; j<n; j++)
            {
                if(b[i]%a[j]== 0) {
                    int x= b[i]/a[j];
                    MX[x]++;
                    if(x>mx)
                        mx=x;
                }
            }
        }
        printf("%d\n",MX[mx]);
    }
    return 0;
}
