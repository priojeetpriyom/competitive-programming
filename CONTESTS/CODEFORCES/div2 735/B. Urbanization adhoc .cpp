#include <bits/stdc++.h>
using namespace std;
int ara[100100];
int main()
{
//    freopen("myOut.txt", "w", stdout);
    int n, n1, n2;
    scanf("%d %d %d", &n, &n1, &n2);

    for(int i=0; i<n; i++)
        scanf("%d", &ara[i]);
    if(n1>n2)
        swap(n1, n2);

    sort(ara, ara+n);

    long long sum1=0, sum2=0;

    int i;
    int cnt=0;
    for(i = n-1; i>=0 && cnt<n1; i--) {
        sum1+= ara[i];
        cnt++;
    }
    double avg1 = (double) sum1 / cnt;
    cnt=0;
    for(i; i>=0 && cnt<n2; i--) {
        sum2+= ara[i];
        cnt++;
    }
    double avg2 = (double) sum2 / cnt;
    printf("%.8lf\n", avg1+avg2);
    return 0;
}
