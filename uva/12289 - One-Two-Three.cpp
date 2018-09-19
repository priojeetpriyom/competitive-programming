#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main() {
    short l,t;
    char str[10];
    scanf("%d",&t);
    while (t--) {
        scanf("%s",str);
        l=strlen(str);
        if(l==5) printf("3\n");
        else {
            if(str[0]== 't' && str[1]=='w') printf("2\n");
            else if(str[0]== 't' && str[2]=='o') printf("2\n");
            else if(str[1]== 'w' && str[2]=='o') printf("2\n");
            else if(str[0]== 'o' && str[1]=='n') printf("1\n");
            else if(str[0]== 'o' && str[2]=='e') printf("1\n");
            else  printf("1\n");
        }
    }
    return 0;
}

