#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main() {
    int a,b,c,t,k=1;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d %d",&a,&b,&c);
        if(a>b && a<c) {
            printf("Case %d: %d\n",k++,a);
        }
        else if (a<b && a>c) {
            printf("Case %d: %d\n",k++,a);
        }
        else if(a>c && a<b) {
            printf("Case %d: %d\n",k++,a);
        }
        else if (a<c && a>b) {
            printf("Case %d: %d\n",k++,a);
        }

        else if(b>a && b<c) {
            printf("Case %d: %d\n",k++,b);
        }
        else if (b<a && b>c) {
            printf("Case %d: %d\n",k++,b);
        }
        else if(b>c && b<a) {
            printf("Case %d: %d\n",k++,b);
        }
        else if (b<c && b>a) {
            printf("Case %d: %d\n",k++,b);
        }
        else if(c>a && c<b) {
            printf("Case %d: %d\n",k++,c);
        }
        else if (c<a && c>b) {
            printf("Case %d: %d\n",k++,c);
        }
        else if(c>b && c<a) {
            printf("Case %d: %d\n",k++,c);
        }
        else if (c<a && c>b) {
            printf("Case %d: %d\n",k++,c);
        }
        else printf("baler code likhso tumi");
    }
    return 0;
}
