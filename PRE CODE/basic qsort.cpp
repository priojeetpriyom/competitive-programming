#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
int sorting ( const void* a,const void* b) {
    int A= *((int*) a);
    int B= *((int*) b);
    return A-B;
}
int main ()
{
    int ara[] = {1,-31,-32,22,23,-22};
    qsort(ara,6,sizeof(int),sorting);
    for(int i=0;i<6;i++) printf("%d ",ara[i]);
    return 0;
}
