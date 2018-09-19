#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myOutput.txt","w",stdout);
    //freopen("myInput.txt",") ;;;we
    int n,m,x, cnt=0;
    bool flag= false;
    scanf("%d %d",&n, &m);
    m+=m;
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&x);
            if(x==1)
                flag=true;
            if(j%2 == 0)
            {
                if(flag)
                    cnt++;
                flag=false;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}

