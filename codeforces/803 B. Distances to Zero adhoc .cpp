#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int ara[200100], ans[200100];

int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        scanf("%d", &ara[i]);
    int last_zero = -1;
    for(int i=0; i<n; i++) {
        if(!ara[i]) last_zero=i;
        if(last_zero> -1)
        ans[i] = i-last_zero;
        else
            ans[i] = INT_MAX;
//        printf("i %d last %d ans %d\n",i, last_zero, ans[i]);
    }
    last_zero = n;
    for(int i=n-1; i>=0; i--) {
        if(!ara[i]) last_zero=i;
        if(last_zero<n)
        ans[i] = min (ans[i], last_zero-i);
    }

    for(int i=0; i<n; i++)
        printf("%d ", ans[i]); printf("\n");

    return 0;

}

