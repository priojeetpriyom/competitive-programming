#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int n;
    int rem,len,i;
    char str[1000];
    while (1 ) {
        scanf("%s",&str);
        len = strlen(str);
        if (len==1 && str[0]==48) break;
        else {
            rem=0;
            for (i=0;i<len;i++) {
                n=str[i]-48+10*rem;
                rem=n%17;
            }
            if(rem==0) printf("1\n");
            else printf("0\n");
    }
    }
    return 0;
}
