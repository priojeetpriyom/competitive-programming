#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 55

//int ara[105];

int main()
{

    int t;
    scanf("%d", &t);
//    memset(dp, -1, sizeof dp);

    int k;


    for(int tc=1; tc<=t; tc++)
    {


        scanf("%d", &k);

        int prev, now, ans=0;
//        scanf("%d", &now);
//        k+=k;

        for(int i=0; i<k; i++) {
            prev = now;
            scanf("%d %d",&prev, &now);
            ans ^= (now - prev-1);
        }

        printf("Case %d: ",tc);
        if(ans >0) {
            printf("Alice\n");
        } else
            printf("Bob\n");


    }



    return 0;
}

