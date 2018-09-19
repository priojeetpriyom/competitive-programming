#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int price[1001], weight[1001], dp[1001] [32];
    int n;

int knapSack(int pos, int left) {
    if(left<0)
        return (-1)* price[pos-1];
    if(pos == n)
        return 0;

    int &ret = dp[pos] [left];
    if(ret!= -1)
        return ret;

    return ret = max(knapSack(pos+1, left-weight[pos])+price[pos], knapSack(pos+1, left) );
}

int main()
{
//    freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    int t;

    cin>>t;

    while(t--) {
        memset(dp, -1, sizeof dp);
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            scanf("%d %d", &price[i], &weight[i]);
        }

        int people;
        scanf("%d", &people);
        int x, sum=0;
        for(int i=0; i<people; i++) {
            scanf("%d", &x);
            sum+= knapSack(0, x);
        }
        printf("%d\n", sum);
    }


    return 0;


}


