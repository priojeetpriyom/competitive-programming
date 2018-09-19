#include <iostream>
#include <cstdio>
using namespace std;
int main ()
{
    long long int n,i,num;
    while(scanf("%lld",&num) == 1) {
        n=num/2 +1;
        num=0;
        for(i=1;i<6;i=i+2) {
            num = num+ n*n*2 -i;
        }
        printf("%lld\n",num);
    }
    return 0;
}
