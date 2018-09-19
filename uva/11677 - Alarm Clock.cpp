#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    int h1,h2,m1,m2,diff;
    while(scanf("%d %d %d %d",&h1,&m1,&h2,&m2)==4) {
        if(h1==0 && h2==0 && m1==0 && m2==0) break;
        if(h2==0 && h1!=0) h2=24;
        if(h2-h1<0) {
            h2=24+h2;
            //printf("h2 %d h1 %d\n",h2,h1);
        }
        else if (h2-h1==0 && m2-m1<0) h1=h1-24;
        printf("%d\n",((h2*60)+m2)-((h1*60)+m1));
    }
    return 0;
}
