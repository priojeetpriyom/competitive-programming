#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ll ans=0;
    int n,k;
    cin>>n>>k;

    ll mn= 2e9, ara[100100];

    for(int i=0; i<n; i++)
    {
        scanf("%I64d", &ara[i]);
        mn = min(mn, ara[i]);
    }

    bool imp = false;

    for(int  i=0; i<n; i++) {
        if( (ara[i]-mn)%k ==0) {
            ans+= ( (ara[i]-mn)/k );
        } else {
//            printf("mn %I64d ara[%d] %I64d %I64d\n", mn, i , ara[i], (ara[i]-mn)%k );
            printf("-1\n");
            return 0;
        }
    }

    cout<<ans<<endl;



    return 0;
}


