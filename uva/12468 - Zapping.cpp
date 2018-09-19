#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main() {
    int a,b,soja,ulta;
    while (scanf("%d %d",&a,&b) == 2) {
        if (a == -1) break;
        else {
        if (a>b) {
            soja = a-b;
            ulta=100-a+b;
        }
        else {
            soja = b-a;
            ulta=100-b+a;
        }
        if(soja<ulta) printf("%d\n",soja);
        else printf("%d\n",ulta);
    }
    }
    return 0;
}
