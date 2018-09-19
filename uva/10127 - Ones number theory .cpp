#include <bits/stdc++.h>
using namespace std;

bool divisible(char str[], int n, int len)
{
    unsigned long long num=0;
    for(int i=0; i<len; i++)
    {
        num = num*10 + str[i];
        if(num>= n)
            num= num%n;
    }
    if(num==0)
        return true;
    return false;
}

int main()
{
//    freopen("myOutput.txt","w",stdout);
//    //freopen("myInput.txt",") ;;;

    int n;
    while(scanf("%d",&n)==1)
    {
        char str[10000];
        int len=0;
        str[len++] = 1;
        while(!divisible(str,n, len))
        {
            str[len++] = 1;
        }
        printf("%d\n", len);
    }
    return 0;
}


