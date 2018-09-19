#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int i;
    char str[31];
    while(gets(str)) {
        for (i=0;i<strlen(str);i++) {
            if (str[i]>64 && str[i]<91) {
                     if (str[i]> 64 && str[i]< 68) printf("2");
                else if (str[i]> 67 && str[i]< 71) printf("3");
                else if (str[i]> 70 && str[i]< 74) printf("4");
                else if (str[i]> 73 && str[i]< 77) printf("5");
                else if (str[i]> 76 && str[i]< 80) printf("6");
                else if (str[i]> 79 && str[i]< 84) printf("7");
                else if (str[i]> 83 && str[i]<87 ) printf("8");
                else if (str[i]> 86 && str[i]< 91) printf("9");
            }
            else if(str[i]==48) printf("0");
            else if(str[i]==49) printf("1");
            else printf("-");
        }
        printf("\n");
    }
    return 0;
}
