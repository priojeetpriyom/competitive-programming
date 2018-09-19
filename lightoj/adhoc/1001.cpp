#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("myOutput.txt","w",stdout);
    int tCase,a;
    scanf("%d",&tCase);
    tCase++;
    for(int i =1;i<tCase;i++)
    {
        scanf("%d",&a);
        if(a>10)
            printf("%d 10\n",a-10);
        else
            printf("0 %d\n",a);
    }
    return 0;
}
