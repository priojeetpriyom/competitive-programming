#include<bits/stdc++.h>
using namespace std;
int ara[100002];
int main ()
{
//    scanf("%d",&t);
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&ara[i]);
    int cnt=1,mx=1;
    for(int i=1; i<n;i++) {
        if(ara[i]>ara[i-1])
            cnt++;
        else
            cnt=1;
        mx = max(cnt,mx);
    }

    printf("%d\n",mx);
    return 0;
}

