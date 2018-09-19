#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int j=0,i,t,k=0,len;
    char str[10000];
    scanf("%d",&t);
    t+=1;
    while (t--) {
        k=1;
        gets(str);
        len = strlen(str);
        for (i=0;i<len-1;i++) {
            if(str[i] == 32 && str[i+1] !=32) k++;
        }
        if(j>0) printf("%d\n",k*420);
        else j++;
    }
    return 0;
}
