#include <bits/stdc++.h>

using namespace std;
bool isUnlucky(int n, int a[], int b[])
{
    for(int i=0; i<n; i++)
        if(b[i]>=a[i])
            return false;
    return true;
}
int main()
{
    int a[101],b[101];
    char str[202];
    int n;
    while(scanf("%d",&n)==1)
    {
        scanf("\n%s",str);
        //n+=n;
        int i;
        for(i=0;i<n;i++)
            a[i]=str[i]-48;
        for(;i<n+n;i++)
            b[i-n]=str[i]-48;


//        for(i=0;i<n;i++)
//            printf("a %d b %d\n",a[i],b[i]);

        sort(a,a+n);
        sort(b,b+n);
        bool x;
        if(a[n-1]==b[n-1])
            x=false;
        else if(a[n-1]>b[n-1])
            x=isUnlucky(n,a,b);
        else
            x= isUnlucky(n,b,a);
        if(x)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
