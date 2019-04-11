#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOutput.txt","w",stdout);

    int n,m,d,ara[101];
    scanf("%d %d",&n,&d);
    for(int i=0; i<n; i++)
        scanf("%d",&ara[i]);
    sort(ara,ara+n);
//    printf("oka");
    scanf("%d",&m);
    int sum=0;
    int x = min(m,n);

    for(int i=0; i<x; i++)
        sum+=ara[i];
    for(int i = x; i<m; i++)
        sum-=d;

    printf("%d\n",sum);

    return 0;
}
