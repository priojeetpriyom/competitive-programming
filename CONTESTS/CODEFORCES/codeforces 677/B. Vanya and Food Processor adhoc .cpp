#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,h,k;
    scanf("%d %d %d",&n, &h, &k);
    int currentHeight=0, x=0;
    long long cnt=0;
    while(n--)
    {
        //if(x==0)
        scanf("%d", &x);
        if((currentHeight+x) > h)
        {
            int temp=(currentHeight/k);
            cnt += temp;
            currentHeight = (currentHeight- (k*temp));
            if((currentHeight+x) > h)
            {
                cnt++;
                currentHeight=x;
            }
            else
                currentHeight+=x;
        }
        else
            currentHeight+=x;

    }
    cnt+=  (currentHeight/k) + ((currentHeight%k) !=0);

    printf("%I64d\n", cnt);
    return 0;
}

