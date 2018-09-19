#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int i,len;
    char str[101];
    while(scanf("%s",&str)==1) {
        len=strlen(str);
        for(i=0;i<len;i++) {
            if(!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'y' || str[i] == 'Y')) {
            if(str[i]<91) printf(".%c",str[i]+32);
            else printf(".%c",str[i]);
        }
        }
        printf("\n");
    }
    return 0;

}
