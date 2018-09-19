/*
    algo:
    idea:

*/
//
//
//#include<stdio.h>
//#include<string.h>

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 505

int n, tc;
double dp[MX][MX][5];


double rec(int r, int b, int turn) {
    if(r==0) {
        return b>0;
    }
    if(b==0) {
        return 0;
    }
//    cout<<"R "<<r<<" B "<<b<<endl;
    double &ret = dp[r][b][turn];

    if(ret != -1) {
        return  ret;
    }
    ret=0;

    if(!turn) {
        if(r)
            ret += rec(r-1,b, turn^1)* ((double)r/(r+b));
        if(b)
            ret+= rec(r, b-1, turn^1) * ((double)b/(r+b));
        return ret;
    }

    if(b) {
        ret = rec(r, b-1, turn^1);
    }


    return ret;

}


int main()
{
//freopen("output.txt", "w", stdout);

  int t;

  scanf("%d", &t);
//      memset(dp, -1, sizeof dp);
    int x, y;
    for(int i=0; i<=500; i++) {
        for(int j=0; j<=500; j++) {
            dp[i][j][0]= dp[i][j][1]= -1;
        }
    }
  for(tc=1; tc<=t; tc++)
  {
      scanf("%d %d",&x, &y);
      printf("Case %d: %.10lf\n", tc, rec(x, y, 0));


  }


    return 0;
}
