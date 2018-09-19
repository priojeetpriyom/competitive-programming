#include <iostream>
#include <cstdio>
using namespace std;
int main ()
{
    int maxx,minn,abs,sum,t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&sum,&abs);

        if (sum>=abs&&(sum+abs)%2==0) {
            maxx = (sum+abs)/2;
            minn = sum-maxx;
            printf("%d %d\n",maxx,minn);
        }
        else printf("impossible\n");
    }
    return 0;
}
