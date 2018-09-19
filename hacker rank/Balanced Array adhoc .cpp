#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin>>n;
    int ara[102];
    ara[0]=0;
    for(int i=1; i<=n; i++) {
        cin>>ara[i];
        ara[i]+= ara[i-1];
//        printf("%d ", ara[i]);
    }
//    printf("\n");

    cout<<abs(ara[n/2] +ara[n/2] - ara[n] )<<endl;

    return 0;
}





