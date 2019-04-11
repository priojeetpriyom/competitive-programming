#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,h,x, cnt;
    scanf("%d %d",&n, &h);
    cnt= n;
    while(n--)
    {
        scanf("%d",&x);
        cnt+= (x>h);
    }
    printf("%d\n", cnt);
    return 0;
}
