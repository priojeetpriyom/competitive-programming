
#include<bits/stdc++.h>
using namespace std;
int main ()
{
   int n;
    while(scanf("%d",&n)==1) {
        int a,b,sum=0;
        while(n--) {
            scanf("%d %d",&a,&b);
            sum+= (b-a);
        }
        printf("%d\n",sum);
    }

    return 0;
}

