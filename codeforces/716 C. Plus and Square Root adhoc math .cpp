#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int n;
    scanf("%d",&n);
    n++;
//    ara[1]=1;
//    n+=2;
//    for(int i=2; i<n; i++) {
//        ara[i] = (i*i)*(i-1)*(i-1);
//    }
//    n--;
//    for(int i=1; i<n; i++) {
//        ans[i] = ((i*(i+1)*(i+1))-(i-1));
//    }
    printf("2\n");
    for(unsigned long long i=2; i<n; i++) {
        printf("%I64u\n",((i*(i+1)*(i+1))-(i-1)));
    }

    return 0;
}

