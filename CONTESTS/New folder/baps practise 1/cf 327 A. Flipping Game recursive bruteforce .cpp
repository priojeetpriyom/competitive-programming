#include <bits/stdc++.h>
using namespace std;


int main()
{

    int n;
    int freq[111];
    while(scanf("%d",&n)==1)
    {
        int ara[111];
        memset(freq, 0 , sizeof(freq));
        freq[n] = INT_MIN;

        for(int i=0; i<n; i++)
        {

            scanf("%d",&ara[i]);
        }
//        if(n<=2) {
//            printf("%d\n",n);
//            continue;
//        }





        int  cnt2=0,mx_mx=0;
        for(int i=0; i<n; i++)
        {
            int cnt=0;
            if(ara[i]==0)
            {
                while(ara[i]==0 && i<n)
                {
                    cnt++;
                    i++;
                }
                mx_mx  = max(mx_mx,cnt);
                i--;
            }
            else
            {
                while(ara[i]==1 && i<n)
                {
                    cnt2++;
                    i++;
                }
                i--;

            }
        }










//        int one=0;
int mx_i, mx_len, mx=0;
    for(int len =1 ; len<= n; len++) {
        for(int i=0; i+len<=n; i++) {
            int zero=0, one=0;
            for(int j=i ; j<i+len; j++) {
                if(ara[j] == 0) {
                    zero++;
                } else
                    one++;
            }

            if(zero- one > freq[i]) {
                freq[i] = zero-one;
                if(freq[i]> mx) {
                    mx = freq[i];
                    mx_i = i;
                    mx_len = len;
                }
            }
        }
    }
//    printf("mx %d mx_i %d mx_len %d\n",mx,mx_i, mx_len);

    if(mx==0) {
//        printf("oka");

        printf("%d\n",n-1);


    } else {
        for(int i=mx_i; i<mx_i+mx_len; i++)
    {
        ara[i] = 1- ara[i];
    }

    int cnt=0;
    for(int i=0; i<n; i++)
        if(ara[i]==1)
            cnt++;

        printf("%d\n", cnt);
    }
    }
    return 0;
}
