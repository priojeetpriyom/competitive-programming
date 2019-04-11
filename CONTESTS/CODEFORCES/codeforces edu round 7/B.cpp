#include <bits/stdc++.h>

using namespace std;
//int ara[100001];
//long long a,b,c,d,e,f;

int main()
{
    //a=0,b=1,c=2,d=3,e=4,f=5;
    int hour,minute,m;
    char c;
    while(scanf("%d \n%c %d %d",&hour, &c, &minute, &m)==4)
    {
        minute+=m;
        hour+= minute/60;
        minute= minute%60;
        hour= hour %24;
        if(hour<10)
            printf("0");
        printf("%d:",hour);
        if(minute<10)
            printf("0");
        printf("%d\n",minute);
    }
    return 0;
}
