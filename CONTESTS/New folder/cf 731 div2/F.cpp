#include <bits/stdc++.h>
using namespace std;

int ara[210000];
int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", &ara[i]);
    sort(ara, ara+n);
    long long sum=0, cnt;
    for(int i=0; i<1000 && i<n; i++) {
        if(i!= n-1 && ara[i]== ara[i+1])
            continue;
        cnt =ara[i];
        for(int j= i+1; j<n; j++) {
            cnt+= ara[j]/ara[i] * ara[i];
        }
        sum = max(cnt, sum);
    }

    for(int i=n-1; i>n-1000 && i>=0; i--) {
        if(i!=0 && ara[i]!= ara[i-1])
            continue;
        cnt =ara[i];
        for(int j= i-1; j>=0; j--) {
            cnt+= ara[j]/ara[i] * ara[i];
        }
        sum = max(cnt, sum);
    }

    printf("%I64d\n", sum);
    return 0;
}
