 #include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    int n,sum,temp,root,i,j,root1,coun=1,k;
    while(1) {
        scanf("%d",&n);

        if(n==0) break;
        printf("Case %d: ",coun++);
        if(n==1) {
            printf("1\n");
            continue;
        }
        else if(n==3) {
            printf("2\n");
            continue;
        }
        else if(n>1000 || n<0) {
            printf("0\n");
            continue;
        }

        temp=n;
        //root=sqrt(n)-2;
        while(--temp>0) {
            k=0;
            sum=0;
            root1=sqrt(temp)+1;
//            if(temp&1==1) i=3;
//            else i=2;
            for(i=1;i<root1;i++) {

                if(temp%i==0) {
                    if(i== temp/i) sum+=i;
                    else sum=sum+i+(temp/i);
                //if(temp==6) printf("i %d sum %d\n",i,sum);
            }
            }
            //sum=sum+1+temp;
            //printf("temp %d sum %d\n",temp,sum);
            if(sum==n) {
                printf("%d\n",temp);
                k=1;
                break;
            }

    }
    if(k==0) printf("-1\n");
    }
    return 0;
}
