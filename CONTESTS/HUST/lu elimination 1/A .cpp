#include <bits/stdc++.h>
#define N 5
#define ll long long
int ara[N];
using namespace std;

int main()
{
    int p1,p2,m,tCase,current,mx;
    scanf("%d",&tCase);
    while(tCase--)
    {
        scanf("%d",&m);
        current=0,mx=0;
        while(m--)
        {
            scanf("%d %d",&p1, &p2);
            current+=p2-p1;
            if(current>mx)
                mx=current;
        }
        printf("%d\n",mx);
    }
    return 0;
}
