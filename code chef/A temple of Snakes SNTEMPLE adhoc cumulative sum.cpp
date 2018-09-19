#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll ara[100100], frontt[100100], backk[100100], ans[100100];


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
        int cnt=0;
        for(int i=1; i<=n; i++) {
            if(ara[i]>cnt) cnt++;
            else cnt=min( (ll) cnt, ara[i]);
            frontt[i] = min(  cnt, n - i+1);
        }
        cnt=0;
        for(int i=n; i>0; i--) {
            if(ara[i] >cnt)
                cnt++;
            else cnt= min( (ll) cnt, ara[i]);
//            printf("i %d cnt %d\n",i, cnt);
            backk[i] = min(  cnt, i);
        }
//        printf("\n");

//        for(int i=1; i<=n; i++) printf("%d ", frontt[i]); printf("\n");
//        for(int i=1; i<=n; i++) printf("%d ", backk[i]); printf("\n");




        int mx=-1, mx_idx;

        for(int i=1; i<=n; i++) {
            ans[i] = min(frontt[i], backk[i]);
//            printf("i %d ans %d\n", i, ans[i]);
            if(ans[i] > mx) {
//                printf("ans_%d %d mx %d\n",i, ans[i], mx);
                mx = ans[i];
                mx_idx = i;
            }
        }
//        printf("mx %d mx_idx %d\n", mx, mx_idx);

//        for(int i=1; i<=n; i++) printf("%d ", ans[i]); printf("\n");


        ans[0] = ans[n+1] =0;
        ll sum=0;

        int r = mx_idx, l = mx_idx-1;

        cnt = mx;
        for(r; r<=n; r++) {
            sum += (ara[r] - cnt);
            if(cnt<=1) break;
            cnt--;
        }
        for(r= r+1; r<=n; r++) {
            sum += (ara[r]);
        }
//        printf("sum after r %lld\n", sum);
        cnt = mx-1;
        for(l = l; l>0; l--) {
//            printf("ara_%d %d cnt %d\n",l, ara[l], cnt);
            sum+=(ara[l] - cnt);
            if(cnt<=1) break;
            cnt--;
        }

        for(l = l-1; l>0; l--) {
            sum+=(ara[l]);
        }




    printf("%lld\n", sum);


    }




    return 0;
}





