#include <iostream>
#include <cstdio>
using namespace std;
int main ()
{
    long long int i,j,k,n,l,coun,m;
    while (scanf("%lld %lld",&i,&j) == 2)
    {
        m=1;
        if (i==0 && j==0) break;
        else if (j>i){
            coun = 0;
            l=i;
            for (;i<=j;i++) {
                n=i;
                k=0;
                do
                 {
                    if(n%2 ==0) {
                        n=n/2;
                        k++;
                }
                    else {
                        n=3*n+1;
                        k++;
                }
                }
                while (n!=1);
                //k++;
                if (k >coun) {
                coun =k;
                m=i;
                }
            }
            printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",l,j,m,coun);
        }
        else {
            l=j;
            coun = 0;
            for (;j<=i;j++) {
                n=j;
                k=0;
                do
                 {
                    if(n%2 ==0) {
                        n=n/2;
                        k++;
                }
                    else {
                        n=3*n+1;
                        k++;
                }
                }
                while (n!=1);
                //k++;
                    if (k >coun) {
                    coun =k;
                    m=j;
                }
            }
            printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",l,i,m,coun);
        }
        }
    return 0;
    }

