#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int n,i,solution,person,sum;
    while (scanf("%d",&n)==1) {
        solution=0;
        while(n--) {
            sum=0;
            for(i=0;i<3;i++) {
            scanf("%d",&person);
            sum+=person;
            }
            if(sum>1) solution++;
        }
        printf("%d\n",solution);
    }
    return 0;

}
