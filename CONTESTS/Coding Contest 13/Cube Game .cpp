#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
//    freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    int n;
    int r,b,s,g;
    while(scanf("%d", &n)==1) {
        int mx = INT_MIN;

        for(int i=1; i<=n; i++) {
            cin>>b>>s>>g>>r;
            int score = (b + (s*3) + (g*10) + (r * (-5)));
            mx = max(mx, score);
            printf("Player %d: %d\n", i, max(0, score));
        }
        printf("High Score = %d\n", mx);


    }

    return 0;


}



