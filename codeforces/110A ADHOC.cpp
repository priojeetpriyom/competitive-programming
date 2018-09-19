#include <bits/stdc++.h>
using namespace std;

bool isLucky(int n)
{
    if(n==0)
        return false;
    while(n>0)
        {
            if(n%10 != 4 && n%10 != 7)
                return false;
            n/=10;
        }
    return true;
}
int main()
{
    long long n;
    while(scanf("%I64d",&n)==1)
    {
        int temp=0;
        while(n>0)
        {
            if(n%10== 4 || n%10 == 7)
                temp++;
            n/=10;
        }
        //printf("temp %d\n",temp);
        if(isLucky(temp))
            printf("YES\n");
        else
                printf("NO\n");
    }
    return 0;
}
