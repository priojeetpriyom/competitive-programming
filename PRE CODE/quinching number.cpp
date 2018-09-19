#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int i,j,tk,k,div;
    while (scanf("%d",&tk) == 1) {
            k=0;
    while(tk != 0) {
        if (tk%7 == 0) {
            printf("%d\n",tk/7);
            tk=0;
        }
        else if(tk >6) {
            i=tk/7;
            k=k+ tk/7;
            tk=tk- i*7;
        }
        else if(tk >4) {
            i=tk/5;
            k=k+ tk/5;
            tk=tk- i*5;        }
        else if(tk >2) {
            i=tk/3;
            k=k+ tk/3;
            tk=tk- i*3;
        }
        else {
            k = k+tk;
            tk=0;
        }
    }
    printf("%d\n",k);
    }
}
