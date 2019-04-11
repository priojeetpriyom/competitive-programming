#include<bits/stdc++.h>

using namespace std;
typedef long long ll;



int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);


    int t;
    cin>>t;
    while(t--) {
        vector<ll> vec;
        int n;
        ll ans=0;

        scanf("%d", &n);
        int x;
        n+=n;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &x);
            vec.push_back(x);
        }

        sort(vec.begin(), vec.end());
//        for(int i= (n>>1); i<n; i++) {
//            ans+=vec[i];
//        }
        n>>=1;
//        ans= round( (double)ans/n);
        ans = vec[n-1 + (n+1)/2];
        n<<=1;
//        if(n<=4) ans = vec[n-1];
        printf("%lld\n", ans);
        printf("%lld %lld",vec[0], vec[n>>1]);
        for(int i=(n>>1)+1; i<n; i++) {
            printf(" %lld %lld",vec[i- (n>>1)], vec[i]);
        }
        printf("\n");

    }


    return 0;
}

