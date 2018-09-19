#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int e,f,c,t,soda,empty;
    scanf("%d",&t);
    while (t--) {
        soda=0;
        scanf("%d %d %d",&e,&f,&c);
        empty=e+f;
        if (empty>=c) {
            while(empty>=c) {
                //printf("%d %d\n",soda,empty);
                if(empty%c==0) {
                    empty/=c;
                    soda+=empty;
                }
                else {
                    soda+=empty/c;
                    empty=empty%c+empty/c;
                }
            }
        }
        printf("%d\n",soda);
    }
    return 0;
}
