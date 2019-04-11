#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,inlove;
    char str[111],c;
    //bool x;
    while(scanf("%d",&n)==1)
    {
        inlove=0;
        for(int i=0;i<n; i++)
        {
           scanf("\n%s %c",str, &str[0]);
           if(str[0]== '1')
                inlove++;
        }
        printf("%d %d\n",inlove, n-inlove);
    }
    return 0;
}
