#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//int dp[(477218589>>5) +1], vis[(477218589>>5) +1];
ll n;

char calc(ll high, ll low, char state)
{
//    getchar();
//    printf("high %lld low %lld state %c\n", high, low, state);
    if(1== low || 1==high)
        return state;

    if(state == 'w') {
        calc(low-1, ((low+1)>>1), 'l');
    } else {
        calc(low-1, ((low+8)/9), 'w');
    }
}

int main()
{
//    freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);


//    dp[lim>>5] |= (1 << (lim&31));
//    vis[lim>>5] |= (1 << (lim&31));


//    for(int i = lim-1; i>1; i--)
//    {
////        printf("i %d\n", i);
//        for(int j=2; j<10; j++) {
//            ll mul =(ll) i*j;
//            if(mul >= lim) {
////                dp[n>>5] |= 0<<(n&31);
//            }
//            else if(! (dp[mul>>5] & (1<< (mul&31)))) {
//                dp[i>>5] |= (1 << (i&31));
//                break;
//            }
//        }
//    }



//    for(int i = lim-1; i>1; i--)
//    {
////        printf("%d\n", i);
//        (calc(i));
//    }


    while(scanf("%lld", &n)==1) {
        if(calc((n), (n+8)/9, 'w') == 'w') {

            printf("Stan wins.\n");
        } else
            printf("Ollie wins.\n");
    }

    return 0;


}

