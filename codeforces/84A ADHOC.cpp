#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    while(scanf("%I64d",&n)==1)
    {
//        n--;
//        n= n*(n+1);
//        n/=2;
        long long v=n,a=n,sum=0;
//        while(p1!= 0 && P2!=0)
//        {
//            if(v%2==0)
//            {
//                a-=(v/2);
//                sum+=v/2;
//                v/=2;
//            }
//            else
//                {
//                    a-=v/2;
//                    sum+=v/2;
//                    v= v/2 +1;
//                }
//            if(a%2==0)
//            {
//                v-= (a/2);
//                sum+= (a/2);
//                a/=2;
//            }
//            else
//            {
//
//            }
//        }
        n=n*3;
        n/=2;
        printf("%I64d\n",n);
    }
    return 0;
}
