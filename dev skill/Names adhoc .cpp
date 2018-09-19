#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int t;
    cin>>t;

    while(t--) {
        char str[111];
        long long l;
        scanf("%lld \n%s", &l, str);
        int len = strlen(str);
        l -= strlen(str);

//        printf("len %d l %lld\n", len, l);

        ll ans=1;

        for(int i=0; i<l; i++)
            ans*=26;
        printf("%lld\n", ans);
    }

    return 0;
}




