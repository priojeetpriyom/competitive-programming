#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int t,j=0;
    float term1,term2,finall,attendance,ct1,ct2,ct3,ct,total;
    scanf("%d",&t);
    while(t--) {
        scanf("%f %f %f %f %f %f %f",&term1,&term2,&finall,&attendance,&ct1,&ct2,&ct3);
        if (ct1>ct3 && ct2>ct3) ct = (ct1+ct2)/2;
        else if (ct1>ct2 && ct3>ct2) ct = (ct1+ct3)/2;
        else ct = (ct2+ct3)/2;
        total=term1+term2+finall+attendance+ct;
        printf("Case %d: ",++j);
        if (total>=90) printf("A\n");
        else if (total>=80) printf("B\n");
        else if (total>=70) printf("C\n");
        else if (total>=60) printf("D\n");
        else printf("F\n");
    }
    return 0;
}

