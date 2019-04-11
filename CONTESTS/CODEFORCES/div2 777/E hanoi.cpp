#include <bits/stdc++.h>

using namespace std;
int n, dp[100100], height[100100], inner[100100], outer[100100];

long long rec(int pos, int prev) {

    if(pos == n)
        return 0;

    if(outer[pos] > )
}


int main()
{
//   freopen("out.txt", "w", stdout);

   cin>>n;

   for(int i=0; i<n; i++)
    scanf("%d %d %d",&inner[i], &outer[i], &height[i]);

   printf("%I64d\n", rec(0, INT_MAX, INT_MAX));


    return 0;
}
