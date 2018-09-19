#include <stdio.h>
/*
int main() {
    int w,a,b;
    while (scanf("%d",&w)==1) {
        a=w/2;
        b=w-a;
        while(a>0) {
            if(a%2==0 && b%2==0) {
                printf("YES\n");
                b=-1;
                break;
            }
            a--;
            b++;
        }
        if(b>=0) printf("NO\n");
    }
    return 0;

}
*/

#include <stdio.h>

int main() {
    int w;
    while (scanf("%d",&w)==1) {
        if(w>2 && w%2==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;

}

