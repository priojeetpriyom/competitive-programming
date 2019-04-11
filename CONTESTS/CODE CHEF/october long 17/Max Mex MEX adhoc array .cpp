#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int ara[(int)2e5+10];

int main()
{
//    ios_base::sync_with_stdio(0);    cin.tie(0);

    int t;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++)
    {
        int n, k;
        memset(ara, 0, sizeof ara);

        scanf("%d %d", &n, &k);
        int x=0;
        for(int i=0; i<n; i++) {
            scanf("%d", &x);
            ara[x]=1;
        }
        int cnt=0;
        for(int i=0; i<=2e5+3; i++) {
            if(!ara[i]) {
                cnt++;
                if(cnt==k+1) {
                    printf("%d\n", i);
                    break;
                }
            }
        }

    }



    return 0;
}

