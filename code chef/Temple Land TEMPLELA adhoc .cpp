#include<bits/stdc++.h>

using namespace std;

typedef long long ll;



int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);


    int t;
    cin>>t;
    int n;
    int ara[111];
    while(t--) {
        int i;
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
            scanf("%d", &ara[i]);
        int ans=1;
        if( !(n&1)) ans=0;
        else {

            for(i=1; i<=(n>>1)+1; i++ ) {
                if(ara[i]!= i) {
                    ans=0;
                    break;
                }
            }

            for(i; i<=n; i++) {
                if(ara[i]!= n-i+1) {
                    ans=0;
                    break;
                }
//                cnt--;
            }
        }

        if(ans) printf("yes\n");
        else printf("no\n");
    }

    return 0;

}
