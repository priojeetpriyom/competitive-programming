#include<algorithm>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int i,n,q,ara[10100],j,k,l=1,querry[10100];
    while (scanf("%d %d",&n,&q)==2) {
        if (n==0&&q==0) break;

        for (i=0;i<n;i++) scanf("%d",&ara[i]);
        for (i=0;i<q;i++) scanf("%d",&querry[i]);
        //for (i=0;i<n;i++) for (j=i+1;j<n;j++) if(ara[i]>ara[j]) swap(ara[i],ara[j]);
        sort(ara,ara+n);

        printf("CASE# %d:\n",l++);
        for (i=0;i<q;i++) {
            k=1;
            for (j=0;j<n;j++) {

                if (ara[j]==querry[i]) {
                    printf("%d found at %d\n",querry[i],j+1);
                    k=0;
                    break;
                }
            }
            if (k==1) printf("%d not found\n",querry[i]);
        }
        }
    return 0;
}

