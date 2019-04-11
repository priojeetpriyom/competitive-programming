#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main ()
{
    char f1[1050],f2[1050],sum[1050];
    int n=5000,slen,l;
   // while(scanf("%d",&n)==1)
    {
        if(n==0)
        {
            printf("The Fibonacci number for 0 is 0\n");
     //       continue;
        }
        else if (n==1)
        {
            printf("The Fibonacci number for 1 is 1\n");
    //        continue;
        }
        else
        {
            //int carry;
            l=n;
            int len=1;
            n-=1;
            for(int i=0; i<1050; i++)
            {
                f1[i]=0;
                f2[i]=0;
                sum[i]=0;
            }
            f1[0]=0;
            f2[0]=1;
            while(n-->0)
            {
                bool carry=0;
                for(int i=0; i<len; i++)
                {
                    int temp = f1[i]+f2[i];
                    if(temp<9)
                    {
                        sum[i]= temp+carry;
                        carry=0;
                    }
                    else if(temp>9)
                    {
                        sum[i] = temp-10+carry;
                        carry=1;
                    }
                    else
                    {
                        if(carry==1)
                        {
                            sum[i]=0;
                        }
                        else
                        {
                            sum[i]=temp;
                            carry=0;
                        }
                    }
                }
                slen=len;
                if(carry==1)
                {
                    sum[slen]=1;
                    slen++;
                }
                for(int i=0; i<len; i++)
                    f1[i]=f2[i];
                for(int i=0; i<slen; i++)
                    f2[i]= sum[i];
                len=slen;
            }
        }
        slen;
        printf("The Fibonacci number for %d is ",l);
        while(slen--)
            printf("%d",sum[slen]);
        printf("\n");
    }
    return 0;
}
