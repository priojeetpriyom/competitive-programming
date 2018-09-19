#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tCase,a,b;
    scanf("%d",&tCase);
    tCase++;
    for(int i =1;i<tCase;i++)
    {
        scanf("%d %d",&a,&b);
        printf("Case %d: %d\n",i,a+b);
    }
    return 0;
}
