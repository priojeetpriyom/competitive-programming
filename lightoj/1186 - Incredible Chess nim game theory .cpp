#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 55

int ara[105];

int main()
{

    int t;
    scanf("%d", &t);
//    memset(dp, -1, sizeof dp);

    int n;


    for(int tc=1; tc<=t; tc++)
    {

        printf("Case %d: ",tc);

        scanf("%d", &n);

        int x, ans=0;
        for(int i=0; i<n; i++) {
            scanf("%d", &ara[i]);
        }
        for(int i=0; i<n; i++) {
            scanf("%d", &x);
            ans ^= (x-ara[i]-1);
        }
        if(ans ==0) {
            printf("black wins\n");
        } else
            printf("white wins\n");


    }



    return 0;
}
