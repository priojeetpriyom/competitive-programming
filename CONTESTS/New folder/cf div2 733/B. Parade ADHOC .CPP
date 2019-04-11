#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int n, l,r, mx=0, mx_l=0,mx_r=0, sum_l=0, sum_r=0, pos=0;
    int mn_l=0, mn_r=0, mn=0, pos_mn=0;
    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        scanf("%d %d", &l, &r);
        if(l-r >mx) {
            mx  = abs(l-r);
            mx_l = l;
            mx_r = r;
            pos = i;
        }
        else if(r-l > mn) {
            mn = r - l;
            mn_l = l;
            mn_r = r;
            pos_mn = i;
        }

        sum_l+=l;
        sum_r+=r;
    }
    int diff = abs(sum_l - sum_r);

    int s_l = (sum_l - mx_l +mx_r);
    int s_r = (sum_r - mx_r + mx_l);
    int diff2 = abs(sum_l - sum_r);

    int pos_main =0;

    if(diff2 > diff)
        pos_main = pos;

    s_l = (sum_l - mn_l +mn_r);
    s_r = (sum_r - mn_r + mn_l);
    int diff3  =  abs(s_l - s_r);

     if(diff3> diff2)
        pos_main = pos_mn;

    printf("%d\n", pos);
//    else
//        printf("0\n");

    return 0;
}
