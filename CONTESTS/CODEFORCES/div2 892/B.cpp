#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100


int ara[1000100];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;


    scanf("%d", &n);


    for(int i=1; i<=n; i++)
        scanf("%d", &ara[i]);

    ll power=0;
    int cnt=0;
    for(int i=n; i>0; i--)
    {
//        printf("%lld ", power);
        if(power)
        {
//            power+= ara[i];
            power--;
//            ara[i] = -1;
        }
        else
        {
            cnt++;
        }
            power= max((ll)ara[i], power);

    }


    printf("%d\n", cnt);





    return 0;
}


