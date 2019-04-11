#include <bits/stdc++.h>
using namespace std;

int ara[100011];
int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int n,k;

    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++) {
        scanf("%d",&ara[i]);
    }

    for(int i=1; i<k ;i++) {
            k-=i;
//            printf("%d\n",k);
    }

    k = max(0, k-1);

    printf("%d\n",ara[k]);


    return 0;
}
