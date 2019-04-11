#include <bits/stdc++.h>
using namespace std;

void pwGen(long long pw[]) {
    pw[0] =0;
    for(long long i=1; i<310; i++) {
        pw[i] = (i*i) - ((i-1) *(i-1));
    }
}

int main()
{
//        freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);
    long long pw[333];
    pwGen(pw);
    long long arr[333] [333], ara[90100];
    int t, m , n;
    cin>>t;

    for(int tc=1; tc<=t; tc++) {
        int lenAra=0;
        scanf("%d %d", &n, &m);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                scanf("%d", &arr[i][j]);
            }
            sort(arr[i], arr[i]+m);
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ara[lenAra++] = arr[i] [j]+ pw[j+1];
            }
        }

        sort(ara, ara+lenAra);
        long long ans=0;
        for(int i=0; i<n; i++)
            ans+= ara[i];

        printf("Case #%d: %lld\n", tc, ans);
    }

    return 0;
}



