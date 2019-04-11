
#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);
    int t;
    cin>>t;

    for(int tc = 1; tc<=t; tc++) {
        int n;
        cin>>n;
        int ara[102];
        for(int i=0; i<n; i++) {
            scanf("%d", &ara[i]);
        }

        sort(ara, ara+n);

        int b=0, e = n-1;
        int cnt=0;
        while(ara[e]>=50 && e> -1)
        {
            cnt++;
            e--;
        }

        while(e>b) {

            int nums = (int) ((ceil) (50.0/ara[e]));


            if(nums> e-b+1)
                break;

            e--;
            nums--;
            while(nums--)
                b++;

            cnt++;
        }

        printf("Case #%d: %d\n",tc,  cnt);
    }
    return 0;
}

