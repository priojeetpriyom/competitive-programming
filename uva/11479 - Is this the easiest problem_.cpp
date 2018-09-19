#include <iostream>
#include <cstdio>

int main ()
{
    long int a,b,c,i=1,t;
    scanf("%d",&t);
    while (i<=t) {
        scanf("%ld %ld %ld",&a,&b,&c);

        if ((a+b<=c) || (b+c<=a) || (a+c<=b)) {
        printf("Case %ld: Invalid\n",i);
        }
        else if (a<=0 || b<=0 || c<=0) printf("Case %ld: Invalid\n",i);
        else   {
            if (a==b && b ==c) printf("Case %ld: Equilateral\n",i);
            else if (a==b || b ==c || c==a) printf("Case %ld: Isosceles\n",i);
            else printf("Case %ld: Scalene\n",i);
        }

        i++;
    }
    return 0;
}

