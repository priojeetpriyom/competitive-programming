#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



ll ara[100100];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    cin>>n;

    for(int i=0; i<n; i++) {
        scanf("%I64d", &ara[i]);
    }
    ll mx = -(1e11), sum=0, l=0;
    for(int i=0; i<n-1; i++) {
        ara[i] = abs(ara[i] - ara[i+1]);
        mx = max(mx, ara[i]);
//        printf("%d ", ara[i]);
//        if(i&1) ara[i]*= (-1);
    }
//    printf("\n");
    for(int i=0; i<n-1; i++) {

        sum+= (ara[i] * (((i-l)&1)? -1 : 1));
//        printf("i %d sum %I64d\n", i, sum);
        if(sum>mx)
            mx=sum;
        if(sum<0) {
            sum=0;
            l = i;
            i--;
        }
    }

    cout<<mx;

    return 0;
}


