#include <bits/stdc++.h>

using namespace std;


int main ()
{
    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++) {
        int if_h,if_m,s_h,s_m;
        char c;
        scanf("%d \n%c %d",&s_h,&c,&s_m);
        scanf("%d \n%c %d",&if_h,&c,&if_m);
        printf("Case %d: ",i);

        if(if_h<s_h) {
            if_h+=24;
        }
        else if(if_h==s_h && if_m<s_m) {
            if_h+=24;
        }

        if(if_m<s_m)
        {
            if_m+=60;
            if_h--;
        }
        if_h-=s_h;
        if_m-=s_m;

        printf("%d hours %d minutes\n",if_h,if_m);

    }
    return 0;
}


