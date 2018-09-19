#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int t,i,j,l,p[101],n[101];
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&l);
        for (i=0;i<l;i++) scanf("%d",&n[i]);
        for (i=0;i<l;i++) scanf("%d",&p[i]);
        for (i=0;i<l;i++) {
            if (n[i]>0 && n[i]<10) {
            if (n[i] == 1) {
                if (p[i]== 1) printf(".");
                else if (p[i]== 2) printf(",");
                else if (p[i]== 3) printf("?");
                else if (p[i]== 4) printf("%c",34);

            }
            else if (n[i] == 2) {
                if (p[i]== 1) printf("a");
                else if (p[i]== 2) printf("b");
                else if (p[i]== 3) printf("c");

            }
            else if (n[i] == 3) {
                if (p[i]== 1) printf("d");
                else if (p[i]== 2) printf("e");
                else if (p[i]== 3) printf("f");

            }
            else if (n[i] == 4) {
                if (p[i]== 1) printf("g");
                else if (p[i]== 2) printf("h");
                else if (p[i]== 3) printf("i");

            }
            else if (n[i] == 5) {
                if (p[i]== 1) printf("j");
                else if (p[i]== 2) printf("k");
                else if (p[i]== 3) printf("l");

            }
            else if (n[i] == 6) {
                if (p[i]== 1) printf("m");
                else if (p[i]== 2) printf("n");
                else if (p[i]== 3) printf("o");

            }
            else if (n[i] == 7) {
                if (p[i]== 1) printf("p");
                else if (p[i]== 2) printf("q");
                else if (p[i]== 3) printf("r");
                else if (p[i]== 4) printf("s");

            }
            else if (n[i] == 8) {
                if (p[i]== 1) printf("t");
                else if (p[i]== 2) printf("u");
                else if (p[i]== 3) printf("v");

            }
            else if (n[i] == 9) {
                if (p[i]== 1) printf("w");
                else if (p[i]== 2) printf("x");
                else if (p[i]== 3) printf("y");
                else if (p[i]== 4) printf("z");

            }
        }
        else if(n[i] == 0) printf(" ");
//        else if (n[i] == '*') printf("*");
//        else if (n[i] == '#') printf("#");
        }
        printf("\n");

    }
    return 0;
}
