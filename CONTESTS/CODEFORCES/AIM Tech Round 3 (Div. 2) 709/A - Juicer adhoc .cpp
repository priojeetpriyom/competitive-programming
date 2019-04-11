#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myOutput.txt","w",stdout);
    int n,b,d;
    scanf("%d %d %d",&n,&b,&d);
    int x,cnt=0;int sum=0;
    for(int i=0; i<n;i++) {
        scanf("%d",&x);

        if(x<=b)
        {
            sum+=x;
            if( sum>d)
            {
                cnt++;
                sum=0;
            }
        }
    }
    printf("%d\n",cnt);

    return 0;
}
