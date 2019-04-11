#include <bits/stdc++.h>
//#define N 5
//#define ll long long
//int ara[N];
using namespace std;

int main()
{
    long long numberofDrinks,n, a, b, c;
    while(scanf("%I64d %I64d %I64d %I64d",&n, &a, &b, &c)==4)
    {
        numberofDrinks=0;
        if(a<= b-c)
        {
            numberofDrinks= n/a;
            //n%=a;
//            while(n>=b)
//            {
//                numberofDrinks+=(n/b);
//                n= (n%b) + c*(n/b);
//                //n%=b;
//            }
            //printf("I64d\n",a/n);
        }
        else
        {
            long long x,y,z;
            x= b-c;
            y= n-b;
            z= y/x;
            n= y%x + b;
            numberofDrinks+= z;
           // n=b;
            while(n>=b)
            {
                numberofDrinks+=(n/b);
                n= (n%b) + c*(n/b);
                //n%=b;
            }

            //n=b;
//            n= b+
            numberofDrinks+= n/a;
        }
        if(numberofDrinks<0)
            numberofDrinks=0;
        printf("%I64d\n",numberofDrinks);
    }
    return 0;
}
