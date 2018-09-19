#include <iostream>
#include <cstdio>
#include <string.h>
int main ()
{
    float l,d,w,weight;
    int t,k=0;
    scanf("%d",&t);
    while(t--) {
        scanf("%f %f %f %f",&l,&w,&d,&weight);
        if(((l <= 56) && (w <= 45) && (d <= 25) )|| (l+w+d <= 125)) {
            if(weight <= 7) {
               printf("1\n");
                k++;
            }
            else printf("0\n");
                        }
        else printf("0\n");

    }
    printf("%d\n",k);
   return 0;
}

