#include <bits/stdc++.h>
using namespace std;



int main()
{
//        freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    int ara[11000];
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) {
        scanf("%d", &ara[i]);
    }
//    printf("fsdfsdf");

    int cnt=0;

    for(int i=1; i<=n; i++) {
//        printf("arr %d arri %d\n", ara[i], ara[ara[i]]);
        if(i == ara[ara[i] ] || i == ara[i])
        {
            cnt++;
            ara[i] = -1;
        }
    }
    if(cnt==0) cnt++;
    printf("%d\n",cnt);


    return 0;
}




