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
    int ara[111];
    for(int i=1; i<=n; i++)
    {
        cin>>ara[i];
    }



    int i=1;

//    if(!ara[i]) {
    int pre_zero=0, pre_one=0;
    while(!ara[i] && i<=n)
    {
        i++;
        pre_zero++;
    }
//        while(ara[i] && i<=n) {
//            i++;
//            pre_one++;
//        }
//    }
    int ans=n;
    int one=0, zero=0;
//    if(i<=n){

    for( ; i<=n; i++)
    {
        if(ara[i])
            one++;
        else zero++;
    }
//    }

    ans = max(one, zero) + pre_zero;

    cout<<ans<<endl;


    return 0;
}


