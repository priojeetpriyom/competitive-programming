#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,n;
    while(scanf("%d",&n)==1) {
        scanf("%d %d",&x,&y);
        int tempx,tempy;
        n--;
        bool samex=true, samey=true;
        while(n--) {
        scanf("%d %d",&tempx,&tempy);
            if(samex || samey) {
                if(tempx != x)
                    samex=false;
                if(tempy!=y)
                    samey=false;
            }
        }
        if(samex || samey)
            printf("YES\n");
        else

            printf("NO\n");
    }
}
