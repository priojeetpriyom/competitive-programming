 #include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    long int n;
    while(1) {
        scanf("%ld",&n);
        if(n<0) break;
        else if (n==1) printf("0%%\n");
        else printf("%ld%%\n",n*25);
    }
    return 0;
}
