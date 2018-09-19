#include <iostream>
#include <cstdio>
using namespace std;
int main ()
{
    int coun,m,n;
    while (scanf("%d %d",&m,&n) == 2) {
        if (m == 2 & n == 2) printf("%d\n",m+1);
        else {
        coun = (m*n)-1;
        printf("%d\n",coun);
        }
    }
    return 0;
}
