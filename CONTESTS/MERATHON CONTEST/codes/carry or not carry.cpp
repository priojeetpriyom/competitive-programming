#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main ()
{
    int a,b;
    while(scanf("%d %d",&a,&b)==2)
        printf("%d\n",a^b);
    return 0;
}
