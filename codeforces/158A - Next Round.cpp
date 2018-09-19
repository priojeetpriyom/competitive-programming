#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    int perticipants[51],i,k,n,coun;
    while (scanf("%d %d",&n,&k)==2) {
        coun=0;
        for(i=0;i<n;i++) scanf("%d",&perticipants[i]);
        if (perticipants[k-1]>0 && k>0) k=perticipants[k-1]-1;
        else k=perticipants[k-1];
        for(i=0;i<n;i++)
            if(perticipants[i]>k) coun++;
        printf("%d\n",coun);
    }
    return 0;

}

