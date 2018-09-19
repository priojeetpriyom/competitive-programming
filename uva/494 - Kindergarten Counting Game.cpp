#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int i,k;
    char str[1000];
    while (gets(str) != NULL) {
        k=0;
        for (i=0;i<strlen(str);i++) {
            if ((str[i]<65 || str[i]>122) && ((str[i-1]>=65 && str[i-1]<=122))) k++;
        }
        printf("%d\n",k);
    }
    return 0;
}
