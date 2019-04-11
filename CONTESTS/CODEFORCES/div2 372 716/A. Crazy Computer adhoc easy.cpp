#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int n,lim,x=0,y=0,cnt=0;
    scanf("%d %d",&n,&lim);
    int z=n;
    while(n--)
    {

        scanf("%d",&x);
        swap(y,x);
        if(y-x>lim)
            cnt=1;
        else
        {
            cnt++;

        }





    }
    printf("%d\n",cnt);

    return 0;
}
