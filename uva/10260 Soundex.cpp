#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int i,j,k,now,last;
    char str[1000];
    while(scanf("%s",&str)==1) {

        last=0;
        for (i=0;i<strlen(str);i++) {

                if( str[i] == 'B' || str[i] == 'F' || str[i] == 'P' || str[i] == 'V') {
                    now=1;
                }
                else if (str[i] == 'C' || str[i] == 'G' || str[i] == 'J' || str[i] == 'K' || str[i] == 'Q' || str[i] == 'S' || str[i] == 'X' || str[i] == 'Z') {
                    now=2;
                }
                else if (str[i] == 'D' || str[i] == 'T') {
                    now=3;
                }
                else if (str[i] == 'L') {
                    now=4;
                }
                else if (str[i] == 'M' || str[i] == 'N') {
                    now=5;
                }
                else if (str[i]== 'R') {
                    now=6;
                }
                else last=now=0;

                if (now!=last) {
                    last=now;
                    printf("%d",now);
                }

        }
        printf("\n");
    }
    return 0;
}
