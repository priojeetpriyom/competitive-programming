#include <iostream>
#include <cstdio>
using namespace std;
int main ()
{
    long long int i,j,k,n,l,coun;
    while (scanf("%lld %lld",&i,&j) == 2)
    {
        //printf("%d %d ",i,j);

        if (j>i) {
            coun = 0;
            l=i;
            for (;i<=j;i++) {
                n=i;
                k=0;
                while (n>0) {
                    if (n==1) {
                        k++;
                        break;
                    }
                    else if(n%2 ==0) {
                        n=n/2;
                        k++;
                }
                    else {
                        n=3*n+1;
                        k++;
                }
                }
                if (k >coun) coun =k;
            }
            printf("%lld %lld %lld\n",l,j,coun);
        }
        else {
            l=j;
            coun = 0;
            for (;j<=i;j++) {
                n=j;
                k=0;
                while (n>0) {
                    if (n==1) {
                        k++;
                        break;
                    }
                    if(n%2 ==0) {
                        n=n/2;
                        k++;
                }
                    else {
                        n=3*n+1;
                        k++;
                }
                }
                if (k >coun) coun =k;
            }
            printf("%lld %lld %lld\n",i,l,coun);
        }
        }
    return 0;
    }

