#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int i,j,n,sum,a,b,c;
    while(1) {
        scanf("%d",&n);
        if(n==0) break;
        else {
            sum=0;
            for(i=1;i<n;i++) {
                for(j=i+1;j<=n;j++) {
                            a=i,b=j;
                        while(1) {
                            c=b%a;
                            if(c==0) break;
                            else {
                                b=a;
                                a=c;
                            }
                        }
                        sum=sum+a;
                    }
                        }
            printf("%d\n",sum);
                    }
                    }
    return 0;
}
