#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int i,j,k,l;
    char str[25];
    bool palindrom,mirror;
    while(scanf("%s",&str) !=EOF) {
        palindrom=false,mirror=false;
        l=strlen(str);
        printf("%s ",str);
        if (l==1) palindrom=true;
        else {
        j=l-1;

        for (i=0;i<j;++i,--j) {

            if(str[i] == str[j]) palindrom=true;
            else {

                palindrom=false;
                break;
            }
        }
        }

        for (i=0,j=l-1;i<=j;i++,j--) {
            if (str[i]== 'A' && str[j] == 'A') mirror=true;
            else if (str[i]== 'E' && str[j] == '3') mirror=true;
            else if (str[i]== '3' && str[j] == 'E') mirror=true;
            else if (str[i]== 'H' && str[j] == 'H') mirror=true;
            else if (str[i]== 'I' && str[j] == 'I') mirror=true;
            else if (str[i]== 'J' && str[j] == 'L') mirror=true;
            else if (str[i]== 'L' && str[j] == 'J') mirror=true;
            else if (str[i]== 'M' && str[j] == 'M') mirror=true;
            else if (str[i]== 'O' && str[j] == 'O') mirror=true;
            else if (str[i]== 'S' && str[j] == '2') mirror=true;
            else if (str[i]== '2' && str[j] == 'S') mirror=true;
            else if (str[i]== 'T' && str[j] == 'T') mirror=true;
            else if (str[i]== 'U' && str[j] == 'U') mirror=true;
            else if (str[i]== 'V' && str[j] == 'V') mirror=true;
            else if (str[i]== 'W' && str[j] == 'W') mirror=true;
            else if (str[i]== 'X' && str[j] == 'X') mirror=true;
            else if (str[i]== 'Y' && str[j] == 'Y') mirror=true;
            else if (str[i]== 'Z' && str[j] == '5') mirror=true;
            else if (str[i]== '5' && str[j] == 'Z') mirror=true;
            else if (str[i]== '1' && str[j] == '1') mirror=true;
            else if (str[i]== '8' && str[j] == '8') mirror=true;
            else {
                mirror=false;
                break;
            }
        }
        if(palindrom==true && mirror==true) printf("-- is a mirrored palindrome.");
        else if (palindrom==false && mirror==false) printf("-- is not a palindrome.");
        else if (palindrom==true) printf("-- is a regular palindrome.");
        else printf("-- is a mirrored string.");
        printf("\n\n");



    }
    return 0;
}
