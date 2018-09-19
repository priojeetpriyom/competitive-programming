#include <iostream>
#include <cstdio>
using namespace std;
int main ()
{
    int n,i,coun,k=0;
    while (1) {
        coun= 0;
        i=2;
        scanf("%d",&n);
        if (n<=0) break;
        else if (n==1) coun=0;
        else {
            while(1) {
            if (i<n) {
            coun++;
            i=i+i;
            }
            else {
                coun++;
                break;
            }
        }
        }
        printf("Case %d: %d\n",++k,coun);
    }
    return 0;
    }

