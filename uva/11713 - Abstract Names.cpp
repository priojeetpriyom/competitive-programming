#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main() {
    char real[25],mutat[25];
    int i,u,t,j,r,m;
    bool prin;
    scanf("%d",&t);
    while (t--) {
        scanf("%s %s",&real,&mutat);
        r=strlen(real),m=strlen(mutat);
        if(r==m) {
            for(i=0;i<r;i++) {
                if(real[i]!='a' && real[i]!='e' && real[i]!='i' && real[i]!='o' && real[i]!='u' && real[i]!=mutat[i]) {
                    printf("No\n");
                    prin=false;
                    break;

                }
                else prin=true;
            }
            if(prin) printf("Yes\n");
        }
        else printf("No\n");
        memset(real,0,sizeof(real));
        memset(mutat,0,sizeof(mutat));
    }
    return 0;
}
