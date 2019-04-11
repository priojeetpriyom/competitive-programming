#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int x1,x2,x3;
    scanf("%d %d %d",&x1, &x2, &x3);
    int avg = ceil((x1+x2+x3)/3);
    int sum = abs(avg-x1) + abs(avg-x2) + abs(avg-x3);
    int sum1 = min(abs(x1-x2)+abs(x1-x3), abs(x1-x2)+abs(x2-x3));
    sum1 = min(sum1, abs(x1-x3)+abs(x2-x3));
    printf("%d\n",min(sum,sum1));
    return 0;
}

