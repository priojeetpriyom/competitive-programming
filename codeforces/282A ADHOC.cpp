#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    char str[10];
    while(scanf("%d",&n)==1)
    {
        int x=0;
        while(n--)
        {
            scanf("\n%s",str);
            if(str[1]== '+')
            {
                //if(n>0)
                //{
                    x++;
                //}
               // else if(str[0]== '+')
                   // x++;
            }
            else
            {
                //
                //
                    x--;
            }
        }
        printf("%d\n",x);
    }
    return 0;
}
