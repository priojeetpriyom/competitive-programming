#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;

int main ()
    {
    int n,i,a,b,c,children,k;
    while (scanf("%d",&n)==1) {
        a=b=c=k=0;
        for (i=0;i<n;i++) {
            scanf("%d",&children);
            if(children==1) a++;
            else if(children==2) b++;
            else if(children==3) c++;
            else k++;
        }
        while (a>0 || b>0 || c>0) {
            if (c>0) {
                if(a>0) {
                    if(c>a) {
                        k+= a;
                        c-=a;
                        a=0;
                    }
                    else {
                        k+= c;
                        a-=c;
                        c=0;
                    }
                }
                else {
                    k+=c;
                    c=0;
                }
            }
            if (b>0) {
                if (b>1) {
                    k+=(b/2);
                    b=b%2;
                }
                if(a>0 && b>0) {
                    if(b>2*a) {
                        k+=a;
                        b-=a;
                        a=0;
                    }
                    else {
                        k+=b;
                        a-=(b+b);
                        b=0;
                    }
                }
                else {
                    k+=b;
                    b=0;
                }

            }
            if(a>0) {
                k+= (a/4);
                if(a%4 !=0) k++;
                a=0;
            }
        }
        printf("%d\n",k);
    }
    return 0;
    }
