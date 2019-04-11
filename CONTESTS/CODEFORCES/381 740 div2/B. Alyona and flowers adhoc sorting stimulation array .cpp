#include <bits/stdc++.h>
using namespace std;
vector<long long> vec;
int ara[110], arr[110];
long long cnt[210];
int main()
{
//    freopen("myOut.txt", "w", stdout);
    int n,m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &ara[i]);
        arr[i] = ara[i];
    }

    for(int i=1; i<n; i++)
        ara[i]+= ara[i-1];
    int l,r;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&l, &r);
        r-=1;
        l-=1;
        if(l<0)
            l=0;
        int temp=0;

        for(int j=l; j<=r; j++)
            temp+= arr[j];

//        if( (ara[r] - ara[l]) >0 )
if(temp>0)
        {
            for(int j=l; j<=r; j++)
                cnt[j]++;
        }
    }

    for(int i=0; i< n; i++)
    {
        cnt[i] = cnt[i] * arr[i];
    }

//    sort(cnt, cnt+101);
    long long sum=0;
    for(int i=0; i<101; i++)
        sum+= cnt[i];
    printf("%I64d\n", sum);
    return 0;
}
