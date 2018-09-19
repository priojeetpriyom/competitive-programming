#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int i,j,k;
    char str[1000];
    while(gets(str)) {
        for (i=0;i<strlen(str);i++) {
            if ((str[i]>65 && str[i]<91)) {
                     if ((str[i]==66)) printf("V");
                else if ((str[i]== 67)) printf("X");
                else if ((str[i]== 68)) printf("S");
                else if ((str[i]== 69)) printf("W");
                else if ((str[i]== 70)) printf("D");
                else if ((str[i]== 71)) printf("F");
                else if ((str[i]== 72)) printf("G");
                else if ((str[i]== 73)) printf("U");
                else if ((str[i]== 74)) printf("H");
                else if ((str[i]== 75)) printf("J");
                else if ((str[i]== 76)) printf("K");
                else if ((str[i]== 77)) printf("N");
                else if ((str[i]== 78)) printf("B");
                else if ((str[i]== 79)) printf("I");
                else if ((str[i]== 80)) printf("O");
                else if ((str[i]== 82)) printf("E");

                else if ((str[i]== 83)) printf("A");
                else if ((str[i]== 84)) printf("R");
                else if ((str[i]== 85)) printf("Y");
                else if ((str[i]== 86)) printf("C");
                else if ((str[i]== 87)) printf("Q");
                else if ((str[i]== 88)) printf("Z");
                else if ((str[i]== 89)) printf("T");
            }
            else if (str[i]==48) printf("9");
            else if (str[i]==49) printf("`");
            else if (str[i]>49 && str[i]<58) printf("%c",str[i]-1);
            else if (str[i]== ',') printf("M");
            else if (str[i]== ';') printf("L");
            else if (str[i]== '[') printf("P");
            else if (str[i]== '-') printf("0");
            else if (str[i]== '=') printf("-");
            else if (str[i]== ']') printf("[");
            else if (str[i]== '.') printf(",");
            else if (str[i]== '/') printf(".");
            else if (str[i]== 92) printf("]");
            else if (str[i]== 39) printf(";");

            else printf("%c",str[i]);
        }
        printf("\n");
    }

    return 0;
}
