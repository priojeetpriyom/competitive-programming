#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    int n,root,i,n1;
    short prime,emrip,k;
    while (scanf("%d",&n)==1) {
        if(n==0) {
            printf("%d is not prime.\n",n);
            continue;
        }
//        else if(n==2) {
//
//        }
        root=sqrt(n)+1;
        //printf("root %d\n",root);
        if(n&1==1) i=3;
        else i=2;
        prime=1;
        for(;i<root;i=i+2) {
            if(n%i==0) {
                prime=0;
            }
        }
        if(prime==0) {
            printf("%d is not prime.\n",n);
            continue;
        }
        n1=0;
        root=n;
        while(n>0) {
            n1=n1*10+n%10;
            n/=10;
        }
        n=root;
        //printf("n %d n1 %d\n",n,n1);
        if(n==n1) {
            printf("%d is prime.\n",n);
            continue;
        }

        root=sqrt(n1)+1;
        if(n1&1==1) i=3;
        else i=2;
        k=1;
        emrip=1;
        for(;i<root;i=i+2) {
            if(n1%i==0) {
                emrip=0;
            }
        }
        if(prime==1 && emrip==1) printf("%d is emirp.\n",n);
        else printf("%d is prime.\n",n);
    }
    return 0;
}
