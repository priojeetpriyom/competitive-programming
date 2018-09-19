#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    long long int decimal,i,j,div,len;
    char str[1000];
    bool breakk;
    while(1) {
        i=1,decimal =0;
        gets(str);
        len=strlen(str);
        for (j=0;j<len;j++) {
            if (str[j] == 48) breakk=true;
            else {
                breakk = false;
                break;
            }
        }
        if (breakk) break;
        else {
            while (len>=1) {
                div = str[--len] - 48;
                if (div>=0) decimal = decimal + (div * pow(2,i++)) - div;
            }
            printf("%lld\n",decimal);
        }
        }
    return 0;
}
