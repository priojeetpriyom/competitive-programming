#include <bits/stdc++.h>

using namespace std;

int ara[100005];
int main ()
{
    int n,digit=1;
    for(int i=1; i<10001; i++) {
        digit*=2;
        digit= digit%10;
        ara[i]=digit;
    }

    while(scanf("%d",&n)==1) {

        printf("%d\n",ara[n]);
    }


    return 0;
}



