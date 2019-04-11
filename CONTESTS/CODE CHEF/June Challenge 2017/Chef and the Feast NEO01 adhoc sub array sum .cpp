#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ara[100100];

ll calc(ll from, ll to) {

    ll sum=0;
    ll d = to - from+1;
    while(from <= to) {
        sum += ara[from];
        from++;
    }

    return sum *d;

}


int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);


    int t;
    scanf("%d", &t);
    int n;

    while(t--) {

        scanf("%d", &n);

        for(int i=1; i<=n; i++) {
            scanf("%lld", &ara[i]);
        }
//        printf("aise\n");

        ara[n+1]=0;
        ll sum=0;
//        for(int i=1; i<=n; i++) {
//            ll prev=0;
//            int j = i;
//
//            printf("1 i %d j %d calc %lld\n",i,j,calc(i,j));
//            while(j<=n && calc(i, j)>= prev)
//                {
//                    printf("i %d j %d calc %lld\n",i,j,calc(i,j));
//                    prev = calc(i,j);
//                    j++;
//                }
//            if(j == i) prev = ara[i];
//            sum+= prev;
//            if(j>i)
//                i = j-1;
//            printf("i %d\n", i);
//        }
        for(int i=1; i<=n; i++) {
            sum+= ara[i];
        }

        printf("%lld\n", sum);

    }


    return 0;
}





