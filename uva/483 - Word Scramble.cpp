#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main() {
    int i,j,k,l;
    char str[1000],str1[1001],temp;
    while (gets(str)) {
            i=0,k=0;
        while (i < strlen(str)) {
            while(1) {
                    if (str[i] == 32 || str[i] == '\0') {
                        break;
                    }
                    else {
                        i++;
                    }
            }
            for (l=i-1,j=k;j <(i+k)/2;l--,j++) {
                swap(str[j],str[l]);
            }

            if (str[i] == 32) {
                i++;
            }
            k=i;
        }
            printf("%s\n",str);
    }
    return 0;
}
