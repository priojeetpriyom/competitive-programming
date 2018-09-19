#include <bits/stdc++.h>
using namespace std;
char str[5] [5];
int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        for(int i=0;i<n; i++)
            scanf("%s", str[i]);
        printf("%d\n",findValidRooks())
    }
    return 0;
}

