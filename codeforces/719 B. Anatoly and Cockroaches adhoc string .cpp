#include <bits/stdc++.h>
using namespace std;

char str[100010];

int main()
{
//    freopen("myInput.txt","r",stdin);
//    freopen("myOutput.txt","w",stdout);

    int len;
    scanf("%d",&len);
    scanf("\n%s",str);

    int cnt2=0,cnt1=0;
    int mis_r=0,mis_b=0;
    for(int i=0; i< len; i++) {
        if((i+1)&1!=0) {
            if(str[i]=='b')
                mis_r++;
        } else if(str[i]=='r')
            mis_b++;
    }
//    printf("r %d b %d\n",mis_r,mis_b);
    cnt1 = abs(mis_b-mis_r)+ min(mis_b,mis_r);
   mis_r=0,mis_b=0;

    for(int i=0; i< len; i++) {
        if((i+1)&1!=0) {
            if(str[i]=='r')
                mis_b++;
        } else if(str[i]=='b')
            mis_r++;
    }
    cnt2 = abs(mis_b-mis_r)+ min(mis_b,mis_r);
    printf("%d\n",min(cnt1,cnt2));

    return 0;
}



