#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    scanf("%d",&m);
    if(m>3)
        printf("0\n");
    else if(m==2)
    {
        printf("5\n");
        printf("10 11 12 13 14\n");
    }
    else if(m==3)
    {
        printf("5\n");
        printf("15 16 17 18 19\n");
    }
    else if(m==4)
    {
        printf("5\n");
        printf("20 21 22 23 24\n");
    }
    else
    {
        printf("5\n");
        printf("5 6 7 8 9\n");
    }
    return 0;
}
