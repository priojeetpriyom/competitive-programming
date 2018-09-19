#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    long int s,d,sum;
    while (scanf("%ld %ld",&s,&d) == 2) {
        sum=0;
        while(s<=d) {
            sum= sum + s;
            if(sum >= d) {
                printf("%ld\n",s);
                break;
            }
            s++;
        }
    }
    return 0;
}
