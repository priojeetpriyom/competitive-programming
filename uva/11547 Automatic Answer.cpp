#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
    int n,t,i,j,l;
    scanf("%d",&t);
    for (i = 0; i<t; i++) {
        scanf ("%d",&n);
        n = (((n*63+7492)*5)-498)/10;
        l = n%10;
        if (n>=0) printf("%d\n",l);
        else printf("%d\n",l-l-l);

    }
    return 0;
}
