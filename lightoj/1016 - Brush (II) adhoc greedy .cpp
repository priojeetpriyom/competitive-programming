#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 50001

int ara [MX];





int main()
{
    char c;
    int t;
    scanf("%d", &t);
//    memset(dp, -1, sizeof dp);

    for(int tc=1; tc<=t; tc++)
    {
        int n,w, x;

        scanf("%d %d", &n, &w);
//        w<<=1;
        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&x, &ara[i]);
        }
        sort(ara, ara+n);

        int cnt=0, mx=ara[0]-1;

        for(int i=0; i<n; i++)
        {
            if(ara[i]>mx)
            {
                cnt++;
                mx =  ara[i] + w;
            }
//            printf("i %d mx %d cnt %d\n", i, mx, cnt);
        }

        printf("Case %d: %d\n",tc, cnt);


    }



    return 0;
}
