
#include <bits/stdc++.h>

using namespace std;

int main ()
{
//    freopen("input.txt","r",stdin);
int t,s,x;
    scanf("%d %d %d",&t,&s,&x);
    x-=t;
    if((x%s==0 || x%s==1) && (x>=s|| x==0) ) {
        printf("YES\n");
    }else
    printf("NO\n");
    return 0;
}


