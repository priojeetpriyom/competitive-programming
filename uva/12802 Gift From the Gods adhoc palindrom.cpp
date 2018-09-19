#include <bits/stdc++.h>
using namespace std;

bool isPalindrom(int n)
{
    char str[10],len=0;
    do
    {
        str[len++] = n%10;
        n/=10;
    }while(n>0);
    for(int i=0; i< len/2; i++)
        if(str[i] != str[len- i])
            return false;
    return true;
}
int main()
{

//    freopen("myInput.txt","r", stdin);
    freopen("myOutput.txt","w",stdout);
    while(1)
    {
        int n;
        scanf("%d",&n);
        printf("yyy%d\n", n*2);

        if(isPalindrom(n))
            break;
    }


    return 0;
}


