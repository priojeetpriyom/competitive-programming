#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,k,cnt=0;
    scanf("%d %d", &k, &n);
    for(int i=k; ; i+=k) {
        cnt++;
        if((i-n)%10 ==0 || i%10==0)
            break;
    }
    printf("%d\n", cnt);
    return 0;
}

