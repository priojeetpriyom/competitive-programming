#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int n,k;
    int a[300], b[300];

    cin>>n>>k;


    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=k; i++) cin>>b[i];




    a[n+1] = 1e9;
    a[0] = -1;
    int prev=0;
    for(int i=1; i<=n; i++) {
        if(a[i])  {
            if(a[i]<=prev) {
                printf("Yes\n"); return 0;
            } else prev=a[i];
        }
    }
    int f=0;
    for(int i=1; i<=n; i++) {

        if(a[i] ==0) {
//                printf("i %d ara_i %d\n", i, a[i]);
            for(int j =1; j<=k; j++)  {
                if( !a[i+1] || b[j]>=a[i+1] || !a[i-1] || b[j] <= a[i-1] ) {
                    printf("Yes\n"); return 0;
                }
            }

        }
//        else printf("i %d a_i %d\n", i, a[i]);

    }

    printf("No\n");
    return 0;
}


