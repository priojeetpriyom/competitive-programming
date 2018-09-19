#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
//d m b g t h j k p l ; ' . , [ ] e y f u o n r v i c
int main() {
    int i;
    char str[1000];

        gets(str);
        for (i=0;i<strlen(str);i++) {
            if ((str[i]>97 && str[i]<123)|| (str[i] >65 && str[i]<91)) {
                     if ((str[i]=='b' || str[i]== 'B')) printf("c");
                else if ((str[i]== 'c' || str[i]== 'C')) printf("z");
                else if ((str[i]== 'd' || str[i]== 'D')) printf("a");
                else if ((str[i]== 'e' || str[i]== 'E')) printf("q");
                else if ((str[i]== 'f' || str[i]== 'F')) printf("s");
                else if ((str[i]== 'g' || str[i]== 'G')) printf("d");
                else if ((str[i]== 'h' || str[i]== 'H')) printf("f");
                else if ((str[i]== 'i' || str[i]== 'I')) printf("y");
                else if ((str[i]== 'j' || str[i]== 'J')) printf("g");
                else if ((str[i]== 'k' || str[i]== 'K')) printf("h");
                else if ((str[i]== 'l' || str[i]== 'L')) printf("j");
                else if ((str[i]== 'm' || str[i]== 'M')) printf("b");
                else if ((str[i]== 'n' || str[i]== 'N')) printf("v");
                else if ((str[i]== 'o' || str[i]== 'O')) printf("u");
                else if ((str[i]== 'p' || str[i]== 'P')) printf("i");
                else if ((str[i]== 'q' || str[i]== 'Q')) printf("q");

                else if ((str[i]== 'r' || str[i]== 'R')) printf("w");
                else if ((str[i]== 's' || str[i]== 'S')) printf("s");
                else if ((str[i]== 't' || str[i]== 'T')) printf("e");
                else if ((str[i]== 'u' || str[i]== 'U')) printf("t");
                else if ((str[i]== 'v' || str[i]== 'V')) printf("x");
                else if ((str[i]== 'w' || str[i]== 'W')) printf("w");
                else if ((str[i]== 'x' || str[i]== 'X')) printf("x");
                else if ((str[i]== 'y' || str[i]== 'Y')) printf("r");
                else if ((str[i]== 'z' || str[i]== 'Z')) printf("z");
            }
            else if (str[i]==48) printf("8");
            else if (str[i]==49) printf("1");
            else if (str[i]>49 && str[i]<58) printf("%c",str[i]-2);
            else if (str[i]== ',') printf("n");
            else if (str[i]== ';') printf("k");
            else if (str[i]== '[') printf("o");
            else if (str[i]== '-') printf("9");
            else if (str[i]== '=') printf("0");
            else if (str[i]== ']') printf("p");
            else if (str[i]== '.') printf("m");
            else if (str[i]== '/') printf(",");
            else if (str[i]== 92) printf("-"); //\//
            else if (str[i]== 39) printf("l"); //'
            else printf("%c",str[i]);
        }
        printf("\n");
    return 0;
}
