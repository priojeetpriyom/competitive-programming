#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOutput.txt","w",stdout);

    int tcase,n;
        char str[100001];
    scanf("%d",&tcase);
    while(tcase--) {
        scanf("\n%s",str);
        n = strlen(str);
        int one=0,zero=0;
        char x;
        while(n-->0) {
            x= str[n];
            if(x=='0')
                zero++;
            else
                one++;
        }
        if(one==1 || zero==1)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}

