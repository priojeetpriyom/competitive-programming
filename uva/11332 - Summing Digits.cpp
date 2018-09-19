#include <iostream>
#include <cstdio>
using namespace std;
int main ()
{
    int n,sum;
    while(1) {
        sum=0;
        scanf("%d",&n);
        if (n==0) break;
        else {
            while (1) {
            if (n>9) {
            while (n!=0) {
                sum = sum + n%10;
                n=n/10;
            }
            n=sum;

            sum=0;
            }
            else break;
        }
            printf("%d\n",n);
        }
    }
    return 0;
}
