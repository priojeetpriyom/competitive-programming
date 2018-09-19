#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    long long int n,rem,i;
    char str[10000];
    while (scanf("%s",&str)) {
        if (strlen(str) ==1 && str[0] == 48) break;
        n=0,rem=0;
        for (i=0;i<strlen(str);i++) {
            n=(str[i]-48)+rem*10;
            rem=n%11;
        }
        if (rem==0) printf("%s is a multiple of 11.\n",str);
        else printf("%s is not a multiple of 11.\n",str);
    }
    return 0;
}
