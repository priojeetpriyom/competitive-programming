#include <bits/stdc++.h>
using namespace std;

char str[100005];
int main()
{
//    freopen("myOutput.txt","w",stdout);

    scanf("\n%s",str);
    int len = strlen(str);
    int r,l,m;

    scanf("%d",&m);
    while(m--)
    {
        scanf("%d %d",&l,&r);
        int x=0,y=0,z=0;
        for(int i=l-1; i<r; i++)
        {
            if(str[i] == 'x')
                x++;
            else if(str[i] == 'y')
                y++;
            else if(str[i] == 'z')
                z++;
        }

        if(r-l<3)
            printf("YES\n");
//           else   if(x>1)
        else if( (x==y && z== x+1) || (y==z && x==y+1) || (x==z && y==x+1) || (x==z && x==y))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
