#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main ()
{
    int a,b,k,root;
    while(1) {

        scanf("%d %d",&a,&b);
        if(a==0 && b==0) break;
        else {
            k=0;
            for(;a<=b;a++) {
                root= sqrt(a);
                if(root*root == a) ++k;
            }
            printf("%d\n",k);
        }
    }
    return 0;
}

