#include <iostream>
#include <cstdio>
using namespace std;
int main ()
{
    int fil,emp,n,k,rem;
    while (scanf("%d",&fil)==1) {
        k=0;
        fil=fil+1;
        while(1) {
        if(fil%3==0) {
        k=k+fil;
        fil=fil/3;
        }
        else if (fil>3) {
            emp=fil-fil%3;
            k=k+emp;
            fil=fil%3+emp/3;
        }
        else{
            fil--;
            k=k+fil;
            break;
        }
        }
        printf("%d\n",k);

    }
    return 0;
}
