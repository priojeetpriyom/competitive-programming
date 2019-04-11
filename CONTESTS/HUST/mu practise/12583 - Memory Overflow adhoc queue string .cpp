#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOutput.txt","w",stdout);
    int t,tcase;
    scanf("%d",&t);
    for(tcase=1; tcase<=t; tcase++) {
        int len,len_remember=0,k,x;
        char str[555],remember[555];
        scanf("%d %d",&len, &x);
        scanf("\n%s",str);
        printf("Case %d: ",tcase);
        int cnt=0;
        for(int k=0; k<len; k++) {
            for(int i=0; i<len_remember;i++) {
                if(str[k] == remember[i])
                {
                    cnt++;
                    break;
                }
            }
            remember[len_remember++] = str[k];
            remember[len_remember]= '\0';

            if(len_remember>x) {
                for(int i=0; i<len_remember; i++)
                    remember[i] = remember[i+1];
                len_remember--;
            }

        }
        printf("%d\n",cnt);
    }

    return 0;
}

