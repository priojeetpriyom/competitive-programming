#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pll;
#define MX 1000100

string s;


int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;

    scanf("%d", &t);

    while(t--) {
        int n,r;
        scanf("%d %d", &n, &r);
        int x, low=0, high = 1e9+1;
        bool valid = true;
        for(int i=1; i<=n; i++) {
            scanf("%d", &x);
            if(x>r) {
                if(x>high)
                    valid = false;
                else
                    high = x;
            } else {
                if(x<low)
                    valid = false;
                else
                    low = x;
            }
        }


        if(valid)
            printf("YES\n");
        else
            printf("NO\n");

    }


    return 0;
}

