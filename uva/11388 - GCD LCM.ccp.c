#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    int a,b,c,gcd,lcm,t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&gcd,&lcm);
        if(gcd>lcm) printf("-1\n");
        else {
            if(lcm%gcd==0) printf("%d %d\n",gcd,lcm);
            else printf("-1\n");
        }
    }
    return 0;
}

