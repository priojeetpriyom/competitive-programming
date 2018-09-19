#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    unsigned i,j;
    while(scanf("%d %d",&i,&j)==2) {
        printf("%u\n",i^j);
    }
    return 0;
}

