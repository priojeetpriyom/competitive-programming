
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    char str[101];
    int len,t;
    scanf("%d",&t);
    while(t--) {
        scanf("%s",&str);
        len=strlen(str);
        if(len>10) printf("%c%d%c\n",str[0],len-2,str[len-1]);
        else printf("%s\n",str);
    }
    return 0;

}
